#pragma once
#include <iostream>
#include <String>
#include <memory>


class Item 
{
public:
	~Item() {}
	virtual void makeHit() = 0;
};

class Knife : public Item 
{
public:
	Knife() 
	{
		std::cout << "Knife created!" << std::endl;
	};
	void makeHit() override 
	{
		std::cout << "Knife hit!" << std::endl;
	};
};

class Pistol : public Item 
{
public:
	Pistol() 
	{
		std::cout << "Pistol created!" << std::endl;
	};
	void makeHit() override 
	{
		std::cout << "Pistol hit!" << std::endl;
	};
};

enum class ItemType {
	KNIFE, 
	PISTOL
};

class Factory
{
public:
	static std::shared_ptr<Item> craftingItem(ItemType type) 
	{
		if (ItemType::KNIFE == type) 
		{
			s_knife++;
			return std::make_shared<Knife>();
		}
		if(ItemType::PISTOL == type)
		{
			s_pistol++;
			return std::make_shared<Pistol>();
		}
		return nullptr;
	}

	static void printCountOfItem()
	{
		std::cout << "You have " << s_knife + s_pistol << " items in inventory: " << std::endl;
		std::cout << "Knife: " << s_knife << std::endl;
		std::cout << "Pistol: " << s_pistol << std::endl;
	}
private:
	static int s_knife;
	static int s_pistol;
	
	Factory();
	~Factory() {}
};

int Factory::s_knife = 0;
int Factory::s_pistol = 0;