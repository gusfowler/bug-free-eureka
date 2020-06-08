// fowler_august_hw2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <fstream>
#include <time.h>

#define subm(a, b) (a - b)
#define cubem(a) (a * a * a)
#define minm(a , b) (a <= b ? a : b)
#define oddm(a) (a % 2 == 0 ? 0 : 1)

using namespace std;

void drShowdown();
void charGenerator();
void mvfThrowDown();
int subf(int a, int b);
int cubef(int a);
int minf(int a, int b);
int oddf(int a);

int main()
{
	int choice;

	std::cout << "Welcome to the fantasy player fun tool!\n1 - Dice Roll Showdown\n2 - Generate a Character\n3 - Macros vs Functions Throw-down\n0 - Exit\nChoose an option:\n"; 
	cin >> choice;

	switch (choice) {
		case 1: drShowdown();
		case 2: charGenerator();
		case 3: mvfThrowDown();
		case 0: exit(0);
		default: cout << "Please Enter a number between 0 - 3." << endl;
	}
	
	return 0;
}

void drShowdown() 
{
	srand(time(NULL));

	int sides = 0, count = 0;
	int p1Score = 0, p2Score = 0;

	cout << "Welcome to the Dice Roll Showdown!" << endl;
	cout << "How many sides do the dice have (input a positive number)?:" << endl;
	cin >> sides;
	cout << "How many dice will each player roll?: " << endl;
	cin >> count;

	cout << "Player 1 Rolled: " << endl;
	for (int x = count; x > 0; x--) {
		int z = rand() % sides + 1;
		cout << z << endl;
		p1Score += z;
	}
	cout << "Total: " << p1Score << endl;

	cout << "\nPlayer 2 Rolled: " << endl;
	for (int y = count; y > 0; y--) {
		int z = rand() % sides + 1;
		cout << z << endl;
		p2Score += z;
	}
	cout << "Total: " << p2Score << endl;

	if (p1Score > p2Score) {
		cout << "Player 1 Wins!\n" << endl;
	}
	else if (p2Score > p1Score) {
		cout << "Player 2 Wins!\n" << endl;
	}
	else {
		cout << "It's a tie!\n" << endl;
	}
	main();
}

void charGenerator() {
	cout << "Welcome to the Fantasy Character generator!" << endl;
	
	srand(time(NULL));
	int seed = 10000 + rand() % (99999 - 10000);
	cout << "Seed generated: " << seed << endl;

	stringstream ss;
	ss << seed;
	string strSeed = ss.str();
	
	if (strSeed[0] % 2 == 0) {
		cout << strSeed[0] << " - Good" << endl;
	}
	else if (strSeed[0] % 2 == 1) {
		cout << strSeed[0] << " - Evil" << endl;
	}
	else {
		cout << "Error" << endl;
	}

	string strNames;
	string Name;
	ifstream hwNames;
	hwNames.open("hwNames.txt");
	if (hwNames.is_open()) {
		int int1 = strSeed[1] - '0', int2 = strSeed[2] - '0';
		int1 = int1 * 10;
		int target = int1 + int2;
		for (int i = 1; i <= target; i++) {
			std::getline(hwNames, Name);
			//for debugging
			//cout << Name << i << endl;
		}
		cout << target << " - " << Name << endl;
	}
	else {
		cout << "File is not open" << endl;
	}
	

	switch ((int)strSeed[3] - (int)'0') {
		case 0: 
			cout << strSeed[3] << " - Human" << endl;
			break;
		case 1:
			cout << strSeed[3] << " - Elf" << endl;
			break;
		case 2:
			cout << strSeed[3] << " - Halfing" << endl;
			break;
		case 3:
			cout << strSeed[3] << " - Gnome" << endl;
			break;
		case 4:
			cout << strSeed[3] << " - Dwarf" << endl;
			break;
		case 5:
			cout << strSeed[3] << " - Half-Elf" << endl;
			break;
		case 6:
			cout << strSeed[3] << " - Kobold" << endl;
			break;
		case 7:
			cout << strSeed[3] << " - Half-Ord" << endl;
			break;
		case 8:
			cout << strSeed[3] << " - Dragon-kin" << endl;
			break;
		case 9:
			cout << strSeed[3] << " - Construct" << endl;
			break;
	}

	switch ((int)strSeed[4] - (int)'0') {
		case 0:
			cout << strSeed[4] << " - Barbarian" << endl;
			break;
		case 1:
			cout << strSeed[4] << " - Bard" << endl;
			break;
		case 2:
			cout << strSeed[4] << " - Cleric" << endl;
			break;
		case 3:
			cout << strSeed[4] << " - Druid" << endl;
			break;
		case 4:
			cout << strSeed[4] << " - Fighter" << endl;
			break;
		case 5:
			cout << strSeed[4] << " - Wizard" << endl;
			break;
		case 6:
			cout << strSeed[4] << " - Monk" << endl;
			break;
		case 7:
			cout << strSeed[4] << " - Paladin" << endl;
			break;
		case 8:
			cout << strSeed[4] << " - Ranger" << endl;
			break;
		case 9:
			cout << strSeed[4] << " - Rogue" << endl;
			break;
	}

	cout << "Would you like to generate another character? (1 - yes, 0 - no):" << endl;
	int inNum;
	cin >> inNum;
	if (inNum == 1) charGenerator();

	main();
}

void mvfThrowDown() {
	int num1 = 5, num2 = 7;
	cout << "num1 , num2" << num1 << " " << num2 << endl;
	cout << "FUNCTION SUB: " << subf(num1, num2) << endl;
	num1 = 5, num2 = 7;
	cout << "MACRO SUB: " << subm(num1, num2) << endl;
	num1 = 5, num2 = 7;
	cout << "FUNCTION SUB: " << subf(num1++, num2--) << endl;
	num1 = 5, num2 = 7;
	cout << "MACRO SUB: " << subm(num1++, num2--) << endl;
	num1 = 5, num2 = 7;
	cout << "FUNCTION CUBE: " << cubef(num1) << endl;
	num1 = 5, num2 = 7;
	cout << "MACRO CUBE: " << cubem(num1) << endl;
	num1 = 5, num2 = 7;
	cout << "FUNCTION CUBE: " << cubef(--num1) << endl;
	num1 = 5, num2 = 7;
	cout << "MACRO CUBE: " << cubem(--num1) << endl;
	num1 = 5, num2 = 7;
	cout << "FUNCTION MIN: " << minf(num1, num2) << endl;
	num1 = 5, num2 = 7;
	cout << "MACRO MIN: " << minm(num1, num2) << endl;
	num1 = 5, num2 = 7;
	cout << "FUNCTION MIN: " << minf(--num1, --num2) << endl;
	num1 = 5, num2 = 7;
	cout << "MACRO MIN: " << minm(--num1, --num2) << endl;
	num1 = 5, num2 = 7;
	cout << "FUNCTION ODD: " << oddf(num1) << endl;
	num1 = 5, num2 = 7;
	cout << "FUNCTION ODD: " << oddm(num1) << endl;
	num1 = 5, num2 = 7;
	cout << "FUNCTION ODD: " << oddf(num1++) << endl;
	num1 = 5, num2 = 7;
	cout << "FUNCTION ODD: " << oddm(num1++) << endl;
	num1 = 5, num2 = 7;

	main();
}

int subf(int a, int b) { return a - b; }
int cubef(int a) { return a * a * a; }
int minf(int a, int b) {
	if (a <= b) {
		return a;
	}
	else {
		return b;
	}
}
int oddf(int a) {
	if (a % 2 == 0) {
		return 0;
	}
	else {
		return 1;
	}
}


