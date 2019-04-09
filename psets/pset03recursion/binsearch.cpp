/*
On my honour, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
Signed: Lee Yeeun  Section: 02 Student Number: 21800546
*/


 /*
 * This program implements a recurisve binary_search():
 *
 * The binary search algorithm is a method of searching a sorted array for a single
 * element by cutting the array in half with each recursive pass.The trick is to
 * pick a midpoint near the center of the array, compare the data at that point
 * with the data being searched and then responding to one of three possible
 * conditions : the data is found at the midpoint, the data at the midpoint is
 * greater than the data being searched for, or the data at the midpoint is less
 * than the data being searched for.
 * Recursion is used in this algorithm because with each pass a new array is
 * created by cutting the old one in half.The binary search procedure is then
 * called recursively, this time on the new (and smaller) array.
 * Typically, the array's size is adjusted by manipulating a beginning and
 * ending index. The algorithm exhibits a logarithmic order of growth because
 * it essentially divides the problem domain in half with each pass.
 *
 * In this example, you need an extra function at user's convenience since a
 * user may want to simply call the function with three parameters such as
 * binary_search(data, key, size).  Once you get the user's initial call,
 * then you call _binary_search(data, key, low, high) recursively.
 *
 * @author: idebtor@gmail.com
 * 2018/03/08	Creation
 * 2019/02/01	Using cpp
 *
 * int _binary_search(int *list, int key, int lo, int hi)
 * implements a recursive binary search algorithm.
 * INPUT:
 *		*list is a array of integers SORTED in ASCENDING order,
 *		key is the integer to search for, lo is the minimum
 *      array index, hi is the maximum array index
 * OUTPUT:
 *		returns the array index of `key` in the list'
 *		returns -1 or something else?
 * NOTE:
 * If the key is not found, low is the insertion point where a key would be
 * inserted to maintain the order of the list.  It is more useful to return
 * the insertion point than -1.  The method must return a negative value to
 * indicate that the key is not in the list. Can it simply return -low?
 */
#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif


int _binary_search(int *data, int key, int lo, int hi) {
	DPRINT(cout << "key=" << key << " lo=" << lo << " hi=" << hi << endl;);

	int half=(hi+lo)/2;
	//cout <<"lo : "<<lo<<" hi : "<<hi << " half : "<<half<<endl;

	if(key==data[half]){
		//cout << "find key! key : "<<key<<" index : "<<half<<endl;
		return half;
	}  else if(((hi-lo)<=1)){
		//cout << "cannot find key! key : "<<key<<" index : "<<hi<<endl;
		return hi;
	}

	if(key<data[half]){
		return _binary_search(data, key, lo, half);

	} else if(key>data[half]){
		return _binary_search(data, key, half, hi);
	}


	// if((hi-lo<=2)&&key!=data[half]){
	// 	return half;
	//}


	//cout << "your code here \n";

	return 0;
}

int binary_search(int *list, int key, int size) {
	DPRINT(cout << ">binary_search: key=" << key << " size=" << size << endl;);
	int answer;
	answer = _binary_search(list, key, 0, size);
	DPRINT(cout << "<binary_search: answer=" << answer << endl;);
	//cout << "answer : "<<answer<<endl;
	return answer;
}



#if 0
int main(int argc, char *argv[]) {
	int list[] = { 3, 5, 6, 9, 11, 12, 15, 16, 18, 19, 20 };
	//int list[] = { 1,2,3,5,6,7 };

	int size = sizeof(list) / sizeof(list[0]);
	int key;
	int result;
	cout << "list: ";
	for (int i = 0; i < size; i++)
		cout << list[i] << " ";
	cout << endl;

	srand(time(NULL));

	for(int i=0; i<size; i++){

		key = rand()%17+3;
		//cout << "size : "<<size<<endl;

		//cout << "key : " << key << endl ;

		result=binary_search(list,key,size-1);

		// randomly generate numbers to search between
		// list[0] = 3 and list[size-1] = 20, inclusviely.
		// do this by 'size' times.
		// print the results as shown in binsearchx.exe.


		if(key==list[result]){
			cout << key <<"\t is @[" << result <<"]"<<endl;
		} else if(key!=list[result]){
			cout << key <<"\t is not @[" << result <<"]"<<endl;
		}
}

	//cout << "your code here \n";

}
#endif
