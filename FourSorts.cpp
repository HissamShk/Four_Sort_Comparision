//CSCI 301
//FourSorts.cpp
//FourSorts Class: A Class to implement 4 different sorting algorithms; 3 of which are on arrays, 
//and one of which is through the conversion of an array into a heap. 
//The samples that are being sorted are of varying sizes and track characteristic operations.
//Hissamuddin Shaikh
#include <iostream>
#include <fstream>
#include "FourSorts.h"
using namespace std;
//Function to sort values, at insert, by placing at the appropriate location within the array.
void FourSorts::insertSorter ( int arr [], int n , int & x )
{
	int i , key , j ;
	for ( i = 1 ; i < n ; i ++)
	{
		key = arr [ i ];
		j = i - 1 ;
		while ( j >= 0 && arr [ j ] > key )
		{
			x ++;
			arr [ j + 1 ] = arr [ j ];
			j = j - 1 ;
		}
		arr [ j + 1 ] = key ;
	}
}
//Function to merge 2 sub-arrays
void FourSorts::merge ( int arr [], int l , int m , int r , int & x )
{
	int i , j , k ;
	int n1 = m - l + 1 ;
	int n2 = r - m ;
	int L [ n1 ], R [ n2 ];
	for ( i = 0 ; i < n1 ; i ++)
	{
		x ++;
		L [ i ] = arr [ l + i ];
	}
	for ( j = 0 ; j < n2 ; j ++)
	{
		R [ j ] = arr [ m + 1 + j ];
	}
	i = 0 ; 
	j = 0 ; 
	k = l ; 
	while ( i < n1 && j < n2 )
	{
		if ( L [ i ] <= R [ j ])
		arr [ k ] = L [ i ++];
		else
		arr [ k ] = R [ j ++];
		k ++;
		x ++;
	}
	while ( i < n1 )
	{
		arr [ k ++] = L [ i ++];
		x ++;
	}
	while ( j < n2 )
	{
		arr [ k ++] = R [ j ++];
		x ++;
	}
}
//Function to carry-out the merge sort algorithm
void FourSorts::mergeSort ( int arr [], int l , int r , int & x )
{
	x ++;
	if ( l < r )
	{
		int m = l +( r - l )/ 2 ;
		mergeSort ( arr , l , m , x );
		mergeSort ( arr , m + 1 , r , x );
		merge ( arr , l , m , r , x );
	}
}
//Function to Swap 2 Elements
void FourSorts::swapper ( int * a , int * b , int & x )
{
	x ++;
	int t = * a ;
	* a = * b ;
	* b = t ;
}
//Function to takes last element as pivot, places the pivot element at its correct
//position in sorted array, and places all smaller (smaller than pivot) to left of
//pivot and all greater elements to right of pivot
int FourSorts::partitioner( int arr [], int low , int high , int & x )
{
	x++;
	int pivot = arr [ high ]; 
	int i = ( low - 1 ); 
	for ( int j = low ; j <= high - 1 ; j ++)
	{
		x ++;
		if ( arr [ j ] <= pivot )
		{
			x ++;
			i ++;
			swapper (& arr [ i ], & arr [ j ], x );
		}
	}
	swapper (& arr [ i + 1 ], & arr [ high ], x );
	return ( i + 1 );
}
//Function to implement a quick sort algorithm on an array 
void FourSorts::quickSort ( int arr [], int low , int high , int & x )
{
	x ++;
	if ( low < high )
	{
		int pi = partitioner ( arr , low , high , x );
		quickSort ( arr , low , pi - 1 , x );
		quickSort ( arr , pi + 1 , high , x );
	}
}
//Function to perform the neceessary operations to establish a heap,
//for the values of a given array, and sort through them. Does most of the heavy lifting.
void FourSorts::heapify (int arr[], int n, int i, int &x)
{
	int largest = i, 
	l = 2 * i + 1, 
	r = 2 * i + 2; 
	if (l < n && arr[l] > arr[largest])
	{
		largest = l;
		x++;
	}
	if (r < n && arr[r] > arr[largest])
	{
		largest = r;
		x++;
	}
	if (largest != i) 
	{
		swapper(&arr[i], &arr[largest] , x);
		heapify(arr , n , largest , x);
		x++;
	}
}
//Function to implement a heap sort algorithm
void FourSorts::heapSort (int arr[], int n , int &x)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		x++;
		heapify(arr, n, i , x);
	}
	for (int i=n-1; i>=0; i--)
	{
		x++;
		swapper(&arr[0], &arr[i], x);
		heapify(arr, i, 0 , x);
	}
}