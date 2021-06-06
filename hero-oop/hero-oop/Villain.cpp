#include "Villain.h"

Villain::Villain()
	: Competitor("The Enemy", 30, 5),
		max_shield(5)
{
	// Nothing here...
}

void Villain::GetsAttacked()
{
	// First action - regenerate shield by 1
	int roll = rand() % 100; // 0 - 99
	if (roll < 15)
	{
		if (++shield > max_shield)
			--shield;
	}

	// Second action - take damage
	roll = rand() % 100;
	if (roll < 65)
	{
		shield -= (1 + (rand() % 2));
		if (shield < 0)
			health -= (5 + (rand() % 6));      
	}
}

/*
* The first action is to check if the shield will regenerate slightly.
* 15% of the time, add 1 to the shield value, and also make sure this new shield value is clamped to its maximum value.
* 85% of the time, no regeneration will occur.
* 
* The second action is to check if health damage is going to be done.
* 35% of the time, the attack misses and does 0 damage.
* 65% of the time, the following occurs:
* Shield takes 1 - 2 damage.
* However, if the modified shield value is less than zero, attack does random 5 - 10 health damage.
* Think of this as an actual physical shield that can be damaged with use.
* If the shield value is reduced to zero or a negative value, that means it has been destroyed.
*/