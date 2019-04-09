/*
On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
Signed: Yeeun Section: 02 Student Number: 21800546
*/


// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
/*
* This brute force version of Selection Sort that takes O(n^2).
*
*  Lab - Using C++, rewrite lab02a.cpp and name the file as lab03.cpp.
*		- <iostream>, <cstdlib>, <cmath>, <cassert>
*		- using namespace std
*		- cin, cout, endl
*		- use new and delete operators instead of malloc() and free()
*/
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include <cassert>
#include <string>
#include <iomanip>
#include "nowic.h"
#include "sort.h"

using namespace std;

void (*sortFn[])(int *, int, int(*)(int,int))={bubbleSort,insertionSort,quickSort,selectionSort};//추가

void print_list(int *list, int n) {
	for (int i = 0; i < n; i++)
		cout << list[i] << " ";
	cout << endl;
}

#if 1
int main(int argc, char *argv[]) {
	clock_t start, end;
	int keyin;
	int N;
	//for(int i=0;i<argc;i++)

	/*
	int list[] = { 3, 4, 1, 7, 9, 6, 5, 2, 8, 0 };
	const int N = sizeof(list) / sizeof(list[0]);
	*/
	if(argc==1){
		keyin = GetInt("Enter input sample size: ");
		N = keyin;
	} else {
		N=std::stoi(argv[1]);
	}

	// int *list = (int *)malloc(N * sizeof(int));
	int *list = new (nothrow) int[N];
	assert(list != NULL);

	cout << "Test Case : NOT passing a default argument : quickSort(list,n)"<<endl;
	cout<<"---------------------------------------------------------------";

	for (int j = 0; j < N; j++)
		list[j] = rand() % N;

	cout << endl << "NOTsorted[quick]: ";
	print_list(list, N);
	cout << "   sorted[quick]: ";
	quickSort(list,N);
	print_list(list, N);
	cout << endl;
	cout << "Test Case : Passing a function pointers : quickSort(list,n,up)"<<endl;
	cout<<"---------------------------------------------------------------";

	for (int j = 0; j < N; j++)
		list[j] = rand() % N;

	cout << endl << "NOTsorted[quick]: ";
	print_list(list, N);
	cout << "   sorted[quick]: ";
	quickSort(list,N,ascending);
	print_list(list, N);
	cout << endl;
	cout << "Test Case : Passing a function pointers : quickSort(list,n,dn)"<<endl;
	cout<<"---------------------------------------------------------------";

	for (int j = 0; j < N; j++)
		list[j] = rand() % N;

	cout << endl << "NOTsorted[quick]: ";
	print_list(list, N);
	cout << "   sorted[quick]: ";
	quickSort(list,N,descending);
	print_list(list, N);
	cout << endl;




/*
	for (int j = 0; j < N; j++)
		list[j] = rand() % N;
		*/
		const int size = sizeof(sortFn)/sizeof(sortFn[0]);

		string pick[]={"Bubble", "Insert", "Quick", "Select"};
		cout << "Test Case : Using an arrat of function pointers"<<endl;
		cout<<"------------------------------------------------";


		for(int i =0; i < size; i++){

			for (int j = 0; j < N; j++)
				list[j] = rand() % N;
/*
			switch (i) {
				case 0 : cout << "bubbleSort"; break;
				case 1 : cout << "insertionSort"; break;
				case 2 : cout << "quickSort"; break;
				case 3 : cout << "selectionSort"; break;
			}
*/

			for (int j = 0; j < N; j++)
				list[j] = rand() % N;
			cout << endl << "NOTsorted["<< pick[i] <<"]: ";
			print_list(list, N);
			//cout << endl;

			//start = clock();
			sortFn[i](list, N, ascending);
			//end = clock();


			cout << "UP sorted["<< pick[i] <<"]: ";
			print_list(list, N);
			//cout << endl;

			//start = clock();
			sortFn[i](list, N, descending);
			//end = clock();


			cout << "DN sorted["<< pick[i] <<"]: ";
			print_list(list, N);


			//cout << "Duration: " << (end - start) / (double)CLOCKS_PER_SEC << " seconds\n";

		}
	delete[] list;
	cout << "Happy Coding~~\n";
}
#endif
