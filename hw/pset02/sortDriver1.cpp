/*
On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
Signed: Lee Yeeun Section: 02 Student Number: 21800546
*/


/*
* Lecture Note by idebtor@gmail.com
*
* This program is written to run the sort algorithms.
* It takes the number of data samples to sort from the user.
* Then, the int array is created and filled with random numbers.
* User may selection one of sort functions to be used. Then
* execution time and its output is displayed.
*
* History:
* 02/10/19:		Created in C++
*
* Before Compilation, you must have some files (static library and
* include file) ready as shown below:
*   src/selection.cpp, bubble.cpp ...
*   include/nowic.h
*	lib/libnowic.a        (nowic.lib for Visual Studio)
* Compilation:
*	g++ selection.cpp insertion.cpp quicksort.cpp bubble.cpp
*       sortDriver.cpp -I../include -L../lib -lnowic -o sort
*/

#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <iomanip>
#include "nowic.h"

using namespace std;

void bubbleSort(int *list, int n);
void insertionSort(int *list, int n);
void quickSort(int *list, int n);
void selectionSort(int *list, int n);

void printList(int *list, int n, int max_print, int per_line);
void randomize(int list[], int n);

// Randomize: shuffle the sequence
// For every sample, starting from the first element in the list,
// it is swapped with the element randomly selected by the index
// generated by a 'real' (not pseudo) random number out of from
// 0 to N - 1.
// Hint: Refer to rand() and srand() function document.
void randomize(int list[], int n) {
	DPRINT(cout << ">randomize...N=" << n << endl;)
	int a,b;
	srand((unsigned)time(NULL));

	for(int i=0;i<n;i++){
		a=list[i];
		list[i]=list[b=rand()%n];
		list[b]=a;

	}
	//cout << "your code here\n";

	DPRINT(cout << "<randomize" << endl;)
}

// When we have a long list, we want to print some in the front
// part of the list and some in the rear part of the list.
//
// The max+print specifies the number of samples in either front
// or rear part of the list.  The per_line determines how many
// samples prints per line.
//
// If max_print is larger than or equal to the sample size N,
// prints max_print/2 samples only.
// For example:
// Case 1) N = 12, max_print = 100, per_line = 20
//		0	1	2	3	4	5
//		6	7	8	9  10  11
// Case 2) N = 12, max_print = 100, per_line = 4
//		0	1	2	3
//		4	5
//		6	7	8	9
//	   10  11
// Case 3) N = 12, max_print = 4, per_line = 6
//		0	1	2	3
//		8	9  10  11
// There should be a line feed between the front part and
// the rear part.
// Observe the sample runs using sortx.exe provided with you.

// Optionally, you may have this kind of a help function.
// void _printList(int *list, int start, int end, int per_line)

void printList(int *list, int N, int max_print, int per_line) {
	DPRINT(cout << ">printList...N=" << N << " max_print=" << max_print << endl;)
	if(max_print>N/2){
		for(int i=0;i<N/2;i++){
			if((i!=0)&&i%per_line==0){
				cout << "\n";
				}
			cout << "\t" << list[i];
			}
			cout << "\n\n";


		for(int i=0;i<N/2;i++){
			if((i!=0)&&i%per_line==0){
				cout << "\n";
				}
			cout << "\t" << list[N/2+i];
			}
	} else{

		for(int i=0;i<max_print;i++){
			if((i!=0)&&i%per_line==0){
				cout << "\n";
				}
			cout << "\t" << list[i];
			}
			cout << "\n\n";


		for(int i=0;i<max_print;i++){
			if((i!=0)&&i%per_line==0){
				cout << "\n";
				}
			cout << "\t" << list[N-max_print+i];
			}
		}

		// your code here
		// Optionally, you may create a help function such as _printList()/

		//cout << "your code here\n";

	DPRINT(cout << "<printList" << endl;)
}

