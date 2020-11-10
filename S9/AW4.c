/*  Reading Integer File
	Steven Rubio
	10/11/2020
*/

#include<stdio.h>
#include<stdlib.h>

/*The print array function modified to 
	write in the output file*/
void print_array(int NUM, int data[], FILE *fp){
	int i;
	for( i=0;i<NUM;i++)
		fprintf(fp,"%d\t", data[i]);
	fprintf(fp,"\n");
}

//Function to calculate the max value of an array
int max_array(int NUM, int data[]){
	int i, max =0;
	for(i=0;i<NUM;i++){
		if(data[i]>max) max =data[i];
	}
	return max;
}

//File process function
void file_process(FILE *ifp){
	
	int d; 
	rewind(ifp);
	
	//Scanning the file
	fscanf (ifp, "%d", &d);
	
	//Creating an array and storing the length
	int values[d];
	int NUM = d;
	int i;
	double avg =0.0;
	//Saving the data in the array
	for(i=0;!feof (ifp);i++){
		fscanf (ifp, "%d", &d);
		values[i]=d;
		avg += (d-avg)/(i+1.0);	//Computing average on the go
	}
	//Creating output file
	FILE *ofp;
	ofp  = fopen ("answer-hw3.txt", "w");
	//Writing a report on the file
	fprintf(ofp,"The length of the array is: %d\n",NUM);
	fprintf(ofp,"Array values: \n");
	print_array(NUM,values,ofp);
	fprintf(ofp,"Average: %lf",avg);
	fprintf(ofp,"\nMax: %d", max_array(NUM,values));
	//Closing file
	fclose (ofp);
}

int main(int argc, char *argv[]){
	FILE *ifp;
	//Ensuring we have an input file
	if(argc !=2){
		printf("Input file needed");
		exit(1);
	}
	//Open, process and closing the file
	ifp = fopen(argv[1], "r+");
	file_process(ifp);
	fclose(ifp);
	
}