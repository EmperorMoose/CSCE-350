/**
A. Pierce Matthews
CSCE-350
10/21/17
Program 1
**/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

//This prints out up to the nth contents of array a
void print(int *a, int n)
{
	int i = 0;
	while(i<n) 
	{
		cout<<a[i]<<",";
		i++;
	}
}

//This swaps two members of the array
void swap(int i, int j, int *a)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

//This is the actual sort method
void quicksort(int *arr, int left, int right)
{
	//This is the mid point in the array
	//Formatted this way to prevent overflow as outlined "https://research.googleblog.com/2006/06/extra-extra-read-all-about-it-nearly.html"
	int mid = left + (right - left) / 2;
	cout<<"QS:"<<left<<","<<right<<"\n";

	int i = left;
	int j = right;
	int pivot = arr[mid];

	while(left<j || i<right)
	{
		while(arr[i]<pivot)
        i++;
        while(arr[j]>pivot)
        j--;

		//If the left item is ever less or equal to the right item, swap
        if(i<=j)
		{
            swap(i,j,arr);
            i++;
            j--;
        }
		//recursive sort again, if either side exeeds bounds, reset bounds
        else
		{
            if(left<j)
                quicksort(arr, left, j);
            if(i<right)
                quicksort(arr,i,right);
            return;
        }
	}
}

int main() 
{
	std::ifstream file("test.txt");
	std::vector<int> v;
	int number;

	while(file >> number)
	{
		v.push_back(number);
	}		
	
	int* arr = &v[0];

	//This needs to become ascii IO
	//int arr[8] = {110, 5, 10, 3, 22, 100, 1, 23};
	quicksort(arr, 0, (sizeof(arr)/sizeof(arr[0]))-1);
	print(arr, (sizeof(arr)/sizeof(arr[0])));
	return 0;
}