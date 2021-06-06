#include <iostream>
#include "Card.h"

Card::Card(Ranks RANK, Suits SUIT)
	: Rank(RANK),
	Suit(SUIT)
{
}

Card::~Card()
{
	// nothing in virtual desctructor for now
	// avoids memory leaks for derived classes
}

Card::Ranks Card::GetRank()
{
	return Rank;
}

Card::Suits Card::GetSuit()
{
	return Suit;
}

int Card::GetFaceValue()
{
	if (Rank <= TEN)
		return static_cast<int>(Rank);

	// return 10 for jack, queen, and king
	if (Rank <= KING)
		return 10;

	// return 11 for ace
	return 11;
}

void Card::Print()
{
	if (Rank <= TEN)
		std::cout << Rank;
	else if (Rank == JACK)
		std::cout << "J";
	else if (Rank == QUEEN)
		std::cout << "Q";
	else if (Rank == KING)
		std::cout << "K";
	else
		std::cout << "A";

	if (Suit == HEARTS)
		std::cout << "H";
	else if (Suit == DIAMONDS)
		std::cout << "D";
	else if (Suit == CLUBS)
		std::cout << "C";
	else
		std::cout << "S";
}
