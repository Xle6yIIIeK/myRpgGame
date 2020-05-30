#ifndef EDITORSTATECLASS_H
#define EDITORSTATECLASS_H

#include "StateClass.h"
class EditorStateClass :
	public State
{
private:
	//variables
	sf::Font font;

	std::map<std::string, ButtonClass*> button;

	void initVariables();
	void initKeybinds();
	void initFonts();
	void initStates(StateData* state_data);
	void initButtons();
public:
	EditorStateClass(StateData* state_data);
	virtual ~EditorStateClass();


	void updateInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget& target );
	void render(sf::RenderTarget* target = NULL);

};


#endif //EDITORSTATECLASS_H