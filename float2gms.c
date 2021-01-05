// Programm zum Umrechnen von Dezimalgrad in Grad, Bogenminuten und Bogensekunden
// Autor: Fabian Prestros
// Datum: 05.01.2021
#include <stdio.h>
#include <math.h>

double einlesen(char koef[4])
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

void umrechnen(double grad, double ergebnis[3])
{
	double minuten = 0;
	ergebnis[0] = trunc(grad);
	minuten = (grad - ergebnis[0]) * 60;
	ergebnis[1] = trunc(minuten);
	ergebnis[2] = (minuten - ergebnis[1]) * 60;
}

int main()
{
	double grad = 0;
	double ergebnis[3] = { 0 };

	grad = einlesen("Grad");

	umrechnen(grad, ergebnis);
	printf("%.0lf\xF8 %.0lf' %lf\"\n", ergebnis[0], ergebnis[1], ergebnis[2]);
}