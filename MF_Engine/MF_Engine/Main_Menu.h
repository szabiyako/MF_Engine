#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "Scene.h"

#include "UI_ButtonTexture.h"

//
#include "Console.h"

class Main_Menu :
	public Scene
{
private:
	sf::Sprite *background;

	UI::ButtonTexture *button_play;
	UI::ButtonTexture *button_settings;
	UI::ButtonTexture *button_exit;
public:
	void InitTexture();
	void InitBackground();
	void InitButtons();
	Main_Menu(Resource_Manager *resource_manager);
	virtual ~Main_Menu();

	void update(float &dt, int &current_scene, sf::RenderWindow &window);
	void render(sf::RenderTarget &window);
};

#endif