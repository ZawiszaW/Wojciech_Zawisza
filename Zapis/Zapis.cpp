#include <stdio.h>
#include <conio.h>
#include <iostream>

FILE* fptr;

void plus()
{
	int a = 0;
	int b = 0;
	int c = 0;
	printf_s("DODAWANIE:\n");
	printf_s("Podaj A   ");
	scanf_s("%d", &a);
	printf_s("\nPodaj B   ");
	scanf_s("%d", &b);
	c = a + b;
	printf_s("\nWYNIK:\n");
	printf_s("A+B=%d\n", c);
	fprintf(fptr, "DODAWANIE:\n%d + %d = %d\n\n", a, b, c);

}


void minus()
{
	int a = 0;

	int b = 0;

	int c = 0;

	printf_s("ODEJMOWANIE:\n");

	printf_s("Podaj odjemna A   ");

	scanf_s("%d", &a);

	printf_s("\nPodaj odjemnik B   ");

	scanf_s("%d", &b);

	c = a - b;

	printf_s("\nWYNIK:\n");

	printf_s("A-B=%d\n", c);

	fprintf(fptr, "ODEJMOWANIE:\n%d - %d = %d\n\n", a, b, c);

}
void razy()
{
	int a = 0;

	int b = 0;

	int c = 0;

	printf_s("MNOZENIE:\n");

	printf_s("Podaj A   ");

	scanf_s("%d", &a);

	printf_s("\nPodaj B   ");

	scanf_s("%d", &b);

	c = a * b;

	printf_s("\nWYNIK:\n");

	printf_s("AxB=%d\n", c);

	fprintf(fptr, "MNOZENIE:\n%d * %d = %d\n\n", a, b, c);

}
void przez()
{
	float a = 0;

	float b = 0;

	float c = 0;

	printf_s("DZIELENIE:\n");

	printf_s("Podaj dzielna A   ");

	scanf_s("%f", &a);

	printf_s("\nPodaj dzielnik B   ");

	scanf_s("%f", &b);

	c = a / b;

	printf_s("\nWYNIK:\n");

	printf_s("A/B=%.3f\n", c);

	fprintf(fptr, "DZIELENIE:\n%0.0f / %0.0f = %0.5f\n\n", a, b, c);

}

void menu()
{
	printf_s("KALKULATOR\n");
	printf_s("JAKIE DZIALANIE WYKONAC?\n");
	printf_s("1 - DODAJ\n");
	printf_s("2 - ODEJMIJ\n");
	printf_s("3 - POMNOZ\n");
	printf_s("4 - PODZIEL\n");
	printf_s("k - KONIEC\n");
}


int main(void)
{
	fptr = fopen("save.txt", "w");
	if (fptr == 0)
	{
		printf("blad otwarcia pliku\n");
		exit(1);
	}
	setlocale(LC_ALL, "pl_PL");
	char opcja = 0;
	while (opcja != 'k')
	{
		system("cls");
		menu();
		opcja = _getch();
		switch (opcja)
		{
		case '1':
			plus();
			system("pause");
			break;

		case '2':
			minus();
			system("pause");
			break;

		case '3':
			razy();
			system("pause");
			break;

		case '4':
			przez();
			system("pause");
			break;

		case 'k':
			printf_s("KONIEC\n");
			system("pause");
			exit(0);
			break;

			break;


		default:
			printf_s("Co konkretnie chcialbys obliczyc?\n ");
			system("pauza");
			break;
		}
	}

	fclose(fptr);

	return 0;
}