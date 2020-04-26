#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H

#include "EntityClass.h"
class PlayerClass :
	public EntityClass
{
private:
	//variables


	//init Functions
	void initVariables();
	void initComponents();

public:
	//CONST - DEST
	PlayerClass(float x, float y, sf::Texture& texture_sheet);
	virtual ~PlayerClass();

	//Functions
	virtual void update(const float& dt);
};
#endif // !PLAYERCLASS_H