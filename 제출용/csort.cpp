// csort.cpp
// This is a sample code that runs okay, has a bad coding style.
// Reference: Fundamentals of Data Structures by Horowitz, Sahni
//
// When you compile the following code in Visual Studio, you may
// get the warning about scanf() or others. Then enter an addtional
// compiler option /wd4996 in the following:
// Project Properties -> C/C++ -> Command Line -> Additonal Options
/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
*/
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <iomanip>
#include "nowic.h"



//#define MAX_SIZE 101

//void SWAP
#define SWAP(x, y, t)  ((t) = (x), (x) = (y), (y) = (t))

void selectionSort(int[], int);

int main(void) {
	int i, n;
	//int list[MAX_SIZE];
	int *list = NULL;
	list = new (std::nothrow) int[n];
	assert(list!=nullptr);
	//std::cout<<"Enter the number of samples: ";
	n=GetInt();
	if (n < 1) {
		fprintf(stderr, "Improper value of n");
		exit(1);
	}

	std::cout<<"\nUnSorted array:\n";
	for (i = 0; i < n; i++) {       // randomly generate numbers
		list[i] = rand() % 1000;
		std::cout<<" "<<list[i];
	}

	selectionSort(list, n);

	printf("\nSorted array:\n");
	for (i = 0; i < n; i++) {
		std::cout<<" "<< list[i];
	}
	printf("\n");

	return 0;
}

void selectionSort(int list[], int n) {
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		SWAP(list[i], list[min], temp);
	}
}
