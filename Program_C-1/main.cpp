
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define Liczba_wierszy 4
#define Liczba_kolumn  4

#define INT_MAX 2147483647


void wprowadz_dane(int tab[][Liczba_kolumn])
{
	printf_s("wprowadz_dane\n");

	for (int wiersze = 0; wiersze < Liczba_wierszy; wiersze++)

	{
		for (int kolumny = 0; kolumny < Liczba_kolumn; kolumny++)
		{
			scanf_s("%d", &tab[wiersze][kolumny]);
		}
	}
}

void wprowadz_dane_losowo(int tab[][Liczba_kolumn])
{
	printf_s("wprowadz_dane_losowo\n");
	for (int wiersze = 0; wiersze < Liczba_wierszy; wiersze++)
	{
		for (int kolumny = 0; kolumny < Liczba_kolumn; kolumny++)
		{
			tab[wiersze][kolumny] = (rand() % 100) + 0;
		}
	}
}

void wyswietl_dane(int tab[][Liczba_kolumn])
{
	int temp = 0;
	for (int wiersze = 0; wiersze < Liczba_wierszy; wiersze++)
	{
		for (int kolumny = 0; kolumny < Liczba_kolumn; kolumny++)
		{
			printf_s("%4d", tab[wiersze][kolumny]);
		}
		printf_s("\n");
	}
	printf_s("\n");
}

void wyswietl_dane_posortowane(int tab[])
{
	printf_s("wyswietl_dane_posortowane\n");
}
 
float srednia(int tab[][Liczba_kolumn])
{
	printf_s("srednia\n");
	int srednia = { 0 };
	for (int wiersze = 0; wiersze < Liczba_wierszy; wiersze++)
	{
		for (int kolumny = 0; kolumny < Liczba_kolumn; kolumny++)
		{
			srednia += tab[wiersze][kolumny];
		}
	}
	return (float)((float)srednia / (float)(Liczba_wierszy * Liczba_kolumn));
}

float mediana(int tab[][Liczba_kolumn], int tab_sort[])
{
	printf_s("mediana\n");
	int licznik = 0;
	for (int wiersze = 0; wiersze < Liczba_wierszy; wiersze++)
	{
		for (int kolumny = 0; kolumny < Liczba_kolumn; kolumny++)
		{
			tab_sort[licznik] = tab[wiersze][kolumny];
			++licznik;
		}
	}
	for (int kolumny = 0; kolumny < (Liczba_wierszy * Liczba_kolumn ) - 1; kolumny++)
	{
		if (tab_sort[kolumny] < tab_sort[kolumny + 1])
		{
			int temp = tab_sort[kolumny];
			tab_sort[kolumny] = tab_sort[kolumny + 1];
			tab_sort[kolumny + 1] = temp;
		}
	}
	return tab_sort[Liczba_kolumn * Liczba_wierszy / 2];
}

void zapisz_dane(int tab[][Liczba_kolumn])
{
	printf_s("zapisz_dane\n");
}

void wczytaj_dane(int tab[][Liczba_kolumn])
{
	printf_s("wczytaj_dane\n");
}

void zamien_min_max(int tab[][Liczba_kolumn])
{
	printf_s("zamien_min_max\n");
	int min[3] = { INT_MAX,0,0 };
	int max[3] = { 0,0,0 };
	for (int wiersze = 0; wiersze < Liczba_wierszy; wiersze++)
	{
		for (int kolumny = 0; kolumny < Liczba_kolumn; kolumny++)
		{
			if (tab[wiersze][kolumny] < min[0])
			{
				min[0] = tab[wiersze][kolumny];
				min[1] = wiersze;
				min[2] = kolumny;
			}
			if (tab[wiersze][kolumny] > max[0])
			{
				
				max[0] = tab[wiersze][kolumny];
				max[1] = wiersze;
				max[2] = kolumny;

			}
		}
	}

	tab[max[1]][max[2]] = min[0];
	tab[min[1]][min[2]] = max[0];

}

void menu(void)
{
	printf_s("\n");
	printf_s("1 - wprowadz dane\n");
	printf_s("2 - wyswietl dane\n");
	printf_s("3 - oblicz srednia i mediane\n");
	printf_s("4 - zamien wartosc minimalna z maksymalna\n");
	printf_s("5 - generuj dane losowo\n");
	printf_s("z - zapisz dane do pliku\n");
	printf_s("w - wczytaj dane z pliku\n");
	printf_s("k - koniec programu\n");
	printf_s("\n");
}

int main()
{
	srand(time(NULL));

	int tablica[Liczba_wierszy][Liczba_kolumn] = { 0 };

	int tab_sort_temp[Liczba_wierszy * Liczba_kolumn] = { 0 };

	char opcja = 0;

	while (opcja != 'k')
	{
		menu();

		opcja = _getch();

		switch (opcja)
		{
		case '1':

			wprowadz_dane(tablica);
			break;

		case '2':

			wyswietl_dane(tablica);
			break;

		case '3':

			printf_s("Srednia wartosci znajdujacych sie w tabeli wynosi: %f\n", srednia(tablica));
			printf_s("Mediana wartosci znajdujacych sie w tabeli wynosi: %f\n", mediana(tablica, tab_sort_temp));
			break;

		case '4':

			zamien_min_max(tablica);
			printf_s("Zamieniono wartosc minimalna z maksymalna.\n");
			break;

		case '5':

			wprowadz_dane_losowo(tablica);
			printf_s("Wygenerowano dane losowo.\n");
			break;

		case 'z':

			zapisz_dane(tablica);
			printf_s("Zapisano dane do pliku.\n");
			break;

		case 'w':

			wczytaj_dane(tablica);
			printf_s("Odczytano dane z pliku.\n");
			break;

		case 'k':

			//zakonczenie programu
			break;

		default:

			printf_s("Wybierz wlasciwa opcje.\n\n");
			break;

		}
	}

	return 0;
}