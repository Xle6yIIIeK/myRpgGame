#include "GUI.h"

gui::ButtonClass::ButtonClass(
	sf::Vector2f pos, sf::Vector2f size,
	sf::Font* font, std::string text, unsigned character_size,
	sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
	sf::Color idle_Color, sf::Color hover_color, sf::Color active_color)
{
	this->buttonstate = BUTTONT_IDLE;

	this->btnshape.setPosition(sf::Vector2f(pos));
	this->btnshape.setSize(sf::Vector2f(size));

	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setCharacterSize(character_size);

	this->btnshape.setFillColor(idle_Color);
	this->text.setFillColor(idle_Color);

	this->text.setPosition(
		this->btnshape.getPosition().x + (this->btnshape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->btnshape.getPosition().y	 
		);

	this->textIdleColor = text_idle_color;
	this->textHoverColor = text_hover_color;
	this->textActiveColor = text_active_color;

	this->idleColor = idle_Color;
	this->hoverColor = hover_color;
	this->activeColor = active_color;
}

gui::ButtonClass::~ButtonClass()
{

}

const std::string& gui::ButtonClass::getText() const
{
	return this->text.getString();
}

const bool gui::ButtonClass::isPressed() const
{
	if (this->buttonstate == BUTTON_ACTIVE)
		return true;

	return false;
}

//Modefires
void gui::ButtonClass::setText(std::string textButton)
{
	this->text.setString(textButton);
}

void gui::ButtonClass::update(const sf::Vector2f& mousepos)
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

void gui::ButtonClass::render(sf::RenderTarget& target)
{
	target.draw(this->btnshape);
	target.draw(this->text);
}

gui::DropList::DropList(sf::Vector2f pos, sf::Vector2f size, sf::Font& font, std::string list[], unsigned numElement, unsigned defauld_index)
	:dlFont(font), showList(false),KeyTimeMax(2.f),keyTime(0.f)
{
	for (size_t it = 0; it < numElement; it++)
	{
		this->list.push_back(
			new gui::ButtonClass(
				sf::Vector2f(
					sf::Vector2f(pos).x,
					sf::Vector2f(pos).y +( it * sf::Vector2f(size).y)
					),
				sf::Vector2f(size),
				&this->dlFont, list[it], 30,
				sf::Color(180, 180, 180), sf::Color(220, 220, 220), sf::Color(200, 200, 200),
				sf::Color(80, 80, 80), sf::Color(100, 100, 100), sf::Color(70, 70, 70)
				)
			);
	}

	activeElement = new ButtonClass(*this->list[defauld_index]);
}

gui::DropList::~DropList()
{
	delete this->activeElement;
	for(auto *&it:this->list)
	{
		delete it;
	}
}

const bool gui::DropList::getKeyTime()
{
	if (this->keyTime >= KeyTimeMax)
	{
		this->keyTime = 0.f;
		return true;
	}
	return true;
}

void gui::DropList::updateKeyTime(const float &dt)
{
	if (this->keyTime < this->KeyTimeMax)
	{
		this->keyTime =this->keyTime+ 10.f * dt;
	}
}

void gui::DropList::update(const sf::Vector2f& mousepos, const float& dt)
{
	this->updateKeyTime(dt);

	this->activeElement->update(mousepos);

	if (this->activeElement->isPressed()&&this->getKeyTime())
	{
		if (this->showList)
			this->showList = false;
		else
			this->showList = true;
	}

	if (this->showList)
	{
		for (auto& it : this->list)
		{
			it->update(mousepos);
		}
	};
}

void gui::DropList::render(sf::RenderTarget& targer)
{
	activeElement->render(targer);

	if (this->showList)
	{
		for (auto& it : this->list)
		{
			it->render(targer);
		}
	};
}
