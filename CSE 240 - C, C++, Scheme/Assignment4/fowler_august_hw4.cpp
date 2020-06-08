// fowler_august_hw4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Assignment 4 for CSE 240 @ Arizona State University
//Written by August Fowler - 1214774210

#include "fowler_august_hw4.h"

using namespace std;

//Main function, prints intro, creates deck of cards and array for drawn
//cards, draws first card, creates points counter, and starts the game
int main()
{
	cout << "Welcome to Assignment 4 - Grab-Bag!" << endl;
	cout << "Author: August Fowler 1214774210" << endl;

	//intial deck
	grabBag bag = grabBag();

	//drawn cards
	vector<Card> drawn;

	//draw first card of the game
	drawn.push_back(bag.grab());

	//store points
	int points = 0;
	
	//go to the game
	startGame(bag, drawn, points);

	cout << "Thanks for playing!" << endl;
	return 0;
}

//Actual game method that loops drawing cards shown, prints each card that has been drawn,
//most recent card that has been drawn, and then displays the probability of next card being 
//higher lower or prob of you guessing the next card (1 / total cards). Proceeds to take input,
//assigning points where due. When bag has (1/3) of 52 left, the bag refills.
void startGame(grabBag bag, vector<Card> drawn, int points) {
	//flag to refill bag
	int refillBag = 0; //0 True 1 False
	
	//game prompt
	while (bag.getCurrentSize() > (52.0 * (1.0 / 3.0))) {
		//probability stats
		if (drawn.size() > 1) {
			cout << "\nAll cards drawn: " << "\n" << endl;
   			printAllCards(drawn);
		}
		cout << "\n\nCard Drawn: \n" << endl;
		prettyPrint(drawn.back());
		cout << "Probability next card is lower:       %" << (100.0 * probCardLower(bag, drawn.back())) << endl;
		cout << "Probability next card is higher:      %" << (100.0 * probCardHigher(bag, drawn.back())) << endl;
		cout << "Probability you can guess next card:  %" << (100.0 * probCardGuess(bag, drawn.back())) << endl;
		
		//prompt
		cout << "\n" << endl;
		cout << "You have 3 options: " << endl;
		cout << "1. Next card will be lower" << endl;
		cout << "2. Next card will be higher" << endl;
		cout << "3. Guess the next card" << endl;
		cout << "Points: " << points << endl;
		
		//take input
		int input = 0;
		scanf(" %d", &input);

		//processes input
		if (input == 1) {
			//draw new card
			Card newCard = bag.grab();
			
			//compare cards and give points
			if (compareCards(drawn.back(), newCard) == 1) {
				points++;
				cout << "You got a point!" << endl;
			}
			else {
				cout << "You were wrong, no point." << endl;
			}

			//move drawn into array
			drawn.push_back(newCard);
		}
		else if (input == 2) {
			//draw new card
			Card newCard = bag.grab();

			//compare cards and give points
			if (compareCards(drawn.back(), newCard) == -1) {
				points++;
				cout << "You got a point!" << endl;
			}
			else {
				cout << "You were wrong, no point." << endl;
			}

			//move drawn card into array
			drawn.push_back(newCard);
		}
		else if (input == 3) {
			//storage to create card in
			Card Guess;
			char SuitGuess;
			int ValGuess;

			//prompt for card
			cout << "Enter card suit guess: (H for Hearts, D for Diamonds, S for Spades, C for Clubs)" << endl;
			scanf(" %c", &SuitGuess);
			cout << "Enter card value guess: (Jack = 11, Queen = 12, King = 13, Ace = 1)" << endl;
			scanf(" %d", &ValGuess);

			//construct card
			if ((SuitGuess == 'H' || SuitGuess == 'D' || SuitGuess == 'S' || SuitGuess == 'C') && ValGuess >= 1 && ValGuess <= 14) {
				Guess.Suit = SuitGuess;
				Guess.value = ValGuess;
			}
			else {
				cout << "Invalid Input" << endl;
				refillBag = 1;
				break;
			}

			//draw new card
			Card newCard = bag.grab();
			
			//compare cards and give points
			if (compareCards(newCard, Guess) == 0) {
				points += 5;
				cout << "You guessed correctly! 5 points!" << endl;
			}
			else {
				cout << "Incorrect guess!" << endl;
			}
		}
		else if (input == 0) {
			exit(0);
		}
		else {
			cout << "Invalid input" << endl;
		}
	}

	//check to see if refill bag or not
	if (refillBag == 0) {
		cout << "\nYou have used 2/3rds of the cards in the bag! The bag will now refill, keeping the most recently drawn card;" << endl;
		
		//store most recent card
		Card recentCard = drawn.back();
		//remove said card
		drawn.pop_back();
		vector<Card> temp;
		drawn.shrink_to_fit();

		//iterate to move all cards from vector back to bag
		for (auto x = drawn.begin(); x != drawn.end(); x++) {
			bag.add(&(*x));
		}

		//clear vector
		drawn.clear();

		//readd most recent card
		drawn.push_back(recentCard);

		//restart game wrapper
		startGame(bag, drawn, points);
	}
	else {
		startGame(bag, drawn, points);
	}
}

