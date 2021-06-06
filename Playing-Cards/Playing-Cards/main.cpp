#include <iostream>
#include <ctime>
#include "Deck.h"

int main()
{
	srand(time(nullptr));  // change random seed every time
	Deck deck;
	deck.Shuffle();
	deck.Print();
	std::cout << std::endl;

	Card* card = deck.TopCard();
	card->Print();
	std::cout << std::endl;

	deck.PopCard();
	std::cout << "Popped the Top Card!" << std::endl;
	deck.TopCard()->Print();
	std::cout << std::endl;

	deck.Print();
	std::cout << std::endl;

	system("pause");
	return 0;
}