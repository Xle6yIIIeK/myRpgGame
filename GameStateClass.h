#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "StateClass.h"
#include "PlayerClass.h"
#include "TileMap.h"
#include "PauseMenuClass.h"
class GameState :
	public State
{
private:
	PauseMenuClass* pMenu;
	std::map<std::string, int>* supportedKeys;
	PlayerClass* player;
	sf::Font gameFont;
	Level testlvl;

	void initVariavles();


	void initKeybinds();
	void initTexture();
	void initPauseMenu();
	void initPlayer();
	void initLevel();
public:
	GameState(StateData* state_data);
	virtual ~GameState();

	void updateInput(const float& dt);
	void updateButtons();
	void updatePlayerInput(const float& dt);
	void update(const float& dt);
																 
	void render(sf::RenderTarget* target);

};
#endif	