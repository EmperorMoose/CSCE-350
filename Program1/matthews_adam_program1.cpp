/**
A. Pierce Matthews
CSCE-350
10/21/17
Program 1 Part 1
**/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>

using namespace std;

//This prints out up to the nth contents of array a
void print(float *a, int n)
{
	int i = 0;
	while(i<n) 
	{
		cout<<a[i]<<",";
		i++;
	}
}

//This swaps two members of the array
void swap(int i, int j, float *a)
{
	float temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

//This is the actual sort method
void quicksort(float *arr, int left, int right)
{
	//This is the mid point in the array
	//Formatted this way to prevent overflow as outlined "https://research.googleblog.com/2006/06/extra-extra-read-all-about-it-nearly.html"
	int mid = left + (right - left) / 2;
	cout<<"QS:"<<left<<","<<right<<"\n";

	int i = left;
	int j = right;
	float pivot = arr[mid];

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

int main(int argc, char* argv[]) 
{
	//This is for execution time in miliseconds
	int start_c=clock();
	
	//This the the first argument, ie the input file
	std::ifstream file(argv[1]);

	std::vector<float> v;
	//not sure what number exactly does, so preserving original line
	//int number;
	float number;

	//This reads the file into a vector
	while(file >> number)
	{
		v.push_back(number);
		cout<<number;
	}		

	//Copies the vector into an array to perserve the original vector
	int s = v.size();
	float arr[s];
	std:copy(v.begin(), v.end(), arr);

	//Print out the contents of the array
	for(int i = 0; i<=s; i++)
		cout<<arr[i]<< " ";

	//Sort, print sorted array
	quicksort(arr, 0, (sizeof(arr)/sizeof(arr[0]))-1);
	print(arr, (sizeof(arr)/sizeof(arr[0])));
	
	//This is for file output
	ofstream outputFile(argv[2]);
	for(int i = 0; i<s; i++)
		outputFile<<arr[i]<<" ";
	outputFile.close();

	int stop_c=clock();
	cout << "Time: " << (stop_c-start_c)/double(CLOCKS_PER_SEC)*1000 << endl;

	return 0;
}