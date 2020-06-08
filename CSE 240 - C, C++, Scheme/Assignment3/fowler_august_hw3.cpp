// fowler_august_hw3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cstdio>

using namespace std;

void menu();
void singleDMath();
void outputArray(int* arr, int SIZE);
int arrAvg(int* arr, int SIZE);
int arrMedian(int* arr, int SIZE);
int arrNotDuped(int* arr, int SIZE, int MAX);
int arrDuped(int* arr, int SIZE, int MAX);
void singleDChar();
void singleDMenu(char* arr, int SIZE);
void singleDFrequency(char* arr, int SIZE);
int getFrequencyOf(char* arr, int SIZE, char item);
void singleDRemove(char* arr, int SIZE);
void removeChar(char* arr, int SIZE, char item);
void singleDSort(char* arr, int SIZE);
void doubleDChar();
void doubleDMenu(char** arr, int length, int height);
void doubleDFrequency(char** arr, int length, int height);
void doubleDRemove(char** arr, int length, int height);


int main()
{
	//set rand() seed
	srand(time(NULL));

	cout << "Welcome to Assignment 3!" << endl;
	//Put menu seperate for easy return and have return 0;
	menu();
	return 0;
}

void menu() 
{
	int input;

	cout << "Menu:" << endl;
	cout << "1 - 1D Math" << endl;
	cout << "2 - Single Dimension Character Processing" << endl;
	cout << "3 - Two-D Character Processing" << endl;
	cout << "4 - Exit" << endl;
	cout << "Choose an option: " << endl;

	scanf(" %d", &input);

	if (input == 1) 
	{
		singleDMath();
	}
	else if (input == 2) 
	{
		singleDChar();
	}
	else if (input == 3) 
	{
		doubleDChar();
	}
	else if (input == 4) 
	{
		//break to main return 0
		return;
	}
	else 
	{
		cout << "Invalid input" << endl;
		menu();
	}

	//Should never hit this return statement for safety
	return;
}

void singleDMath()
{
	//to store user inputs
	static int SIZE, MIN, MAX;

	cout << "Single Dimensional Math:" << endl;

	//take input
	cout << "Please enter the size of the array: " << endl;
	scanf(" %d", &SIZE);
	cout << "Please enter the minimum number for the array: " << endl;
	scanf(" %d", &MIN);
	cout << "Please enter the maximum number for the array: " << endl;
	scanf(" %d", &MAX);

	//debugging
	//cout << SIZE << " " << MIN << " " << MAX << endl;

	int * arr;
	arr = new int [SIZE];

	//fill with random numbers
	for (int x = 0; x < SIZE; x++)
	{
		int random = (rand() % MAX) + 1;
		//cout << random << endl;
		arr[x] = random;
	}

	//output contents of array
	cout << "Contents of the array: " << endl;
	outputArray(arr, SIZE);

	//output avg of array
	cout << "Average: " << arrAvg(arr, SIZE) << endl;

	//output median of array
	cout << "Median: " << arrMedian(arr, SIZE) << endl;

	//output unique 
	cout << "Unique Numbers: " << arrNotDuped(arr, SIZE, MAX) << endl;

	//output duplicates
	cout << "Duplicate Numbers: " << arrDuped(arr, SIZE, MAX) << endl;
	
	//cleanup
	delete[] arr;
	//return to menu
	menu();
}

void outputArray(int* arr, int SIZE)
{
	cout << "{ ";
	for (int x = 0; x < SIZE; x++)
	{
		cout << " " << arr[x] << " ,";
	}
	cout << " }" << endl;
}

int arrAvg(int* arr, int SIZE)
{
	int total = 0;

	//create total
	for (int x = 0; x < SIZE; x++)
	{
		total += arr[x];
	}

	return total / SIZE;
}

int arrMedian(int* arr, int SIZE)
{
	//create temp arr
	int * temp;
	temp = new int[SIZE];

	//copy into temp arr
	for (int x = 0; x < SIZE; x++)
	{
		temp[x] = arr[x];
	}

	//sort temp arr
	sort(temp, temp + SIZE);

	//midpoint
	int mid = SIZE / 2;
	//find value
	int median = temp[mid];

	//garbage collection
	delete[] temp;

	return median;
}

