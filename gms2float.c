// Programm zum Umrechnen von Grad, Bogenminuten und Bogensekunden in Dezimalgrad
// Autor: Fabian Prestros
// Datum: 05.01.2021
#include <stdio.h>
#include <math.h>

double einlesen(char koef[8])
{
	int chk = 0;
	double zahl = 0;

	do													// In einer Schleife einlesen, bis eine korrekte Zahl eingelesen wurde
	{
		printf("%s = ", koef);
		chk = scanf_s("%lf", &zahl);
		while (getchar() != '\n');						// Tastaturpuffer leeren.
		if (chk == 0)									// Fehlermeldung, wenn scanf_s meldet, dass keine Ganze Zahl eingegeben wurde
			printf("Bite geben Sie eine Zahl ein!\n");
	} while (chk == 0);									// Schleifendurchlauf, bis kein Fehler mehr vorliegt.

	return zahl;
}

double umrechnen(double ergebnis[3])
{
	double grad = 0;

	grad = ergebnis[0] + ergebnis[1] / 60 + ergebnis[2] / 3600;
	return grad;
}

int main()
{
	double grad = 0;
	double ergebnis[3] = { 0 };

	ergebnis[0] = einlesen("Grad");
	ergebnis[1] = einlesen("Minuten");
	ergebnis[2] = einlesen("Sekunden");

	grad = umrechnen(ergebnis);
	printf("%lf\xF8\n", grad);
}