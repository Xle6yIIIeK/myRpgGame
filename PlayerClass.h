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
	PlayerClass(float x, float y, sf::Texture& texture);
	virtual ~PlayerClass();

	//Functions

};
#endif // !PLAYERCLASS_H