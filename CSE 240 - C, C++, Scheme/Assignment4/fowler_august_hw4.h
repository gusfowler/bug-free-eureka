//fowler_august_hw4.h: Function Declarations for fowler_august_hw4.cpp
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include "grabbag.h"

void startGame(grabBag bag, std::vector<Card> drawn, int points);
void printAllCards(grabBag bag);
void printAllCards(std::vector<Card> drawn);
void prettyPrint(Card card);
int compareCards(Card a, Card b);
double probCardHigher(grabBag bag, Card card);
double probCardLower(grabBag bag, Card card);
double probCardGuess(grabBag bag, Card card);