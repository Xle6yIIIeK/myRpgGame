#ifndef SETTINGSTATECLASS_H
#define SETTINGSTATECLASS_H

#include "StateClass.h"
class SettingState:
	public State
{
private:
	//variables
	sf::RectangleShape backgoundshape;
	sf::Texture backgroundTexture;
	sf::Font font;

	std::map<std::string, gui::ButtonClass*> button;

	gui::DropList* droplist;

	void initVariables();
	void initKeybinds();
	void initBackground();
	void initStates(StateData* state_data);
	void initButtons();
	void initDropList();

public:

	SettingState(StateData* state_data);
	virtual ~SettingState();
	
	//Functions
	void updateInput(const float& dt);
	void updateButtons();
	void updateDropList(const float& dt);
	void update(const float& dt);
	void renderButtons(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = NULL);
	//Accsesors

};


#endif // !SETTINGSTATECLASS_H
