//CSCI 301
//PROJECT 11
//Sort Compare (with Heap Sort)	
//Hissamuddin Shaikh
//This program utilizes the class, FourSorts, to sort through a randomly generated array of values. The number of values in
//the array are specified by the user. It creates 4 copies,(5 arrays in total) and utilizes one of 4 different methods to
//sort each one of the 4 copied arrays. The 4 sorting methods being utilized are an Insert Sort, Merge Sort, Quick Sort and Heap Sort.
//The system can display the sorted array upon request from the User. Moreover, the system returns the number of
//characteristic operations, and in turn, the efficiency of the sorting algorithms, as far as computation and time are
//concerned, within the realm of the given computational platform. Therefore, this program can be utilized, not only
//to test sorting efficiency of the algorithms given various array-sizes, but to also see which type of sorting algorithm
//would be best to use in other implementations.
//The program exercises all of the functions of the FourSorts class.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "FourSorts.h"
using namespace std ;
/*Function Prototypes*/
void copyArr ( int START [] , int ARRAY_SIZE , int FIN []);
//Pre-Condition: Takes in the Array that is to be copied, into another Array (which is empty).
//				 Takes in the Size of the Array that is to be copied, to ensure that all values are copied and their inherent order is maintained.               
//				 Takes in the Array into which another Array is to be copied into, this Array is the same size as the one it is taking data from.
//Post-Condition: Returns an exact duplicate of a particular Array.
void randArr ( int r [] , int ARRAY_SIZE );
//Pre-Condition: Takes in an Array that is empty, and inserts random values into it.
//				 Takes in the Size of the Array, so as to play the appropriate amount of random values into the Array.               
//Post-Condition: Returns an array that is completely filled with randmon integers.
int main ()
{
	/*Data Variables*/
	
	//Object to access the class Sorts, which contains the 3 sorting algorithms.
	FourSorts S;
	//Integer to track the number of Insert Sort Operations.
	int i_count = 0;
	//Integer to track the number of Merge Sort Operations.
	int m_count = 0 ;
	//Integer to track the number of Quick Sort Operations.
	int q_count = 0 ;
	//Integer to track the number of Heap Sort Operations.
	int h_count = 0 ;
	//Integer to store the user-inserted seed, for the production of random numbers.
	int seed ;
	//Integer to store the user-inserted size for the array of random values to be sorted.
	int size ;
	//Variable to store the user's desire to whether or not print the sorted array of random values.
	char p_values ;

	/*Prompt for the User to enter the, necessary information to run the Simulation*/
	cout << endl;
	cout << "   | Sort Compare |" << endl;
	cout << endl;
	cout << "   Enter these Parameters for the Comparison to run:-" << endl;
	cout << endl;
	cout << "        The Number of Values to Generate and Sort, between 1 and 5000: "; cin >> size;
	cout << endl ;
	cout << "        An Integer Seed Value: "; cin >> seed;
	cout << endl ;
	cout << "        Print the Un-Sorted Array and Sorted Result(Y for Yes, N for No): "; cin >> p_values;
	cout << endl ;
	
	//Initializing the various Arrays that will undergo different sorts.
	int Orig [ size ], A [ size ], B [ size ], C [ size ], D [size];
	//Seeding the rand function, for the production of random values.
	srand ( seed );
	//Producing a Random Array
	randArr ( Orig , size );
	//Producing 4 copies of this Array. 
	copyArr ( Orig , size , A );
	copyArr ( Orig , size , B );
	copyArr ( Orig , size , C );
	copyArr ( Orig , size , D );
	//Sorting each Array with a different Sorting Algorithm
	S.insertSorter ( A , size , i_count );
	S.quickSort ( C , 0 , size - 1 , q_count );
	S.mergeSort ( B , 0 , size - 1 , m_count );
	S.heapSort (D, size, h_count);
	//Determining if to display the Sorted and Un-Sorted Array to the User.
	if ( toupper ( p_values ) == 'Y' )
	{
		cout << "   ORIGINAL ARRAY: " ;
		int a = 0;
		int b = 20;
		cout << Orig [ a ];
		for ( int r = 1 ; r < size ; r ++)
		{ 
			if (r%b == 0)
			{
				cout << endl;
				cout << "                   " ; cout << Orig [ r ];
			}
			else
				cout << ", " << Orig [ r ];
		}
		cout << endl;
		cout << endl;
		cout << "   SORTED ARRAY: " ;
		cout << D [ a ];
		for ( int r = 1 ; r < size ; r ++)
		{ 
			if (r%b == 0)
			{
				cout << endl;
				cout << "                 " ; cout << C [ r ];
			}
			else
				cout << ", " << C [ r ];
		}
		cout << endl ;
		}
	cout << "   ---------------------- " << endl;
	//Print out how efficient, in terms of computation (and time, in a sense) each algorithm was in sorting through the Array.	
	cout << "   Efficiency Counts" << endl;
	cout << "   ---------------------- " << endl;
	cout << "   Insertion Sort count = " << i_count << endl ;
	cout << endl;
	cout << "   Merge Sort count = " << m_count << endl ;
	cout << endl;
	cout << "   Quick Sort count = " << q_count << endl ;
	cout << endl;
	cout << "   Heap Sort count = " << h_count << endl ;
	cout << "   ---------------------- " << endl;
	return 0 ;
}
//Function to create a copy of a given array.
void copyArr ( int START [] , int ARRAY_SIZE , int FIN [])
{
for ( int x = 0 ; x < ARRAY_SIZE ; x ++)
FIN [ x ] = START [ x ];
}
//Function to create an array of a given size, filled with random values.
void randArr ( int r [] , int ARRAY_SIZE )
{
for ( int x = 0 ; x < ARRAY_SIZE ; x ++)
r [ x ] = rand () % ARRAY_SIZE + 1 ;
}