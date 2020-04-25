#ifndef ENTITYCLASS_H
#define ENTITYCLASS_H
#include "MovementComponents.h"

class MovementComponent;

class EntityClass
{
private:
	void initVariables();

protected:
	sf::Texture* texture;
	sf::Sprite sprite;
		  
	MovementComponent* movementcomponent;

public:
	//CONST - DEST
	EntityClass();
	virtual ~EntityClass();

	void setTexture(sf::Texture& texture);
	void createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration);


	//funct
	virtual void setPosition(const float x, const float y);
	virtual void move(const float dir_x, const float dir_y, const float& dt);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);
};


#endif // !ENTITYCLASS_H