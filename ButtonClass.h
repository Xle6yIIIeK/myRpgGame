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

	sf::Color textIdleColor;
	sf::Color textHoverColor;
	sf::Color textActiveColor;
		
	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;


public:
	ButtonClass(
		float x, float y,
		float width, float heigth,

		sf::Font* font, std::string text,
		unsigned character_size,

		sf::Color text_idle_color, 
		sf::Color text_hover_color, 
		sf::Color text_active_color,

		sf::Color idle_Color,
		sf::Color hover_color,
		sf::Color active_color);

	virtual ~ButtonClass();

	//Accses
	const bool isPressed() const;

	//func
	void update(const sf::Vector2f mousepos);
	void render(sf::RenderTarget* targer);
};


#endif // !BUTTONCLASS_H