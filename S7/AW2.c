/*  Assigment Using struct
	Steven Rubio
	22/10/2020
*/

#include<stdio.h>
//Definicion de tipo de dato mes
typedef enum mes{ ene, feb, mar, abr, may, jun, jul, ago, sep, oct, nov, dic} mes;
//Definicion de estructura dia 
typedef struct dia{ mes m; int d;} dia;

//Case print para todas las opciones
void print_dia(dia d){
	switch(d.m){
	case ene:	printf("Enero %d\n",d.d);		break;	
	case feb:	printf("Febrero %d\n",d.d);		break;	
	case mar: 	printf("Marzo %d\n",d.d);	 	break;
	case abr: 	printf("Abril %d\n",d.d);		break;
	case may: 	printf("Mayo %d\n",d.d);		break;
	case jun: 	printf("Junio %d\n",d.d);		break;
	case jul: 	printf("Julio %d\n",d.d);		break;
	case ago: 	printf("Agosto %d\n",d.d);		break;
	case sep: 	printf("Septiembre %d\n",d.d);	break;
	case oct: 	printf("Octubre %d\n",d.d);		break;
	case nov: 	printf("Noviembre %d\n",d.d);	break;
	case dic: 	printf("Diciembre %d\n",d.d);	break;
	default:	printf("%d es un error",d);
	}
}

void dia_siguiente(dia *d){
	//Meses con 31 dias
	if(d->m==ene||d->m==mar||d->m==may||d->m==jul|| d->m==ago|| d->m==oct|| d->m==dic){
		if(d->d==31 && d->m==ene) d->m= feb;
		else if(d->d==31 && d->m==mar) d->m= abr;
		else if(d->d==31 && d->m==may) d->m= jun;
		else if(d->d==31 && d->m==jul) d->m= ago;
		else if(d->d==31 && d->m==ago) d->m= sep;
		else if(d->d==31 && d->m==oct) d->m= nov;
		else if(d->d==31 && d->m==dic) d->m= ene;
		d->d = (d->d%31)+1;}
	//Meses con 30 dias
	else if(d->m==abr||d->m==jun||d->m==sep||d->m==nov){
		if(d->d==30 && d->m==abr) d->m= may;
		else if(d->d==30 && d->m==jun) d->m= jul;
		else if(d->d==30 && d->m==sep) d->m= oct;
		else if(d->d==30 && d->m==nov) d->m= dic;
		d->d = (d->d%30)+1;}
	//Febrero, caso unico de 28 dias
	else if(d->m==feb){
		if(d->d==28) d->m= mar;
		d->d = (d->d%28)+1;}
}


int main(){
	//dias solicitados
	printf("\n\nFechas solicitadas: \n");
	printf("------------\n");
	dia D1= {feb,28};
	print_dia(D1);
	dia_siguiente(&D1);
	print_dia(D1);
	printf("------------\n");
	dia D2= {mar,14};
	print_dia(D2);
	dia_siguiente(&D2);
	print_dia(D2);
	printf("------------\n");
	dia D3= {oct,31};
	print_dia(D3);
	dia_siguiente(&D3);
	print_dia(D3);
	printf("------------\n");
	dia D4= {dic,31};
	print_dia(D4);
	dia_siguiente(&D4);
	print_dia(D4);
	return 0;
}