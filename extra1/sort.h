#ifndef SORT_H
#define SORT_H

int ascending (int a, int b) {return a - b;}

int descending(int a, int b) {return b - a;}

void bubbleSort(int *list, int n, int (*compar)(int , int) = ascending);
void insertionSort(int *list, int n, int (*compar)(int , int) = ascending);
void quickSort(int *list, int n, int (*compar)(int , int) = ascending);
void selectionSort(int *list, int n, int (*compar)(int , int) = ascending);

#endif
