#pragma once
#include <iostream>
#include "Factory.h"

class Strategy
{
public:
	virtual ~Strategy() = default;
	virtual int useWeapon(int damage, int damageBonus) = 0;
	
};

class KnifeAttack : public Strategy
{
public:
	int useWeapon(int damage, int damageBonus) override
	{
		return damage * damageBonus;
	}
};

class PistoleAttack : public Strategy
{
public:
	int useWeapon(int damage, int damageBonus) override
	{
		return damage + damageBonus;
	}
};

class Player 
{
public:
	Player(std::shared_ptr<Strategy> _strategy) :
		strategy(_strategy)
	{}

	void swichWeapon(std::shared_ptr<Strategy> _strategy) 
	{
		strategy = _strategy;
	}

	int makeAttack(int weaponDamage, int bonus)
	{
		return strategy->useWeapon(weaponDamage, bonus);
	}

private:
	std::shared_ptr<Strategy> strategy;
};