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
	PauseMenuClass pMenu;
	std::map<std::string, int>* supportedKeys;
	PlayerClass* player;

	Level testlvl;

	void initVariavles();


	void initKeybinds();
	void initTexture();
	void initPlayer();
	void initLevel();
public:
	GameState(StateData* state_data);
	virtual ~GameState();

	void updateMousePositions(sf::View* view);
	void updateInput(const float& dt);
	void updateKeytime(const float& dt);
	void updatePlayerInput(const float& dt);
	void update(const float& dt);
																 
	void render(sf::RenderTarget* target);

};
#endif	