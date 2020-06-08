// fowler_august_hw5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "fowler_august_hw5.h"

using namespace std;

int main()
{
	cout << "Word Frequency Analysis - Binary Search Tree" << endl;

	bst<string> database = bst<string>();

	cout << "\n" << endl;
	takeInput(database);

	cout << "\n" << endl;
	printStatistics(database);

	cout << "\n" << endl;
	analysisMenu(database);
}

void takeInput(bst<string>& database) {
	cout << "Please enter the name of the file to analyize: " << endl;
	string fileName;
	cin >> fileName;

	cout << "Reading from " << fileName << endl;
	ifstream file (fileName);
	
	string * s;
	s = new string;
	while (file.good()) {
		char c = file.get();
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == 39) {
			if (!(s->empty() && c == 39)) {
				(*s) += c;
			}
		}
		else if ((*s).size() > 0) {
			transform((*s).begin(), (*s).end(), (*s).begin(), ::toupper);
			database.Insert(*s);
			s = new string;
		}
	}
}

void printStatistics(bst<string>& database) {
	//print # of words
	cout << "Total Words: " << database.Length << endl;

	//print # of unique words
	printUniqueWords(database);

	//print top 5 most used words
	cout << endl;
	printTopFiveMostUsed(database);

	//print top 5 least used words
	cout << endl;
	printTopFiveLeastUsed(database);
}

void printUniqueWords(bst<string>& database) {
	//pull vector of words
	vector<string> vect = database.ToVector();

	//count # of unique words
	int unique = 0;

	for (vector<string>::iterator it = vect.begin(); it != vect.end(); ++it) {
		if (database.getFrequency(*it) == 1) {
			unique += 1;
		}
	}

  	cout << "Total Unique Words: " << unique << endl;
}

void printTopFiveMostUsed(bst<string>& database) {
	vector<pair<int, string>> sorted = getSortedByFreq(database);

	cout << "Top 5 Most Used Words: " << endl;
	int counter = 0;
	for (vector<pair<int, string>>::reverse_iterator it = sorted.rbegin(); it != sorted.rend() && counter < 5; ++it) {
		counter++;
		printf("%d: %s - %d\n", (counter), it->second.c_str(), it->first);
	}
}

void printTopFiveLeastUsed(bst<string>& database) {
	vector<pair<int, string>> sorted = getSortedByFreq(database);

	cout << "Top 5 Least Used Words: " << endl;
	int counter = 0;
	for (vector<pair<int, string>>::iterator it = sorted.begin(); it != sorted.end() && counter < 5; ++it) {
		counter++;
		printf("%d: %s - %d\n", counter, it->second.c_str(), it->first);
	}
}

vector<pair<int, string>> getSortedByFreq(bst<string>& database) {
	vector<string> vect = database.ToVector();
	vector<pair<int, string>> sorted;

	for (vector<string>::iterator vectIt = vect.begin(); vectIt != vect.end(); ++vectIt) {
		int freq = database.getFrequency(*vectIt);
		sorted.push_back(make_pair(freq, *vectIt));
	}

	sort(sorted.begin(), sorted.end());

	return sorted;
 }

void analysisMenu(bst<string>& database) {
	//prompt with options
	cout << "Please enter an option: " << endl;
	cout << "1. View All Words sorted Alphabetically" << endl;
	cout << "2. View All Words sorted by Frequency" << endl;
	cout << "3. Check Frequency of specific word" << endl;
	cout << "4. Output Analysis to File" << endl;
	cout << "5. Exit" << endl;

	//take input
	int choice = 0;
	scanf(" %d", &choice);

	//if to execute option
	if (choice >= 1 && choice <= 5) {
		//1. View All Words sorted Alphabetically
		cout << "\n" << endl;
		if (choice == 1) printAllByAlpha(database);

		//2. View All Words sorted by Frequency
		cout << "\n" << endl;
		if (choice == 2) printAllByFreq(database);

		//3. Check Frequency of specific word
		cout << "\n" << endl;
		if (choice == 3) checkFreq(database);

		//4. Output Analysis to File
		cout << "\n" << endl;
		if (choice == 4) writeToFile(database);

		//5. Exit
		if (choice == 5) {
			exit(0);
		}
	}
	else {
		cout << "\nInvalid Entry\n" << endl;
		analysisMenu(database);
	}
}

