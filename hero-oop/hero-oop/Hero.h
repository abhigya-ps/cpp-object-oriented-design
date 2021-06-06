#pragma once
// does not get compiled more than once because of the above statement

#include <string>
#include "Competitor.h"

class Hero : public Competitor
{
public:
	Hero(const std::string& NAME, int HEALTH, int SHIELD);  // passing string by reference so C++ does not make a copy of the string before we do

	virtual void GetsAttacked() override;
};