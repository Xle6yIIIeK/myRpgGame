#include "EntityClass.h"

void EntityClass::initVariables()
{
	this->movementSpeed = 100.f;
	this->sprite = NULL;
	this->texture = NULL;
}

EntityClass::EntityClass()
{
	this->texture = new sf::Texture();
	this->texture->loadFromFile("Resourses/images/player.png");

		
}

EntityClass::~EntityClass()
{
	delete this->sprite;
}

void EntityClass::createSprite(sf::Texture* texture)
{
	//this->texture = texture;
	this->sprite->setTexture(*this->texture);
	this->sprite->setScale(2,2);
}

void EntityClass::movement(const float& dt, const float dir_x, const float dir_y)
{
	if (this->sprite)
	{
	this->sprite->move(dir_x * this->movementSpeed *dt, dir_y * this->movementSpeed *dt);
	}
}

void EntityClass::update(const float& dt)
{
	
};

void EntityClass::render(sf::RenderTarget* target)
{
	if (this->sprite)
	{
		target->draw(*this->sprite);
	}
}
						     