/*On my honour, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
Signed: Lee YeEun   Section: 02       Student Number: 21800546
*/


/**
	HelloWho.cpp by idebtor@gmail.com
	It prints "Hello World!" on the console or
	"Hello" with a given name.

	To build the program which generates hellowho.exe:
	> g++ HelloWho.cpp -o hello

	To run the program without a command line argument:
	> ./hello
	> Enter a name:

	To run the program with a command line argument:
	> ./hello Dr. John Kim
	> Hello Dr. John Kim!

	02/10/19: Created
*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    // Use setvbuf() to prevent the output from buffered on console.
    // setvbuf(stdout, NULL, _IONBF, 0);
		string name = "";
		while(1){
				if(argv[1]==0){
			  cout << "Enter your name :";
			  getline(cin, name);
					if(name.length()>0)
				  	cout << "Hello " << name <<"!\n";
					else{
						cout << "Hello World!\n";
						break;
					}
				} else {
					cout << "Hello";
					for (int i = 1; i < argc; i++)
					cout << " " << argv[i] ;
					cout << "!\n";
					break;
				}

		}



    // Use system("pause") to prevent the terminal from disappearing
    // as soon as the program terminates such as Visual Studio sometimes.
    // system("pause");
    return EXIT_SUCCESS;
}
