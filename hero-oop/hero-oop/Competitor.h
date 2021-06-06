#pragma once

#include <string>

class Competitor
{
public:
	Competitor(const std::string& NAME, int HEALTH, int SHIELD);  // passing string by reference so C++ does not make a copy of the string before we do

	std::string GetName() const;  // const -> just getting information, not modifying it
	int GetHealth() const;
	int GetShield() const;

	bool IsDefeated() const;
	virtual void GetsAttacked() = 0;  // the program knows which version of GetsAttacked to run at runtime, not compile time
	// equals to 0 means GetsAttacked is a pure virtual function - it has no base definition/behavior

protected:
	std::string name;
	int health;
	int shield;
};