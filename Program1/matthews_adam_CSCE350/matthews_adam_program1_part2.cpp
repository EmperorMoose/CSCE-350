/**
A. Pierce Matthews
CSCE-350
10/22/17
Program 1 Part 2
**/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <sstream>

using namespace std;

//Generates 100 ascii files of the given input size
void generateFiles(int inputSize)
{
	
	//For each 100 files
	for(int i = 0; i < 100; i++)
	{
		std::ostringstream fileNameStream("input_size_");
		cout << "TEST 2 ";
		//declare file as output stream
		fileNameStream << inputSize << "_" << i << ".txt";
		
		std::string fileName = fileNameStream.str();
		
		ofstream outputFile(fileName.c_str());
		
		//ofstream outputFile("input_size_"+std::to_string(inputSize)+"_"+std::to_string(i)+".txt");
		//For each number
		for(int y = 0; y < inputSize; y++)
		{
			//Generate
			float r = (rand() / (float)RAND_MAX * 19) + 1;
			cout << r;
			cout << "TEST 3 ";
			//Append to file
			outputFile << r;
			outputFile << " ";
		}
		outputFile.close();
	}
}

//Generate 100 files of each input size
void generateFiles()
{
	//This is the loop for each of the 5 input sizes
	int size = 0;	
	while(size < 1)
	{
		//This controls which input size is generated 
		switch(size)
		{
			case 0:
			{
				cout << "TEST 1 ";
				generateFiles(10);
				cout << "TEST 4 |||||||||||||||||||||||||||||||||||||||||||||||||||||";
				cout << endl;
				size = size + 1;
			}
			
			case 1:
			{
				generateFiles(100);
				size = size + 1;
				cout << "TEST 5 |||||||||||||||||||||||||||||||||||||||||||||||||||||";
				cout << endl;
			}
			
			case 2:
			{
				generateFiles(1000);
				size = size + 1;
				cout << "TEST 6|||||||||||||||||||||||||||||||||||||||||||||||||||||";
				cout << endl;
			}
			
			case 3:
			{
				generateFiles(10000);
				size = size + 1;
				cout << "TEST 7 |||||||||||||||||||||||||||||||||||||||||||||||||||||";
				cout << endl;
			}
			
			case 4:
			{
				generateFiles(100000);
				size = size + 1;
				cout << "TEST 8 |||||||||||||||||||||||||||||||||||||||||||||||||||||";
				cout << endl;
			}
		} 
	}
}



int main(int argc, char* argv[])
{
	generateFiles();
}