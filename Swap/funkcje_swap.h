#pragma once
#ifndef __funkcje_swap_H__
#define __funkcje_swap_H__


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define LICZBA_WIERSZY 4
#define LICZBA_KOLUMN  4

#define INT_MAX 2147483648

float mediana(int tab[][LICZBA_KOLUMN], int tab_sort[]);

float srednia(int tab[][LICZBA_KOLUMN]);

void zamien_min_max(int tab[][LICZBA_KOLUMN]);

void swap(int **a, int **b);

void swap_bracket(int a[][LICZBA_WIERSZY], int b[][LICZBA_WIERSZY], int Liczba_elementow_do_zamiany = 1);

void swap_star(int **a, int **b, int Liczba_elementow_do_zamiany = 1);


#endif /* __funkcje_swap_H__*/
