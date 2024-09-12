#pragma once
#include <iostream>

class Animal
{
public:
	virtual int walkSpeed() = 0;
	virtual void makeNoise() = 0;
};

class Bear : public Animal
{
public:
	int walkSpeed() override
	{
		return 8;
	}
	void makeNoise()  override
	{
		std::cout << "Roaring" << std::endl;
	}
};

class Toy
{
public:
	virtual void makeSound() = 0;
};

class PlushToy : public Toy 
{
public:
	void makeSound() 
	{
		std::cout << "Talk" << std::endl;
	}
};

class Adapter : PlushToy
{
	std::shared_ptr<Animal> bear;

public:
	Adapter(std::shared_ptr<Animal> _bear) :
		bear(_bear)
	{}
	void makeSound()
	{
		bear->makeNoise();
	}
};

