#include "ButtonClass.h"

ButtonClass::ButtonClass(
	float x, float y, float width, float heigth,
	sf::Font* font, std::string text,
	sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
	this->buttonstate = BUTTONT_IDLE;
	this->btnshape.setPosition(sf::Vector2f(x, y));
	this->btnshape.setSize(sf::Vector2f(width, heigth));
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(20);
	this->text.setPosition(
		this->btnshape.getPosition().x + (this->btnshape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->btnshape.getPosition().y
		);

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;
	this->btnshape.setFillColor(this->idleColor);

}

ButtonClass::~ButtonClass()
{

}

const bool ButtonClass::isPressed() const
{
	if (this->buttonstate == BUTTON_ACTIVE)
	{
		return true;
	}

	return false;

}

void ButtonClass::update(const sf::Vector2f mousepos)
{
	this->isPressed();

	this->buttonstate = BUTTONT_IDLE;

	if (this->btnshape.getGlobalBounds().contains(mousepos))
	{
		this->buttonstate = BUTTONT_HOVER;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonstate = BUTTON_ACTIVE;
		}
	}

	switch (this->buttonstate)
	{
	case BUTTONT_IDLE:
		this->btnshape.setFillColor(this->idleColor);
		break;
	case BUTTONT_HOVER:
		this->btnshape.setFillColor(this->hoverColor);
		break;
	case BUTTON_ACTIVE:
		this->btnshape.setFillColor(this->activeColor);
		break;
	default:
		this->btnshape.setFillColor(sf::Color::Red);
		break;
	}
}

void ButtonClass::render(sf::RenderTarget* target)
{
	target->draw(this->btnshape);
	target->draw(this->text);
}
