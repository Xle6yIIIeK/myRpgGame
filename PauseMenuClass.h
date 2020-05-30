#ifndef PAUSEMENU_H
#define PAUSEMENU_H
#include "stdafx.h"
#include "ButtonClass.h"

class PauseMenuClass
{
private:
	sf::Font& Font;
	sf::Text menuText;

	sf::RectangleShape background;
	sf::RectangleShape container;

	std::map<std::string, ButtonClass*> buttons;

	void createButton(sf::RenderWindow& window);

public:
	PauseMenuClass(sf::RenderWindow& window, sf::Font& font);
	virtual ~PauseMenuClass();

	void update();
	void updateButton();
	void render(sf::RenderTarget& target);
};


#endif // DEBUG