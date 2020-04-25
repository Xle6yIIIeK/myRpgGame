#include "PlayerClass.h"
//Initializer functions
void PlayerClass::initVariables()
{

}

void PlayerClass::initComponents()
{
	this->createMovementComponent(300.f, 20.f, 5.f);
}

//Constructors / Destructors
PlayerClass::PlayerClass(float x, float y, sf::Texture& texture)
{
	this->initVariables();
	this->initComponents();

	this->setTexture(texture);
	this->setPosition(x, y);
}

PlayerClass::~PlayerClass()
{

}

