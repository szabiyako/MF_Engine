#ifndef LEVEL_1
#define LEVEL_1

#include "Scene.h"
#include "Player.h"

#include "Console.h"

#include "UI_ContextMenu.h"
#include "UI_ButtonText.h"

class Level_1 :
	public Scene
{
private:
	std::vector<sf::String> list;
	sf::Font *font;
	sf::Text *text;

	UI::ContextMenu *cm;
	UI::ButtonText *button;
public:
	Level_1(Resource_Manager *resource_manager);
	virtual ~Level_1();

	void update(float &dt, int &current_scene, sf::RenderWindow &window);
	void render(sf::RenderTarget &window);
};

#endif

