#pragma once
#ifndef __menu_H__
#define __menu_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define LICZBA_WIERSZY 4
#define LICZBA_KOLUMN  4

#define INT_MAX 2147483647

void wprowadz_dane(int tab[][LICZBA_KOLUMN]);
void wprowadz_dane_losowo(int tab[][LICZBA_KOLUMN]);
void wyswietl_dane(int tab[][LICZBA_KOLUMN]);
void wyswietl_dane_posortowane(int tab[]);
void zapisz_dane(int tab[][LICZBA_KOLUMN]);
void wczytaj_dane(int tab[][LICZBA_KOLUMN]);
void menu(void);

#endif /*__menu_H__*/
