#include <ctime>
#include <iostream>
#include "Hero.h"
#include "Villain.h"
#include "Competitor.h"

int main()
{
	// Different randomness every time program is executed
	srand(static_cast<unsigned>(time(0)));
 
	// Run many simulations
	const int NUMBER_OF_SIMULATIONS = 1000000;

	// Count the total number of rounds survived
	int heroWins = 0;
	int villainWins = 0;

	// Repeat many times
	for (int i = 1; i <= NUMBER_OF_SIMULATIONS; ++i)
	{
		// Base class pointers pointing to derived class objects under the hood
		Competitor * oh = new Hero("Oh", 31, 13);  // declaration of an object
		Competitor * enemy = new Villain;  // not a declaration of an object, but a function prototype
		// pointers + virtual functions are necessary to ensure that functions calls are generated at run time, not compile time

		// While still healthy enough to compete in battle
		while ((oh->IsDefeated() == false) && (enemy->IsDefeated() == false))
		{
			enemy->GetsAttacked();
			if (enemy->IsDefeated() == false)
				oh->GetsAttacked();
		}

		if (enemy->IsDefeated() == true) ++heroWins;
		else ++villainWins;
	}

	double heroPct = heroWins / static_cast<double>(NUMBER_OF_SIMULATIONS) * 100;
	double villainPct = villainWins / static_cast<double>(NUMBER_OF_SIMULATIONS) * 100;

	// Gather and report final statistics
	std::cout << "Hero: " << heroPct << std::endl;
	std::cout << "Villain: " << villainPct << std::endl;

	// Clean up and exit program
	system("pause");
	return 0;

	//// Checking the Hero class
	//// Different randomness every time program is executed
	//srand(static_cast<unsigned>(time(0)));

	//// Get health
	//std::cout << "Enter hero's health value: ";
	//int health;
	//std::cin >> health;

	//// Get shield
	//std::cout << "Enter hero's shield value: ";
	//int shield;
	//std::cin >> shield;

	//// Run many simulations
	//const int NUMBER_OF_SIMULATIONS = 1000000;

	//// Count the total number of rounds survived
	//int roundsSurvived = 0;

	//// Repeat many times
	//for (int i = 1; i <= NUMBER_OF_SIMULATIONS; ++i)
	//{
	//	// Let's see how long one hero can last
	//	Hero oh("Oh", health, shield);

	//	// While still healthy enough to compete in battle
	//	while (oh.IsDefeated() == false)
	//	{
	//		// Take another hit
	//		++roundsSurvived;
	//		oh.GetsAttacked();
	//	}
	//}

	//// Gather and report final statistics
	//std::cout << "Average number of rounds until defeated: ";
	//double average = roundsSurvived / static_cast<double>(NUMBER_OF_SIMULATIONS);
	//std::cout << average << std::endl << std::endl;
}