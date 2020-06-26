#ifndef GRAPHICAL_USER_INTERFACE_H
#define GRAPHICAL_USER_INTERFACE_H
#include "stdafx.h"
enum buttonState { BUTTONT_IDLE = 0, BUTTONT_HOVER, BUTTON_ACTIVE };

namespace gui
{
	class ButtonClass
	{
	private:
		short unsigned buttonstate;

		sf::RectangleShape btnshape;
		sf::Font* font;
		sf::Text text;

		sf::Color textIdleColor, textHoverColor, textActiveColor;
		sf::Color idleColor, hoverColor, activeColor;

	public:
		ButtonClass(
			sf::Vector2f pos, sf::Vector2f size,
			sf::Font* font, std::string text, unsigned character_size,
			sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
			sf::Color idle_Color, sf::Color hover_color, sf::Color active_color);

		virtual ~ButtonClass();

		//Accses
		const bool isPressed() const;
		const std::string& getText() const;

		//modifires
		void setText(std::string textButton);
						 
		//func
		void update(const sf::Vector2f& mousepos);
		void render(sf::RenderTarget& targer);
	};

	class DropList
	{
	private:
		float keyTime, KeyTimeMax;
		sf::Font& dlFont;
		ButtonClass* activeElement;
		std::vector<gui::ButtonClass*> list;
		bool showList;

	public:
		DropList(sf::Vector2f pos,sf::Vector2f size,
			sf::Font& dlfont, std::string list[],
			unsigned numElement, unsigned defauld_index=0);

		virtual ~DropList();
		
		const bool getKeyTime();
		void updateKeyTime(const float& dt);
		void update(const sf::Vector2f& mousepos, const float& dt);
		void render(sf::RenderTarget& targer);
	};


};

#endif // !GRAPHICAL_USER_INTERFACE_H