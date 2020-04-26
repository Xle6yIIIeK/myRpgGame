#include "EntityClass.h"

void EntityClass::initVariables()
{
	this->movementcomponent = NULL;
}

EntityClass::EntityClass()
{
	this->initVariables();
}

EntityClass::~EntityClass()
{
	delete this->movementcomponent;
	delete this->anmationcomponent;
}

void EntityClass::createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration)
{
	this->movementcomponent = new MovementComponent(this->sprite, maxVelocity, acceleration, deceleration);
}

void EntityClass::createAnimationComponent(sf::Texture& texture_sheet)
{
	this->anmationcomponent = new AnimatioComponent(this->sprite, texture_sheet);
}

void EntityClass::setTexture(sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}


void EntityClass::setPosition(const float x, const float y)
{
		this->sprite.setPosition(x, y);
}

void EntityClass::move(const float dir_x, const float dir_y, const float& dt)
{
	if (this->movementcomponent)
	{
		this->movementcomponent->move(dir_x, dir_y, dt); //Sets velocity
	}
}

void EntityClass::update(const float& dt)
{

}

void EntityClass::render(sf::RenderTarget* target)
{
		target->draw(this->sprite);
}
						     