int arrNotDuped(int* arr, int SIZE, int MAX)
{
	int numNotDuped = 0;
	
	// create array to max possible value
	int * temp;
	temp = new int[MAX + 1];

	//init each val of array to 0
	for (int x = 0; x < MAX + 1; x++)
	{
		temp[x] = 0;
	}

	//for each number in arr add 1 to that index in temp
	for (int x = 0; x < SIZE; x++)
	{
		temp[arr[x]] += 1;
	}

	//for each temp index == 1 add 1 to numNotDuped
	for (int x = 0; x < MAX + 1; x++) 
	{
		if (temp[x] == 1) 
		{
			numNotDuped += 1;
		}
	}

	//garbage collection
	delete[] temp;

	//return
	return numNotDuped;
}

int arrDuped(int* arr, int SIZE, int MAX)
{
	int numDuped = 0;

	// create array to max possible value
	int * temp;
	temp = new int[MAX + 1];

	//init each val of array to 0
	for (int x = 0; x < MAX + 1; x++)
	{
		temp[x] = 0;
	}

	//for each number in arr add 1 to that index in temp
	for (int x = 0; x < SIZE; x++)
	{
		temp[arr[x]] += 1;
	}

	//for each temp index == 1 add 1 to numNotDuped
	for (int x = 0; x < MAX + 1; x++)
	{
		if (temp[x] > 1)
		{
			numDuped += 1;
		}
	}

	//garbage collection
	delete[] temp;

	//return
	return numDuped;
}

void singleDChar() 
{
	//store arr size
	static int SIZE;
	
	//take input
	cout << "Please enter the size of the array: " << endl;
	scanf(" %d", &SIZE);

	//create arr
	char * arr;
	arr = new char[SIZE];

	//blankout arr
	for (int x = 0; x < SIZE; x++)
	{
		arr[x] = 0;
	}

	//fill arr with random lowercase chars
	for (int x = 0; x < SIZE; x++)
	{
		arr[x] = ('a' + rand() % ('z' - 'a'));
	}

	//start menu
	singleDMenu(arr, SIZE);

	//garbage
	delete[] arr;

	//return to menu
	menu();
}

void singleDMenu(char* arr, int SIZE)
{
	int iN;

	//print arr
	cout << "\n";
	cout << "Array contains: " << endl;
	for (int x = 0; x < SIZE; x++)
	{
		cout << arr[x];
	}
	cout << endl;

	//print menu
	cout << "\n";
	cout << "Array Options: " << endl;
	cout << "1. Check frequency of a letter" << endl;
	cout << "2. Remove a letter" << endl;
	cout << "3. Sort" << endl;
	cout << "4. Return to Main Menu" << endl;

	//take menu input
	scanf(" %d", &iN);
	if (iN == 1) singleDFrequency(arr, SIZE);
	else if (iN == 2) singleDRemove(arr, SIZE);
	else if (iN == 3) singleDSort(arr, SIZE);
	else if (iN == 4) return;
	else
	{
		cout << "Invalid Entry" << endl;
		singleDMenu(arr, SIZE);
	}

	return;
}

void singleDFrequency(char* arr, int SIZE)
{
	//take input
	char in = '\0';
	cout << "Please input a lowercase letter: " << endl;
	scanf(" %c", &in);

	//safety check
	if (in >= 'a' && in <= 'z')
	{
		int freq = getFrequencyOf(arr, SIZE, in);
		cout << "Frequency of " << in << ": " << freq << endl;
	}
	else
	{
		cout << "Invalid Entry" << endl;
		singleDFrequency(arr, SIZE);
		return;
	}

	cout << "\n" << endl;
	singleDMenu(arr, SIZE);
	return;
}

int getFrequencyOf(char* arr, int SIZE, char item)
{
	//create temp array for frequency
	int * temp;
	temp = new int[27];

	//init array to 0
	for (int x = 0; x < 27; x++)
	{
		temp[x] = 0;
	}
	
	//iterate thru arr and record frequency in temp
	for (int x = 0; x < SIZE; x++)
	{
		temp[arr[x] - 'a'] += 1;
	}

	//return for selected item
	int out = temp[item - 'a'];
	delete[] temp;
	return out;
}

