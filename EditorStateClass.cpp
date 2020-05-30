#include "EditorStateClass.h"

void EditorStateClass::initVariables()
{
}

void EditorStateClass::initKeybinds()
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

void EditorStateClass::initFonts()
{

	if (!this->font.loadFromFile("Resourses/Fonts/lunchds.ttf"))
	{
		throw("ERROR::MAINMENUCLASS::INITFONTS font not find");
	}
}

void EditorStateClass::initStates(StateData* state_data)
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

void EditorStateClass::initButtons()
{
	this->button["BACK_BUTTON"] = new ButtonClass(		//typename[""] Button
		this->window->getSize().x - 120,			   //Pos x					
		this->window->getSize().y - 50,				  //Pos Y
		120, 50,									 //width heigth
		&this->font, "Back",						//Font & Text in button	
		23,										   //character size text
		sf::Color(180, 180, 180),				  //TEXT_IDLE_COLOR
		sf::Color(220, 220, 220),				 //TEXT_HOVER_COLOR
		sf::Color(200, 200, 200),				//TEXT_ACTIVE_COLOR
		sf::Color(80, 80, 80),				   //IDLE_COLOR
		sf::Color(100, 100, 100),			  //HOVER_COLOR
		sf::Color(70, 70, 70)				 //ACTIVE_COLOR					 
		);
}

EditorStateClass::EditorStateClass(StateData* state_data)
	:State(state_data)
{
	this->initVariables();
	this->initKeybinds();
	this->initFonts();
	this->initStates(state_data);
	this->initButtons();
}

EditorStateClass::~EditorStateClass()
{
	auto it = this->button.begin();
	for (it = this->button.begin(); it != this->button.end(); ++it)
	{
		delete it->second;
	}
}

void EditorStateClass::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
		this->endState();
}

void EditorStateClass::updateButtons()
{
	for (auto& it : this->button)
	{
		it.second->update(this->mousePosView);
	}
}

void EditorStateClass::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	this->updateButtons();

}


void EditorStateClass::renderButtons(sf::RenderTarget& target)
{
	for (auto &it : this->button)
	{
		it.second->render(target);
	}
}

void EditorStateClass::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	this->renderButtons(*target);
}
