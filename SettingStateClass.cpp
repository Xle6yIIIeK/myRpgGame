#include "SettingStateClass.h"

void SettingState::initVariables()
{

}

void SettingState::initKeybinds()
{
	std::fstream ifs("Config/KeyBoard_game.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";
		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}

	ifs.close();
}

void SettingState::initBackground()
{
	this->backgoundshape.setSize(
		sf::Vector2f(
			this->window->getSize().x,
			this->window->getSize().y
			)
		);

	if (!this->backgroundTexture.loadFromFile("Resourses/images/backGround.png"))
	{
		throw "ERROR::SettingState::initBackground Resourses/images/backGround.png Can`t do load";
	}

	this->backgoundshape.setTexture(&this->backgroundTexture);
}

void SettingState::initStates(StateData* state_data)
{
	this->window = state_data->window;
	this->supportedKeys = state_data->supportedKeys;
	this->states = state_data->states;
	this->quit = false;
	this->paused = false;
	this->keytime = 0.f;
	this->keytimeMax = 10.f;
	this->gridSize = state_data->gridSize;
	this->font = state_data->GlobalFont;
}

void SettingState::initButtons()
{
	this->button["EXIT_BUTTON"] = new gui::ButtonClass(
		sf::Vector2f(
			this->window->getSize().x - 120.f,
			this->window->getSize().y - 50.f),
		sf::Vector2f(120, 50),
		&this->font, "Exit", 30,
		sf::Color(180, 180, 180), sf::Color(220, 220, 220), sf::Color(200, 200, 200),
		sf::Color(80, 80, 80), sf::Color(100, 100, 100), sf::Color(70, 70, 70)
		);
}

void SettingState::initDropList()
{
	std::string list[] = { "0", "1", "2", "3", "4", "4", "4", "4" };

	this->droplist = new gui::DropList(
		sf::Vector2f(0, 0), sf::Vector2f(250, 30),
		this->font, list, _countof(list)
		);
	
}

SettingState::SettingState(StateData* state_data):
	State(state_data)
{
	this->initVariables();
	this->initKeybinds();
	this->initBackground();
	this->initStates(state_data);
	this->initButtons();
	this->initDropList();
}

SettingState::~SettingState()
{
	auto it = this->button.begin();
	for (it = this->button.begin(); it != this->button.end(); ++it)
	{
		delete it->second;
	}

	delete this->droplist;
}

//Functions
void SettingState::updateInput(const float& dt)
{

}

void SettingState::updateButtons()
{
	for (auto& it : this->button)
	{
		it.second->update(this->mousePosView);
	}

	if (this->button["EXIT_BUTTON"]->isPressed())
	{
		this->endState();
	}
}

void SettingState::updateDropList(const float& dt)
{
	this->droplist->update(this->mousePosView,dt);
}

void SettingState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	this->updateButtons();
	this->updateDropList(dt); 
}

void SettingState::renderButtons(sf::RenderTarget& target)
{
	for (auto& it : this->button)
	{
		it.second->render(target);
	}
}

void SettingState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->stateData->window;

	target->draw(this->backgoundshape);
	this->renderButtons(*target);

	this->droplist->render(*target);
}

//Accsesors