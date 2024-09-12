
#include <iostream>
#include <memory>
#include "Factory.h"
#include "Strategy.h"
#include "Adapter.h"
using namespace std;

int main()
{
	//Factory metod
	shared_ptr<Item> item = Factory::craftingItem(ItemType::KNIFE);
	shared_ptr<Item> item2 = Factory::craftingItem(ItemType::KNIFE);
	shared_ptr<Item> item3 = Factory::craftingItem(ItemType::PISTOL);

	Factory::printCountOfItem();

	//Stratedy
	shared_ptr<KnifeAttack> closeAttack = make_shared<KnifeAttack>();
	shared_ptr<PistoleAttack> rangeAttack = make_shared<PistoleAttack>();

	Player player(closeAttack);
	cout << "Knive gave " << player.makeAttack(23, 5) << " damage!" << endl;
	
	player.swichWeapon(rangeAttack);
	cout << "Pistol gave " << player.makeAttack(23, 5) << " damage!" << endl;

	//Adapter
	shared_ptr<Bear> bear = make_shared<Bear>();
	shared_ptr<PlushToy> plushBear = make_shared<PlushToy>();

	shared_ptr<Adapter> newPlushBearSound = make_shared<Adapter>(bear);

	cout << "Bear say: ";
	bear->walkSpeed();
	bear->makeNoise();

	cout << "Plush Bear say: ";
	plushBear->makeSound();

	cout << "Plush Bear say like real: ";
	newPlushBearSound->makeSound();
}


