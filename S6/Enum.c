/*  Enums
	Steven Rubio
	14/10/2020
*/

#include<stdio.h>

enum dia { dom, lun, mar, mie, jue, vie, sab}; //Declaracion
//typedef enum dia dia; 
//Asocia las palabras para poder usar solo dia d por ejemplo

void print_day(enum dia d){
	switch(d){
	case dom:	printf("Domingo");		break;	
	case lun:	printf("Lunes");		break;	
	case mar:	printf("Martes");		break;	
	case mie:	printf("Miercoles");	break;
	case jue:	printf("Jueves");		break;
	case vie:	printf("Viernes");		break;
	case sab:	printf("Sabado");		break;
	default:	printf("%d es un error",d);
	}
}

enum dia dia_sig(enum dia d){
	switch(d){
	case sab:	return dom;	break;		
	case dom:	return lun;	break;
	case lun:	return mar;	break;
	case mar:	return mie;	break;
	case mie:	return jue;	break;
	case jue:	return vie;	break;
	case vie:	return sab;	break;
	default:	return lun; 
	}	
}

int main(){
	
	enum dia hoy = vie;
	print_day(hoy);
	printf("\n\n");
	//print_day(7);
	printf("\n\n");
	print_day(dia_sig(hoy));
	printf("\n\n");
	return 0;
}