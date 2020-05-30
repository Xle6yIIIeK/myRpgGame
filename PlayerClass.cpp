#include "PlayerClass.h"
//Initializer functions
void PlayerClass::initVariables()
{
	this->attack = false;
}

void PlayerClass::initComponents()
{
}

//Constructors / Destructors
PlayerClass::PlayerClass(float x, float y, sf::Texture& texture_sheet)
{
	this->setPosition(x, y);

	this->createHitBoxComponent(this->sprite, 0, 0, 64, 64);
	this->createMovementComponent(300.f, 20.f, 5.f);
	this->createAnimationComponent(texture_sheet);

	this->anmationcomponent->addAnimation("IDLE", 20.f, 0, 0, 0, 0, 152, 197);
	this->anmationcomponent->addAnimation("WALK", 10.f, 0, 0, 5, 0, 64, 64);
	this->anmationcomponent->addAnimation("ATTACK", 10.f, 0, 1, 15, 1, 32, 32);
}

PlayerClass::~PlayerClass()
{

}
//Functions
void PlayerClass::updateAttack()
{

}

void PlayerClass::updateAnimation(const float& dt)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->attack = true;
	}
	if (this->attack)
	{
		//check origin on direction
		if (this->sprite.getScale().x > 0.f)
		{
			this->sprite.setOrigin(0, 0);
		}
		else
		{

		}
		if (this->anmationcomponent->play("ATTACK", dt, true))
			this->attack = false;
	}
	if (this->movementcomponent->getState(IDLE))
	{
		this->sprite.setOrigin(0, 0);
		this->sprite.setScale(0.8f, 0.8f);
		this->anmationcomponent->play("IDLE", dt, 0);
	}
	else if (this->movementcomponent->getState(MOVELEFT))
	{
		if (this->sprite.getScale().x < 0.f)
		{
			this->sprite.setOrigin(0, 0);
			this->sprite.setScale(0.8f, 0.8f);
		}
		this->anmationcomponent->play("WALK", dt,
			this->movementcomponent->getVelocity().x
			, this->movementcomponent->getMaxVelocity(), 0);
	}
	else if (this->movementcomponent->getState(MOVERIGHT))
	{
		if (this->sprite.getScale().x > 0.f)
		{
			this->sprite.setOrigin(32, 0);
			this->sprite.setScale(-0.8f, 0.8f);
		};
		this->anmationcomponent->play("WALK", dt, 0);
	}
	else if (this->movementcomponent->getState(MOVEUP))
	{

	}
	else if (this->movementcomponent->getState(MOVEDOWN))
	{

	}
}

void PlayerClass::update(const float& dt)
{
	this->movementcomponent->update(dt);
	this->updateAttack();
	this->updateAnimation(dt);


	this->hitboxcomponent->update();
}
