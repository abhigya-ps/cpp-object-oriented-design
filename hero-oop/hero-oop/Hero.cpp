#include "Hero.h"

Hero::Hero(const std::string& NAME, int HEALTH, int SHIELD)
	: Competitor(NAME, HEALTH, SHIELD)
{
	// Nothing here...
}

void Hero::GetsAttacked()
{
	// 0 - 99
	int roll = rand() % 100;
	if (roll == 0) //  1% of the time
	{
		health = 0;
	}
	else if (roll <= 50)  // 50% of the time
	{
		shield -= (2 + (rand() % 4));
		if (shield < 0)
		{
			health += shield; // shield has a negative value now
			shield = 0;
		}
	}
	else if (roll <= 79) // 29% of the time
	{
		health -= (4 + (rand() % 5));
	}
	// 20% of the time, do nothing.
}

/*
* 1% of the time, the Hero is instantly defeated! Set health to 0.
* 20% of the time, the attack misses and does 0 damage.
* 50% of the time, the attack does 2 - 5 random shield damage.
* Once the shield has a value less than or equal to 0, the health takes the extra damage.
* 29% of the time, the attack does 4 - 8 health damage.
*/