// sortDriver to test sort functions or algorithms.
int main(int argc, char *argv[]) {
	int N = 0;						// default sample size
	int keyin;
	int *list = NULL;				// input and output buffer
	int max_print = 10;				// default max_print(=front_part+last_part)
	int per_line = max_print / 2;	// default samples per line to print
	clock_t start, end;
	char randomized = 'N';
	char option_char;
	char option_str[512];
	char algorithm_list[4][20] = {"Bubble", "Insertion", "Quicksort", "Selection"};
	enum algorithm_enum { BUBBLE, INSERTION, QUICKSORT, SELECTION };
	int  algorithm_chosen = SELECTION;  // default algorithm chosen
	//list = new int[N];

	DPRINT(cout << ">main...N=" << N << endl;)

	// Use setvbuf() to prevent the output from buffered on console.
	setvbuf(stdout, NULL, _IONBF, 0);
	srand(time(NULL));

	do {
		sprintf(option_str, "[sort=%s N=%d randomized=%c max_print=%d per_line=%d]",
			algorithm_list[algorithm_chosen], N, randomized, max_print, per_line);
		cout << "\n\tOPTIONS: " << option_str << "\n"
			"\tn - number of samples size and initialize\n"
			"\tr - randomize(shuffle) samples\n"
			"\ta - algorithm to run\n"
			"\ts - sort()\n"
			"\tm - max samples to display at front or rear\n"
			"\td - max samples to display per line\n";


		option_char = GetChar("\tCommand(q to quit): ");
		DPRINT(cout << "option_char = " << option_char << endl;)

		switch (option_char) {
		case 'a': DPRINT(cout << "case = " << option_char << endl;)

			switch (GetChar("\tEnter b for bubble, i for insertion, s for selection, q for quick sort: ")) {
				case 'b': algorithm_chosen=BUBBLE;
					break;
				case 'i': algorithm_chosen=INSERTION;
					break;
				case 's': algorithm_chosen=SELECTION;
					break;
				case 'q': algorithm_chosen=QUICKSORT;
					break;

			// your code here

			default: { cout << "\tNo such an algorithm available. Try it again.\n"; break; }
			}

			//////////////
			break;

		case 'n': DPRINT(cout << "case = " << option_char;)

			keyin = GetInt("\tEnter input sample size: ");
			if (keyin < 1) {
				cout << "\tExpecting a number larger than 0";
				break;
			}

			N=keyin; // set N with the new keyin value
			if(list!=nullptr){
				delete[] list;//이거맞냐ㅎㅎ 아래돟ㅎㅎ
			}// before allocating the new list, free the old list if not NULL
			list = new (nothrow) int[N]; // allocate memory for new data samples
			assert(list!=nullptr);
			for(int i=0;i<N;i++){// Fill the list with numbers from 0 to n - 1.
				list[i]=i;
			}
			//cout << "your code here\n";
			printList(list, N, max_print, per_line);
			//assert(ptr!=nullptr);
			break;

		case 'r': DPRINT(cout << "case = " << option_char << endl;)
			if (N <= 1) {
				cout << "\tSet sample size first or larger\n";
				break;
			}
			randomize(list, N);
			//cout << "your code here\n";

			break;

		case 's': DPRINT(cout << "case = " << option_char << endl;)
			if (N <= 0) {
				cout << "\tSet sample size first\n";
				break;
			}
			cout << "\tThe clock ticks and " << algorithm_list[algorithm_chosen] << " begins...\n";
			start = clock();
			switch (algorithm_chosen) {
				case BUBBLE: bubbleSort(list,N);
					break;
				case INSERTION: insertionSort(list,N);
					break;
				case SELECTION: selectionSort(list,N);
					break;
				case QUICKSORT: quickSort(list,N);
					break;//얘네 다 날리고 sorfFn() 이런식으로 호출할수있게 하는고얌(드라이브2가.)
			}
			//printList(list, N, max_print, per_line);
			//cout << "your code here\n";

			end = clock();
			cout << "\tDuration: " << (end - start) / (double)CLOCKS_PER_SEC << " seconds\n";
			break;

		case 'm': DPRINT(cout << "case = " << option_char << endl;)
			max_print=GetInt();
			printList(list, N, max_print, per_line);
			//cout << "your code here\n";

			break;
		case 'd': DPRINT(cout << "case = " << option_char << endl;)

			//cout << "your code here\n";
			per_line= GetInt();
			printList(list, N, max_print, per_line);

			break;
		default:
			break;
		}
	} while (option_char != 'q');

	if (list != NULL) free(list);
	// system("pause");
	DPRINT(cout << ">main" << endl;)
	return EXIT_SUCCESS;
}