#include "ButtonClass.h"

ButtonClass::ButtonClass(
	float x, float y, float width, float heigth,
	sf::Font* font, std::string text,
	unsigned character_size,
	sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
	sf::Color idle_Color, sf::Color hover_color, sf::Color active_color)
{
	this->buttonstate = BUTTONT_IDLE;

	this->btnshape.setPosition(sf::Vector2f(x, y));
	this->btnshape.setSize(sf::Vector2f(width, heigth));

	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setCharacterSize(character_size);

	this->btnshape.setFillColor(idle_Color);
	this->text.setFillColor(idle_Color);

	this->text.setPosition(
		this->btnshape.getPosition().x + (this->btnshape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->btnshape.getPosition().y + (this->btnshape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 1.5f
		);

	this->textIdleColor = text_idle_color;
	this->textHoverColor = text_hover_color;
	this->textActiveColor = text_active_color;

	this->idleColor = idle_Color;
	this->hoverColor = hover_color;
	this->activeColor = active_color;

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
		this->text.setFillColor(this->textIdleColor);
		break;
	case BUTTONT_HOVER:
		this->btnshape.setFillColor(this->hoverColor);
		this->text.setFillColor(this->textHoverColor);
		break;
	case BUTTON_ACTIVE:
		this->btnshape.setFillColor(this->activeColor);
		this->text.setFillColor(this->textActiveColor);
		break;
	default:
		this->btnshape.setFillColor(sf::Color::Red);
		this->text.setFillColor(sf::Color::Green);
		break;
	}
}

void ButtonClass::render(sf::RenderTarget& target)
{
	target.draw(this->btnshape);
	target.draw(this->text);
}
