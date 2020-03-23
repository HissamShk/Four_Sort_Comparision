//CSCI 301
//FourSorts.h
//FourSorts Class: A Class to implement 4 different sorting algorithms; 3 of which are on arrays, 
//and one of which is through the conversion of an array into a heap. 
//The samples that are being sorted are of varying sizes and track characteristic operations.
//Hissamuddin Shaikh
//This class contains 4 functions, 3 of which carry out a different type of sorts on an array, and one which does it through a heap.
//The 4 sorts are Insertion Sort, Merge Sort, Quick Sort and Heap Sort.
#ifndef FOURSORTS_H
#define FOURSORTS_H
#include <fstream>
using namespace std;
//Class, containing functions that will sort, through the use of different Sorting Algorithms.
class FourSorts
{
    public:
		/*Sort Functions*/
        void insertSorter (int arr [], int n , int & x );
		//Pre-Condition: Takes in an array, the size of the array, 
		//               and a variable x to increment upon characteristic operations.
        //Post-Condition: Results in the Array passed on to the function, being sorted in ascending order.
        void mergeSort (int arr [], int l , int r , int & x );
		//Pre-Condition: Takes in an array, the lowest (left-most) position value of the array,
		//               the highest (right-most) position value of the array,
		//				 and a variable x to increment upon characteristic operations.
        //Post-Condition: Results in the Array passed on to the function, being sorted in ascending order.
        void quickSort (int arr [], int low , int high , int & x );
		//Pre-Condition: Takes in an array, the lowest (left-most) position value of the array,
		//               the highest (right-most) position value of the array,
		//				 and a variable x to increment upon characteristic operations.
        //Post-Condition: Results in the Array passed on to the function, being sorted in ascending order.
		void heapSort(int arr[], int n , int &x);
		//Pre-Condition: Takes in an array which is to be sorted, the size fo the array (n) 
		//               and a variable x to increment upon characteristic operations.
        //Post-Condition: Turns the array into a heap, and through the operations contained within the function
		//				  returns the Array that was passed on to the function, sorted in ascending order.
    private:
		/*Private Functions*/
		void merge(int arr [], int l , int m , int r , int & x );
		//Pre-Condition: Takes in an array, the lowest (left-most) position value of the array,
		//               the highest (right-most) position value of the array,
		//				 and a variable x to increment upon characteristic operations. 
		//				 Also, takes in the middle value.
		//Post-Condition: Results in the Merging of 2 sub-Arrays of arr [].
        void swapper (int * a , int * b , int & x );
		//Pre-Condition: Takes in two elements (a and b),
		//				 and a variable x to increment upon characteristic operations. 
		//Post-Condition: Results in the 2 variables being swapped, with regards to their position.
        int partitioner (int arr [], int low , int high , int & x );
		//Pre-Condition: Takes in an array, the lowest (left-most) position value of the array,
		//               the highest (right-most) position value of the array,
		//				 and a variable x to increment upon characteristic operations. 
		//Post-Condition: This function takes last element as a pivot, places the pivot element at its correct
		//				  position in sorted array, and places all smaller (smaller than pivot) to left of
		//				  pivot and all greater elements to right of pivot
		void heapify(int arr[], int n, int i, int &x);
		//Pre-Condition: Takes in an unsorted array, the size of the array (n), a subtree rooted with node "i",
		//				 which is an index in arr[], and a variable x to increment upon characteristic operations.
        //Post-Condition: Ensures that the tree created maintains the nature of a heap, and is largely responsible
		//				  for sorting the heap into the apporpriate order.
};
#endif //FOURSORTS_H