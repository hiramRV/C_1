/*  Double Space File
	Steven Rubio
	10/11/2020
*/

#include<stdio.h>
#include<stdlib.h>

//Funcion para imprimir el contenido de un archivo
void print_file(FILE *fptr){
	int c;
	rewind(fptr);					//Esta funcion nos lleva al inicio del archivo
	while((c=getc(fptr)) != EOF) 	//Revisamos que no estamos al final del archivo
		putc(c, stdout);
}


void double_space(FILE *ifp, FILE *ofp){
	int c;
	rewind(ifp);					//Esta funcion nos lleva al inicio del archivo
	while((c=getc(ifp)) != EOF){	//Revisamos que no estamos al final del archivo
		putc(c, ofp);
		if(c == '\n'){				//Uso '' ya que estos denotan un caracter
			putc('\n',ofp);	
			putc('/',ofp);
			putc('\\',ofp);
			putc('\n',ofp);
		}			
	}
}


int main(int argc, char *argv[]){
	FILE *ifp, *ofp;
	//Nos aseguramos de tener 2 archivos de entrada
	if(argc !=3){
		printf("Se necesitan archivos de entrada y salida");
		exit(1);
	}
	//Se abre cada archivo con los permisos deseados
	ifp = fopen(argv[1], "r+");
	ofp = fopen(argv[2], "w+");
	printf("Mi archivo de entrada es: %s \n\n", argv[1]);
	print_file(ifp);
	double_space(ifp, ofp);
	printf("\n\nMi archivo de salida es: %s \n\n", argv[2]);
	print_file(ofp);
	printf("\n\n");
	//Se cierran los archivos como buena práctica
	fclose(ifp);
	fclose(ofp);
}