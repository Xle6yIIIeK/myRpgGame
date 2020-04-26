#ifndef CORE_H
#define CORE_H
#include"MainMenuClass.h"
class CORE
{
private:
	sf::RenderWindow* window;
	GraphicsSettings setting;
	StateData stateData;
	sf::Event sfEvent;
	float gridSize;
	sf::Clock clock;

	float dt;

	std::stack<State*> states;
	std::map<std::string, int> supportedKeys;

	void initVariables();
	void initWindow();
	void initGraphics();
	void initKeys();
	void initStateData();
	void initState();

public:
	CORE();
	virtual ~CORE();

	void endApplication();

	void updateTime();
	void updateSFML();
	void update();
	void render();
	void run();
};
#endif