//Comparison Function: if the card a is greater than b, then the output will be positive
//					 : if the card a is less than b, then the output will be negative
//					 : if equal output = 0
int compareCards(Card a, Card b) {
	double output = 0;
	int suitA, suitB, valA, valB;
	
	//move compare values
	valA = a.value;
	valB = b.value;

	if (a.Suit == 'C') suitA = 1;
	if (a.Suit == 'D') suitA = 2;
	if (a.Suit == 'H') suitA = 3;
	if (a.Suit == 'S') suitA = 4;
	if (b.Suit == 'C') suitB = 1;
	if (b.Suit == 'D') suitB = 2;
	if (b.Suit == 'H') suitB = 3;
	if (b.Suit == 'S') suitB = 4;

	//compare values
	if (suitA > suitB) {
		output = 1;
	}
	else if (suitA < suitB) {
		output = -1;
	}
	else if (suitA == suitB) {
		if (valA > valB) {
			output = 1;
		}
		else if (valA < valB) {
			output = -1;
		}
		else if (valA == valB) {
			output = 0;
		}
	}

	//return output
	return output;
}

//Calculates the probability of a higher card than the input existing within the deck
double probCardHigher(grabBag bag, Card card) {
	bagNode* node = bag.peekHead();
	double countCardsHigher = 0;
	double currentSize = bag.getCurrentSize();

	//loop through all
	while (node->next != NULL) {
		if (compareCards(card, *node->card) > 0) countCardsHigher += 1;
		node = node->next;
	}
	if (compareCards(card, *node->card) > 0) countCardsHigher += 1;

	//calculate probability
	double probability = (countCardsHigher / currentSize);

	return probability;
}

//Calculates the probability of a lower card than the input existing within the deck
double probCardLower(grabBag bag, Card card) {
	bagNode* node = bag.peekHead();
	double countCardsLower = 0;
	double currentSize = bag.getCurrentSize();

	//loop through all
	while (node->next != NULL) {
		if (compareCards(card, *node->card) < 0) countCardsLower += 1;
		node = node->next;
	}
	if (compareCards(card, *node->card) < 0) countCardsLower += 1;
	
	//calculate probability
	double probability = (countCardsLower / currentSize);

	return probability;
}

//Calculates the probability of the user being able to guess an individual card out of the deck
double probCardGuess(grabBag bag, Card card) {
	double currentSize = bag.getCurrentSize();
	double probability = (1.0 / currentSize);
	return probability;
}

//used to print all the cards in a bag mostly in debugging
void printAllCards(grabBag bag) {
	int countCards = 0;
	bagNode* node = bag.peekHead();
	while (node->next != NULL) {
		countCards += 1;
		cout << "Cards: " << countCards << endl;
		prettyPrint(*node->card);
		node = node->next;
	}
	prettyPrint(*node->card);
}

//Print all cards in drawn vector, used each round of game to show players what cards have been drawn
void printAllCards(vector<Card> drawn) {
	int countCards = 0;
	for (auto x = drawn.begin(); x != drawn.end(); x++) {
		countCards += 1;
		cout << "Cards: " << countCards << endl;
		prettyPrint(*x);
	}
}

//Makes the text output from a card look pretty in the cmdprompt
void prettyPrint(Card card) {
	int value = card.value;
	char suit = card.Suit;

	cout << "-------" << endl;
	if (value >= 10 || value == 1) {
		if (value == 10) cout << "|" << value << "   |" << endl;
		if (value == 11) cout << "|" << "J" << "    |" << endl;
		if (value == 12) cout << "|" << "Q" << "    |" << endl;
		if (value == 13) cout << "|" << "K" << "    |" << endl;
		if (value == 1) cout << "|" << "A" << "    |" << endl;
	}
	else {
		cout << "|" << value << "    |" << endl;
	}
	cout << "|" << suit << "    |" << endl;
	cout << "|     |" << endl;
	cout << "|    " << suit << "|" << endl;
	if (value >= 10 || value == 1) {
		if (value == 10) cout << "|   " << value << "|" << endl;
		if (value == 11) cout << "|    " << "J" << "|" << endl;
		if (value == 12) cout << "|    " << "Q" << "|" << endl;
		if (value == 13) cout << "|    " << "K" << "|" << endl;
		if (value == 1) cout << "|    " << "A" << "|" << endl;
	}
	else {
		cout << "|    " << value << "|" << endl;
	}
	cout << "-------" << endl;
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
