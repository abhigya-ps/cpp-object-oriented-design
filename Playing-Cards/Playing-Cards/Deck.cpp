#include <iostream>
#include <algorithm>
#include "Deck.h"

Deck::Deck()
	: deck()
{
	// get a memory block that holds 52 of the card pointers
	//deck.reserve(52);  // reserve works for vector, not for deque

	for (Card::Ranks r = Card::TWO; r <= Card::ACE; r = static_cast<Card::Ranks>(static_cast<int>(r) + 1))
	{
		for (Card::Suits s = Card::HEARTS; s <= Card::SPADES; s = static_cast<Card::Suits>(static_cast<int>(s) + 1))
		{
			deck.push_front(new Card(r, s));
		}
	}
}

Deck::~Deck()
{
	for (Card* card : deck)
	{
		delete card;
	}
}

void Deck::Print()
{
	for (Card* card : deck)
	{
		card->Print();
		std::cout << " ";
	}
}

void Deck::Shuffle()
{
	std::random_shuffle(deck.begin(), deck.end());
}

Card* Deck::TopCard()
{
	return deck.front();
}

void Deck::PopCard()
{
	// copy the card from the front to the back and then erase it
	deck.push_back(deck.front());
	deck.erase(deck.begin());
}
