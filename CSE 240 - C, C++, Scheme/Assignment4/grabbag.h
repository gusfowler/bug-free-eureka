#include <iostream>
#include <string>
#include <random>
#include <ctime>

//Define stucts and classes
//struct Card;
//struct bagNode;
//class grabBag;


//Card struct, used to store the data that is a card in a deck
struct Card {
	char Suit;
	int value;
};

//bagNode struct, used to form a linked list of cards
//features pointers to head and to the next node in the list
struct bagNode {
	Card* card;
	bagNode* next;
	bagNode* head;
};

//Class grabBag, features all definition for functions used in the class grabBag
class grabBag {
	private:
		const char Hearts = 'H', Diamonds = 'D', Spades = 'S', Clubs = 'C';
		bagNode * head;
		bagNode * getTailPointer();
	public:
		grabBag();
		void printCards();
		int getCurrentSize();
		int isEmpty();
		void add(Card*);
		Card grab();
		Card pop();
		Card* genRandCard();
		int getFrequencyOf(Card);
		void empty();
		void fillWithCards();
		void fillWithRandCards();
		void deleteNode(bagNode*);
		Card peek();
		bagNode* peekHead();
};