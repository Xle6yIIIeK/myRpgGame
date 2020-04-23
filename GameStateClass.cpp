#include "GameStateClass.h"

void GameState::initKeybinds()
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

void GameState::initLevel()
{
	this->testlvl.LoadFromFile("Resourses/maps/qq.tmx");
}

GameState::GameState(StateData* state_data)
	:State(state_data)
{
	this->window = state_data->window;
	this->supportedKeys = state_data->supportedKeys;
	this->gridSize = state_data->gridSize;
	
	this->initKeybinds();
	this->initLevel();
	this->p = new EntityClass();

}

GameState::~GameState()
{
	delete this->p;
}

void GameState::updateMousePositions(sf::View* view)
{

}

void GameState::updateKeytime(const float& dt)
{

}

void GameState::updateInput(const float& dt)
{

	//Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
		this->p->movement(dt, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->p->movement(dt, 0.f, 1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->p->movement(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->p->movement(dt, -1.f, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
		this->endState();
}

void GameState::update(const float &time)
{
	this->updateInput(time);
	this->updateKeytime(time);
	this->p->update(time);
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	this->testlvl.Draw(target);

	this->p->render(target);
}