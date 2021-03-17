#include <stdio.h>

int main ()
{
	_Bool a = 0;
	signed char b = -10;
	unsigned char c;
	short i = 0;
	//unsigned short 
	int z = 2147456;
	long int g = -323456789;
	unsigned long f = 54687921;
	long long h = -546875138798;
   	float m = 121545487868498;
	double n;


	c = i;
	printf ("le unsigned char est reste un unsigned char %u\n", c);
	
/*
	z = m + f;
	printf("le float est reste un float %f\n", m);
	printf("le unsigned long est reste un unsigned long %lu\n", f);
	printf("le resultat%d\n", z);
	printf("%lu\n", sizeof(m));
	printf("%lu\n", sizeof(f));
	printf("%lu\n", sizeof(z));


	->> quand on met une variable a gauche de l egalite qui ets plus petit que les variables a droite de l egalite, le resultat devient n importe quoi. 
	-> chaque fois qu on caste, le compilateur le caste implicitement , mais la variable garde son type
*/
/*	printf("le unsigned char est reste un unsigned char  %c\n", c);
	printf("le signed signed char est reste un signed char  %c\n", b);
	printf("le resultat %f\n", n);
	printf("%lu\n", sizeof(b));
	printf("%lu\n", sizeof(c));
	printf("%lu\n", sizeof(n));*/


}


//tu ne peux pas mettre dans un char, un int,ah peut etre que tu peux mettre dans un 
//unsigned char un int compris entre 0 et 250 ?? a tester
//
//pour %c  c est unsigned char =  va_arg(args, int) 
