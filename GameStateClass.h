#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "StateClass.h"
#include "EntityClass.h"
#include "TileMap.h"
class GameState :
	public State
{
private:
	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	EntityClass* p;

	Level testlvl;

	void initKeybinds();
	void initLevel();
public:
	GameState(StateData* state_data);
	virtual ~GameState();

	void updateMousePositions(sf::View* view);
	void updateKeytime(const float& dt);
	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target);

};
#endif	