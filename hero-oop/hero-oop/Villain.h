#pragma once
// does not get compiled more than once because of the above statement

#include "Competitor.h"

class Villain : public Competitor
{
public:
	Villain();
	virtual void GetsAttacked() override;

private:
	int max_shield;
};