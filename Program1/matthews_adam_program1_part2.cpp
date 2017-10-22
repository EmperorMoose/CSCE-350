/**
A. Pierce Matthews
CSCE-350
10/22/17
Program 1 Part 2
**/

#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>

using namespace std;

//Generates 100 ascii files of the given input size
void generateFiles(int inputSize)
{
	//For each 100 files
	for(int i=0; i<100; i++)
	{
		//declare file as output stream
		ofstream outputFile("input_size_"+inputSize+"_"+i+".txt");
		//For each number
		for(int y = 0; y < inputSize; i++)
		{
			//Generate
			float r = (rand() / (float)RAND_MAX * 19) + 1;
			//Append to file
			outputFile << r + " ";
		}
		outputFile.close();
	}
}

//Generate 100 files of each input size
void generateFiles()
{
	//This is the loop for each of the 5 input sizes
	int size = 0;	
	while(size < 5)
	{
		//This controls which input size is generated 
		switch(size)
		{
			case 0:
			{
				generateFiles(10);
			}
			
			case 1:
			{
				generateFiles(100);
			}
			
			case 2:
			{
				generateFiles(1000);
			}
			
			case 3:
			{
				generateFiles(10000);
			}
			
			case 4:
			{
				generateFiles(100000);
			}
		} 
	}
}

int main(int argc, char* argv[])
{
	generateFiles();
}