void singleDRemove(char* arr, int SIZE)
{
	//take input on which char to remove
	char In;
	cout << "Which Character would you like to remove? (lowercase): " << endl;
	scanf(" %c", &In);

	//move to function to actually remove it
	if (In <= 'z' && In >= 'a')
	{
		removeChar(arr, SIZE, In);
	}

	//back to menu
	singleDMenu(arr, SIZE);
	return;
}

void removeChar(char* arr, int SIZE, char item)
{
	//count frequency for number of shift loops
	int iterations = getFrequencyOf(arr, SIZE, item);
	
	//iterate thru arr to remove
	for (int x = 0; x < SIZE; x++)
	{
		if (arr[x] == item)
		{
			arr[x] = '\0';
		}
	}

	//shift all other characters to fill space
	for (int x = 0; x < iterations; x++) 
	{
		for (int x = 0; x < SIZE; x++)
		{
			if (arr[x] == '\0')
			{
				if (x + 1 < SIZE)
				{
					//swap
					char temp = arr[x];
					arr[x] = arr[x + 1];
					arr[x + 1] = temp;
				}
			}
		}
	}

	return;
}

void singleDSort(char* arr, int SIZE)
{
	//sort array into abc order
	sort(arr, arr + SIZE);

	//back to menu
	singleDMenu(arr, SIZE);
	return;
}

void doubleDChar()
{
	//store length and width for the arr
	static int length, height;
	cout << "Enter the length of the array: " << endl;
	scanf(" %d", &length);
	cout << "Enter the height of the array: " << endl;
	scanf(" %d", &height);

	//create the array
	//height
	char ** arr;
	arr = new char* [height];
		//create the rows / length
	for (int x = 0; x < height; x++)
	{
		arr[x] = new char[length];
	}

	//init the array
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < length; x++)
		{
			arr[y][x] = '\0';
		}
	}

	//randomize the array
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < length; x++)
		{
			arr[y][x] = ('a' + rand() % ('z' - 'a'));
		}
	}

	//move to menu
	doubleDMenu(arr, length, height);

	//back to main menu
	menu();
	return;
}

void doubleDMenu(char** arr, int length, int height)
{
	//print the array
	cout << "Contents of the Array: " << endl;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < length; x++)
		{
			cout << arr[y][x] << " ";
		}
		cout << endl;
	}

	//store input
	int input;

	//print menu
	cout << "\n" << endl;
	cout << "Array Options: " << endl;
	cout << "1. Check frequency of a letter" << endl;
	cout << "2. Remove a letter" << endl;
	cout << "3. Return to Main Menu" << endl;
	scanf(" %d", &input);

	//respond to input
	if (input == 1) doubleDFrequency(arr, length, height);
	else if (input == 2) doubleDRemove(arr, length, height);
	else if (input == 3) return;
	else 
	{
		cout << "Invalid Input" << endl;
		doubleDMenu(arr, length, height);
	}
	
	return;
}

void doubleDFrequency(char** arr, int length, int height)
{
	//store frequency
	int freq = 0;
	
	//prompt for char
	char input;
	cout << "Enter a lowercase letter: " << endl;
	scanf(" %c", &input);

	//safetycheck
	if ('a' <= input && input <= 'z')
	{
		//iterate thru arrays to total frequencies
		for (int y = 0; y < height; y++)
		{
			freq += getFrequencyOf(arr[y], length, input);
		}
	}
	else
	{
		cout << "Invalid Input" << endl;
		doubleDFrequency(arr, length, height);
	}

	//output frequency
	cout << "Character " << input << " occurs " << freq << " times. \n" << endl;

	//return to menu
	doubleDMenu(arr, length, height);
	return;
}

void doubleDRemove(char** arr, int length, int height) 
{
	//prompt & store char to remove
	char input;
	cout << "Enter a lowercase character to remove: " << endl;
	scanf(" %c", &input);

	//safetycheck
	if ('a' <= input && input <= 'z')
	{
		//iterate thru arrays to remove character
		for (int y = 0; y < height; y++)
		{
			removeChar(arr[y], length, input);
		}
	}
	else
	{
		//Invalid case
		cout << "Invalid Input" << endl;
		doubleDRemove(arr, length, height);
	}

	//back to menu
	doubleDMenu(arr, length, height);
	return;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
