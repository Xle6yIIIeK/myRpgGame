#ifndef BUTTONCLASS_H
#define BUTTONCLASS_H
#include "stdafx.h"
enum buttonState { BUTTONT_IDLE = 0, BUTTONT_HOVER, BUTTON_ACTIVE };

class ButtonClass
{
private:
	short unsigned buttonstate;

	sf::RectangleShape btnshape;
	sf::Font* font;
	sf::Text text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;


public:
	ButtonClass(
		float x, float y,
		float width, float heigth,
		sf::Font* font, std::string text,
		sf::Color idleColor,
		sf::Color hoverColor,
		sf::Color activeColor);

	virtual ~ButtonClass();

	//Accses
	const bool isPressed() const;

	//func
	void update(const sf::Vector2f mousepos);
	void render(sf::RenderTarget* targer);
};


#endif // !BUTTONCLASS_H