void printAllByAlpha(bst<string>& database) {
	vector<string> vect = database.ToVector();

	cout << "All Words Sorted Alphabetically: " << endl;
	int count = 0;
	for (vector<string>::iterator it = vect.begin(); it != vect.end(); ++it) {
		count++;
		printf("%d: %s - %d\n", count, it->c_str(), database.getFrequency(*it));
	}

	cout << endl;
	analysisMenu(database);
}

void printAllByFreq(bst<string>& database) {
	vector<pair<int, string>> vect = getSortedByFreq(database);

	cout << "All Words Sorted by Frequency: " << endl;
	int count = 0;
	for (vector<pair<int, string>>::reverse_iterator it = vect.rbegin(); it != vect.rend(); ++it) {
		count++;
		printf("%d: %s - %d\n", count, it->second.c_str(), it->first);
	}

	cout << "\n" << endl;
	analysisMenu(database);
}

void checkFreq(bst<string>& database) {
	cout << "Enter the word you want to check the frequency of: " << endl;
	string input;
	cin >> input;

	transform(input.begin(), input.end(), input.begin(), ::toupper);

	int freq = database.getFrequency(input);

	cout << "The word " << input << " occurs " << freq << " times." << endl;

	cout << endl;
	analysisMenu(database);
}

void writeToFile(bst<string> database) {
	//create analysis file
	ofstream file;
	file.open("Word_Analysis.txt");
	file << "Word Analysis File: \n\n" << endl;

	//write total words
	file << "Total Words: " << database.Length << endl;

	//write total unique words
	writeUniqueWords(database, file);

	//write top and bottom 5 frequent words
	file << "\n" << endl;
	writeTopFiveMostUsed(database, file);

	file << "\n" << endl;
	writeTopFiveLeastUsed(database, file);

	//write all words sorted alpha
	file << "\n" << endl;
	writeAllByAlpha(database, file);

	//write all words sorted freq
	file << "\n" << endl;
	writeAllByFreq(database, file);

	//close file
	file.close();

	cout << "Analysis Written to Word_Analysis.txt" << endl;
	cout << "\n" << endl;
	analysisMenu(database);
}

void writeUniqueWords(bst<string> database, ofstream& file) {
	//pull vector of words
	vector<string> vect = database.ToVector();

	//count # of unique words
	int unique = 0;

	for (vector<string>::iterator it = vect.begin(); it != vect.end(); ++it) {
		if (database.getFrequency(*it) == 1) {
			unique += 1;
		}
	}

	file << "Total Unique Words: " << unique << endl;
}

void writeTopFiveMostUsed(bst<string> database, ofstream& file) {
	vector<pair<int, string>> sorted = getSortedByFreq(database);

	file << "Top 5 Most Used Words: " << endl;
	int counter = 0;
	for (vector<pair<int, string>>::reverse_iterator it = sorted.rbegin(); it != sorted.rend() && counter < 5; ++it) {
		counter++;
		file << (counter) << ": " << it->second << " - " << it->first << endl;
	}
}

void writeTopFiveLeastUsed(bst<string> database, ofstream& file) {
	vector<pair<int, string>> sorted = getSortedByFreq(database);

	file << "Top 5 Least Used Words: " << endl;
	int counter = 0;
	for (vector<pair<int, string>>::iterator it = sorted.begin(); it != sorted.end() && counter < 5; ++it) {
		counter++;
		file << (counter) << ": " << it->second << " - " << it->first << endl;
	}
}

void writeAllByAlpha(bst<string> database, ofstream& file) {
	vector<string> vect = database.ToVector();

	file << "All Words Sorted Alphabetically: " << endl;
	int count = 0;
	for (vector<string>::iterator it = vect.begin(); it != vect.end(); ++it) {
		count++;
		file << count << ": " << *it << " - " << database.getFrequency(*it) << endl;
	}
}

void writeAllByFreq(bst<string> database, ofstream& file) {
	vector<pair<int, string>> vect = getSortedByFreq(database);

	file << "All Words Sorted by Frequency: " << endl;
	int count = 0;
	for (vector<pair<int, string>>::reverse_iterator it = vect.rbegin(); it != vect.rend(); ++it) {
		count++;
		file << count << ": " << it->second << " - " << it->first << endl;
	}
}

void printDatabase(bst<std::string> database) {
	vector<string> vect = database.ToVector();

	for (vector<string>::iterator it = vect.begin(); it != vect.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
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
