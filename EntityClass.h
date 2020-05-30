#ifndef ENTITYCLASS_H
#define ENTITYCLASS_H

#include "MovementComponents.h"
#include "AnimatioComponent.h"
#include "HitBoxComponent.h"
class MovementComponent;

class EntityClass
{
private:
	void initVariables();

protected:

	sf::Sprite sprite;
		  
	HitBoxComponent* hitboxcomponent;
	AnimationComponent* anmationcomponent;
	MovementComponent* movementcomponent;
public:
	//CONST - DEST
	EntityClass();
	virtual ~EntityClass();

	void setTexture(sf::Texture& texture);
	void createHitBoxComponent(sf::Sprite& sprite,
		float offset_x, float offset_y,
		float width, float height);


	//Create Movement component
	//Max speed plyer, acceleration, deceleration
	void createMovementComponent(const float maxSpeed, const float acceleration, const float deceleration);
	void createAnimationComponent(sf::Texture& texture_sheet);


	//funct
	virtual void setPosition(const float x, const float y);
	virtual void move(const float dir_x, const float dir_y, const float& dt);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget& target);
};


#endif // !ENTITYCLASS_H