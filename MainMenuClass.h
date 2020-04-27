#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H
#include "StateClass.h"

class MainMenuClass	   
	:public State
{
private:
	//variables
	sf::RectangleShape backgoundshape;
	sf::Texture backgroundTexture;
	sf::Font font;
	sf::Music music;

	std::map<std::string, ButtonClass*> button;

	void initVariables();
	void initKeybinds();	
	void initFonts();
	void initBackground();
	void initStates(StateData* state_data);
	void initButtons();
	void initMusic();
public:
	MainMenuClass(StateData* state_data);
	virtual ~MainMenuClass();


	void updateInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void playMusic();
	void renderButtons(sf::RenderTarget* target = NULL);
	void render(sf::RenderTarget* target=NULL);

};

#endif MAINMENUSTATE_H