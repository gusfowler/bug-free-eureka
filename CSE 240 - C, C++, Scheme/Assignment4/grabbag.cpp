#include "grabbag.h"

//Constructor, used to create linked list
grabBag::grabBag() {
	head = NULL;
	
	//used for random number generator that was used during debugging
	srand(time(NULL));

	//fills linked list with all 52 cards in a deck
	fillWithCards();
}

//used during debugging to print all cards in the deck
void grabBag::printCards() {
	bagNode* current = head;
	while (current->next != NULL) {
		std::cout << current->card->Suit << " " << current->card->value << std::endl;
		current = current->next;
	}
	std::cout << current->card->Suit << " " << current->card->value << std::endl;
}

//used during debugging and development to generate a random card
Card* grabBag::genRandCard() {
	//store vars
	int Rsuit, Rval;
	Card * card;
	card = new Card;

	//generate rand ints
	Rsuit = (rand() % 4);
	Rval = (rand() % 13) + 1;

	//create card
	if (Rsuit == 0) card->Suit = Hearts;
	else if (Rsuit == 1) card->Suit = Diamonds;
	else if (Rsuit == 2) card->Suit = Spades;
	else if (Rsuit == 3) card->Suit = Clubs;
	else {
		std::cout << "Error in random card generation (suit)" << std::endl;
	}

	card->value = Rval;

	std::cout << "hit card generation" << std::endl;
	//return card
	return card;
}

//Adds card to bag by taking a pointer to a card and creating a node and placing it into the linked list appropriately
void grabBag::add(Card* c) {
	//if no head, create head
	if (head == NULL) {
		head = new bagNode();
		head->card = c;
		head->head = head;
		head->next = NULL;
	}
	
	//if no head->next, create that
	else if (head->next == NULL) {
		bagNode * node;
		node = new bagNode;
		node->card = c;
		node->head = head;
		node->next = NULL;
		head->next = node;
	}

	//else add to end
	else {
		bagNode *node;
		node = new bagNode();
		node->card = c;
		node->head = head;
		node->next = NULL;
		getTailPointer()->next = node;
	}
}

//Returns pointer to the last node in the linked list
bagNode* grabBag::getTailPointer() {
	//counter starting from head
	bagNode* current = head;

	//iterate thru to end
	while (current->next != NULL) {
		current = current->next;
	}

	//return last pointer
	return current;
}

//counts the number of nodes in the bag and returns that value
int grabBag::getCurrentSize() {
	int counter = 0;

	//iterator starting at head
	bagNode* current = head;

	if (current == NULL) return counter;
	else {
		//iterate\
		while (current != NULL) {
			counter += 1;
			if (current->next == NULL) break;
			current = current->next;
		}
	}

	//return counter
	return counter;
}

//used to add a card of each type into the linked list
void grabBag::fillWithCards() {
	//loop through for each suit
	
	for (int x = 0; x < 4; x++) {
		//store suit val
		char suit;

		//determine which suit and set that value
		if (x == 0) { suit = Spades; }
		if (x == 1) { suit = Hearts; }
		if (x == 2) { suit = Diamonds; }
		if (x == 3) { suit = Clubs; }

		//loop thru to add each card for said suit
		for (int x = 1; x < 14; x++) {
			Card * c;
			c = new Card;
			c->Suit = suit;
			c->value = x;
			add(c);
		}
	}
}

//used during debugging to fill the bag with random cards
void grabBag::fillWithRandCards() {
	//iterate thru adding cards
	while (getCurrentSize() < 52) {
		add(genRandCard());
	}
}

//removes a random card from the linked list and manages linked list appropiately
Card grabBag::grab() {
	//pick random card
	int cardIndex = (rand() % getCurrentSize());

	//iterate through to that card node
	bagNode* current = head;
	for (int x = 0; x <= cardIndex && current->next != NULL; x++) {
		current = current->next;
	}
	
	//move from node to card
	Card card = *(current->card);
	//current->card = NULL;

	//delete node
	deleteNode(current);

	//return card
	return card;
}

//used during debugging to pull the last card from the bag and remove it
Card grabBag::pop() {
	bagNode* node = getTailPointer();
	Card card = *(node->card);
	deleteNode(node);
	return card;
}

//used during debugging to get the last card in the list and see it without removing it
Card grabBag::peek() {
	bagNode* node = getTailPointer();
	Card card = *(node->card);
	return card;
}

//Used to get the head node of the linked list
//Allows for iteration thru the linked list outside of this class, for probability functions 
bagNode* grabBag::peekHead() {
	return head;
}

//Used to be able to delete a node from the list and have it managed appropriately
void grabBag::deleteNode(bagNode* toDel) {
	bagNode* current = head;

	if (current == toDel && current == head) {
		delete current;
		current = NULL;
		head = NULL;
	}
	else {
		//iterate thru to node before deleted
		while (current->next != NULL && current) {
			if (current->next == toDel) {
				if (current->next->next != NULL) {
					current->next = current->next->next;
				}
				else {
					current->next = NULL;
				}
				//delete toDel->card;
				delete toDel;
				break;
			}
			current = current->next;
		}
	}
}

//used to empty the deck of cards
void grabBag::empty() {
	while (head != NULL) {
		deleteNode(getTailPointer());
	}
}

//used to know if the bag of cards has anything in it or not
int grabBag::isEmpty() {
	//use current size to determine if empty
	if (getCurrentSize() <= 0) {
		return 0;
	}
	else {
		return 1;
	}
}

//Calculates how often a card occurs within the deck
int grabBag::getFrequencyOf(Card x) {
	int frequency = 0;
	bagNode* current = head;
	
	while (current->next != NULL) {
		Card working = *(current->card);
		if (working.Suit == x.Suit && working.value == x.value) {
			frequency += 1;
		}
		//move to next 
		current = current->next;
	}

	return frequency;
}