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
}

void EntityClass::createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration)
{
	this->movementcomponent = new MovementComponent(this->sprite, maxVelocity, acceleration, deceleration);
}

void EntityClass::setTexture(sf::Texture& texture)
{
	this->texture = &texture;

	this->sprite.setTexture(texture);
	this->sprite.scale(0.4f, 0.4f);
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
	if (this->movementcomponent)
		this->movementcomponent->update(dt);
}

void EntityClass::render(sf::RenderTarget* target)
{
		target->draw(this->sprite);
}
						     