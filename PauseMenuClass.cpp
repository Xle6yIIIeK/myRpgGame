#include "PauseMenuClass.h"

void PauseMenuClass::createButton() 
	
{
	this->buttons["BACK_TO_GAME"] = new ButtonClass( 
		this->container.getSize().x /2,			 
		this->container.getPosition().y/8,		  
		120, 50,									
		this->Font, "New Game",					
		23,										 
		sf::Color(180, 180, 180),			
		sf::Color(220, 220, 220),				
		sf::Color(200, 200, 200),				
		sf::Color(80, 80, 80),				  
		sf::Color(100, 100, 100),			  
		sf::Color(70, 70, 70)				
		);	 
		
}

PauseMenuClass::PauseMenuClass(sf::RenderWindow& window, sf::Font& font)
	:Font(font)
{
	this->background.setSize(
		sf::Vector2f(
			static_cast<float>(window.getSize().x),
			static_cast<float>(window.getSize().y)
			)
		);

	this->background.setFillColor(sf::Color(20, 20, 20, 100));

	this->container.setSize(
		sf::Vector2f(
			static_cast<float>(window.getSize().x) / 4.f,
			static_cast<float>(window.getSize().y)		 -100.f
			)
		);

	this->container.setFillColor(sf::Color(20, 20, 20, 200));
	this->container.setPosition(
		static_cast<float>(window.getSize().x)
		/ 2.f - this->container.getSize().x / 2.f,
		0.f);

	this->menuText.setFont(this->Font);
	this->menuText.setFillColor(sf::Color(255, 255, 255, 200));
	this->menuText.setCharacterSize(50);
	this->menuText.setString("PAUSE");
	this->menuText.setPosition(this->container.getPosition());
	this->createButton();
}

PauseMenuClass::~PauseMenuClass()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

	 //functions
void PauseMenuClass::update()
{

}

void PauseMenuClass::render(sf::RenderTarget& target)
{
	target.draw(background);
	target.draw(container);

	for (auto& i : this->buttons)
	{
		i.second->render(target);
	}
	target.draw(this->menuText);
}
