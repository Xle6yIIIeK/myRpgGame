#include "MainMenuClass.h"
#include "GameStateClass.h"
#include "EditorStateClass.h"

void MainMenuClass::initVariables()
{
}

void MainMenuClass::initKeybinds()
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

void MainMenuClass::initFonts()
{

	if (!this->font.loadFromFile("Resourses/Fonts/lunchds.ttf"))
	{
		throw("ERROR::MAINMENUCLASS::INITFONTS font not find");
	}
}

void MainMenuClass::initBackground()
{
	this->backgoundshape.setSize(
		sf::Vector2f(
			this->window->getSize().x,
			this->window->getSize().y
			)
		);

	if (!this->backgroundTexture.loadFromFile("Resourses/images/backGround.png"))
	{
		throw "ERROR::MainMenuClass::initBackground Resourses/images/backGround.png Can`t do load";
	}
	this->backgoundshape.setTexture(&this->backgroundTexture);
}

void MainMenuClass::initStates(StateData* state_data)
{
	this->stateData = state_data;
	this->window = state_data->window;
	this->supportedKeys = state_data->supportedKeys;
	this->states = state_data->states;
	this->quit = false;
	this->paused = false;
	this->keytime = 0.f;
	this->keytimeMax = 10.f;
	this->gridSize = state_data->gridSize;
}

void MainMenuClass::initButtons()
{
	this->button["GAME_STATE_BUTTON"] = new ButtonClass(//typename[""] Button
		this->window->getSize().x - 120,			   //Pos x
		this->window->getSize().y - 200,			  //Pos Y
		120, 50,									 //width heigth
		&this->font, "New Game",					//Font & Text in button	
		23,										   //character size text
		sf::Color(180, 180, 180),				  //TEXT_IDLE_COLOR
		sf::Color(220, 220, 220),				 //TEXT_HOVER_COLOR
		sf::Color(200, 200, 200),				//TEXT_ACTIVE_COLOR
		sf::Color(80, 80, 80),				   //IDLE_COLOR
		sf::Color(100, 100, 100),			  //HOVER_COLOR
		sf::Color(70, 70, 70)				 //ACTIVE_COLOR
		);

	this->button["EDITOR_BUTTON"] = new ButtonClass(    //typename[""] Button
		this->window->getSize().x - 120,			   //Pos x					
		this->window->getSize().y - 150,			  //Pos Y
		120, 50,									 //width heigth
		&this->font, "Editor",						//Font & Text in button	
		23,										   //character size text
		sf::Color(180, 180, 180),				  //TEXT_IDLE_COLOR
		sf::Color(220, 220, 220),				 //TEXT_HOVER_COLOR
		sf::Color(200, 200, 200),				//TEXT_ACTIVE_COLOR
		sf::Color(80, 80, 80),				   //IDLE_COLOR
		sf::Color(100, 100, 100),			  //HOVER_COLOR
		sf::Color(70, 70, 70)				 //ACTIVE_COLOR
		);

	this->button["EXIT_BUTTON"] = new ButtonClass(		//typename[""] Button
		this->window->getSize().x - 120,			   //Pos x					
		this->window->getSize().y - 50,				  //Pos Y
		120, 50,									 //width heigth
		&this->font, "Exit",						//Font & Text in button	
		23,										   //character size text
		sf::Color(180, 180, 180),				  //TEXT_IDLE_COLOR
		sf::Color(220, 220, 220),				 //TEXT_HOVER_COLOR
		sf::Color(200, 200, 200),				//TEXT_ACTIVE_COLOR
		sf::Color(80, 80, 80),				   //IDLE_COLOR
		sf::Color(100, 100, 100),			  //HOVER_COLOR
		sf::Color(70, 70, 70)				 //ACTIVE_COLOR					 
		);
}

void MainMenuClass::initMusic()
{
	this->music.openFromFile("Resourses/Music/mainmenumusic.flac");
	this->music.play();
	this->music.setVolume(10);
}

MainMenuClass::MainMenuClass(StateData* state_data)
	:State(state_data)
{
	this->initVariables();
	this->initKeybinds();
	this->initFonts();
	this->initBackground();
	this->initStates(state_data);
	this->initButtons();
	this->initMusic();
}

MainMenuClass::~MainMenuClass()
{
	auto it = this->button.begin();
	for (it = this->button.begin(); it != this->button.end(); ++it)
	{
		delete it->second;
	}
}

void MainMenuClass::updateInput(const float& dt)
{
	this->getQuit();
	
}

void MainMenuClass::updateButtons()
{
	for (auto& it : this->button)
	{
		it.second->update(this->mousePosView);
	}
}

void MainMenuClass::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	this->playMusic();
	this->updateButtons();

	if (this->button["EXIT_BUTTON"]->isPressed())
	{
		this->quit = true;
	}
	if (this->button["GAME_STATE_BUTTON"]->isPressed())
	{
		this->states->push(new GameState(this->stateData));
	}
	if (this->button["EDITOR_BUTTON"]->isPressed())
	{
		this->states->push(new EditorStateClass(this->stateData));
	}
}

void MainMenuClass::playMusic()
{
	
}

void MainMenuClass::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->button)
	{
		it.second->render(target);
	}
}

void MainMenuClass::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->backgoundshape);
	this->renderButtons(target);
}
