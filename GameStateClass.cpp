#include "GameStateClass.h"

void GameState::initVariavles()
{

}

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

void GameState::initTexture()
{
	this->textures["sheet"].loadFromFile("Resourses/images/pal0.png");
}

void GameState::initPlayer()
{
	this->player = new PlayerClass(0, 0, this->textures["sheet"]);
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
							
	this->initVariavles();
	this->initKeybinds();
	this->initLevel();
	this->initTexture();
	this->initPlayer();
}

GameState::~GameState()
{
	delete this->player;
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
		this->player->move(0.f, -1.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->player->move(0.f, 1.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player->move(1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player->move(-1.f, 0.f, dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
		this->endState();
}

void GameState::update(const float &dt)
{
	this->updateInput(dt);
	this->updateKeytime(dt);

	this->player->update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	this->testlvl.Draw(target);

	this->player->render(target);
}