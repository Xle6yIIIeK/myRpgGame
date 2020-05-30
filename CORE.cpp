#include "CORE.h"
#include "stdafx.h"
void CORE::initVariables()
{
	this->window = NULL;
	this->dt = 0.f;
	this->gridSize = 64.f;
}

void CORE::initWindow()
{
	if (this->setting.fullscreen)
	{
		this->window = new sf::RenderWindow(
			this->setting.resolution,
			this->setting.title,
			sf::Style::Fullscreen,
			this->setting.contextSettings);
	}
	else
	{
		this->window = new sf::RenderWindow(
			this->setting.resolution,
			this->setting.title,
			sf::Style::Titlebar|sf::Style::Close,
			this->setting.contextSettings);
	}

	this->window->setFramerateLimit(this->setting.frameRateLimit);
	this->window->setVerticalSyncEnabled(this->setting.verticalSync);
}

void CORE::initGraphics()
{
	this->setting.loadFromFile("Config/setting.ini");
}

void CORE::initKeys()
{
	std::fstream ifs("Config/KeyBoard.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		int keyValue = 0;
		while (ifs >> key >> keyValue)
		{
			this->supportedKeys[key] = keyValue;
		}
	}
	ifs.close();
}

void CORE::initStateData()
{
	this->stateData.window = this->window;
	this->stateData.settings = &this->setting;
	this->stateData.gridSize = this->gridSize;
	this->stateData.supportedKeys = &this->supportedKeys;
	this->stateData.states = &this->states;
}

void CORE::initState()
{
	this->states.push(new MainMenuClass(&this->stateData));
}

CORE::CORE()
{
	this->initVariables();
	this->initGraphics();
	this->initWindow();
	this->initKeys();
	this->initStateData();
	this->initState();
}

CORE::~CORE()
{
	delete this->window;
}

void CORE::endApplication()
{
	std::cout << "Ending Application!" << "\n";
}

void CORE::updateTime()
{
	this->dt = this->clock.restart().asSeconds();
	std::cout << this->dt <<"\n";
}

void CORE::updateSFML()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
						 
	}
}				  

void CORE::update()
{
	this->updateSFML();

	if (!this->states.empty())
	{
		if (this->window->hasFocus())
		{
			this->states.top()->update(this->dt);

			if (this->states.top()->getQuit())
			{
				this->states.top()->endState();
				delete this->states.top();
				this->states.pop();
			}
		}
	}
	//Application end
	else
	{
		this->endApplication();
		this->window->close();
	}
}

void CORE::render()
{
	this->window->clear();
	if (!this->states.empty())
	{
		this->states.top()->render();
	}
	
	this->window->display();
}

void CORE::run()
{
	while (this->window->isOpen())
	{
		this->updateTime();
		this->update();
		this->render();
	}
}


										 