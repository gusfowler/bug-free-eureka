#pragma once

#include "bst.h"
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

int main();
void takeInput(bst<std::string>& database);
void printStatistics(bst<std::string>& database);
void printUniqueWords(bst<std::string>& database);
void printTopFiveMostUsed(bst<std::string>& database);
void printTopFiveLeastUsed(bst<std::string>& database);
std::vector<std::pair<int, std::string>> getSortedByFreq(bst<std::string>& database);
void analysisMenu(bst<std::string>& database);
void printAllByAlpha(bst<std::string>& database);
void printAllByFreq(bst<std::string>& database);
void checkFreq(bst<std::string>& database);
void writeToFile(bst<std::string> database);
void writeUniqueWords(bst<std::string> database, std::ofstream& file);
void writeTopFiveMostUsed(bst<std::string> database, std::ofstream& file);
void writeTopFiveLeastUsed(bst<std::string> database, std::ofstream& file);
void writeAllByAlpha(bst<std::string> database, std::ofstream& file);
void writeAllByFreq(bst<std::string> database, std::ofstream& file);
void printDatabase(bst<std::string> database);