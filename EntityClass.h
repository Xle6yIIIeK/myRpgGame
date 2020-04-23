#ifndef ENTITYCLASS_H
#define ENTITYCLASS_H
#include"stdafx.h"

class EntityClass
{
private:
	void initVariables();

protected:
	sf::Texture* texture;
	sf::Sprite* sprite;

	float movementSpeed;

public:
	EntityClass();
	virtual ~EntityClass();

	void createSprite(sf::Texture* texture);

	//funct
	virtual void movement(const float& dt,const float x, const float y);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);
};


#endif // !ENTITYCLASS_H