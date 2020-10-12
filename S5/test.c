/*	Computing average of file
	Steven Rubio
	11/10/2020
*/

#include <stdio.h>

//Original code from https://stackoverflow.com/questions/4600797/read-int-values-from-a-text-file-in-c

double read_ints (const char* file_name)
{
  //Opening file 
  FILE* file = fopen (file_name, "r");
  //Variables
  int i = 0, counter = 1;
  double avg =0.0, o_avg;
  //Scaning the file
  fscanf (file, "%d", &i);  

  printf("Element value \t   average \taverage-error(%)\n");
  //Loop while we are not in the end of the file
  while (!feof (file))
    {  
	//Computing average
	o_avg = avg;		//Old value
	avg += (i-avg)/(counter+1.0);
	//Priting Value
	printf ("%d:   \t%d\t %lf    %lf\n",counter,i,avg,100*((avg-o_avg)/avg));
	//Updating counter
	counter++;
    fscanf (file, "%d", &i);      
    }
	
  //Closing file
  fclose (file);   
  return avg;
}

int main () {

   //Calling 
   printf("\n\nThe average weight it's: %lf",read_ints("SE.txt"));

   return(0);
}
