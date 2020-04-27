#include "PlayerClass.h"
//Initializer functions
void PlayerClass::initVariables()
{

}

void PlayerClass::initComponents()
{
}

//Constructors / Destructors
PlayerClass::PlayerClass(float x, float y, sf::Texture& texture_sheet)
{
	this->setPosition(x, y);

	this->createMovementComponent(300.f, 20.f, 5.f);
	this->createAnimationComponent(texture_sheet);

	this->anmationcomponent->addAnimation("IDLE", 10.f, 0, 0, 5, 0, 48, 48);
	this->anmationcomponent->addAnimation("WALK", 10.f, 0, 1, 5, 1, 48, 48);
}

PlayerClass::~PlayerClass()
{

}
//Functions
void PlayerClass::update(const float& dt)
{
	if (this->movementcomponent)
		this->movementcomponent->update(dt);

	if(this->movementcomponent->getState(IDLE))
		this->anmationcomponent->play("IDLE", dt);
	else if(this->movementcomponent->getState(MOVELEFT))
		this->anmationcomponent->play("WALK", dt);

}
