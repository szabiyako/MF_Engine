#include "Main_Menu.h"



void Main_Menu::InitTexture()
{
	this->resource_manager->setTexture("resources/textures/Main_Menu.png");
}

void Main_Menu::InitBackground()
{
	this->background = new sf::Sprite();
	this->background->setTexture(*this->resource_manager->getTexture());
	this->background->setTextureRect(sf::IntRect(0, 0, 1280, 720));
	this->background->setPosition(0.f, 0.f);
}

void Main_Menu::InitButtons()
{
	this->button_play = new UI::ButtonTexture(this->resource_manager->getTexture(), sf::IntRect(1280, 0, 370, 60), sf::IntRect(1280, 60, 370, 60), sf::Vector2f(75.f, 250.f));
	this->button_settings = new UI::ButtonTexture(this->resource_manager->getTexture(), sf::IntRect(1280, 120, 370, 60), sf::IntRect(1280, 180, 370, 60), sf::Vector2f(75.f, 350.f));
	this->button_exit = new UI::ButtonTexture(this->resource_manager->getTexture(), sf::IntRect(1280, 240, 370, 60), sf::IntRect(1280, 300, 370, 60), sf::Vector2f(75.f, 450.f));
}


Main_Menu::Main_Menu(Resource_Manager * resource_manager) : Scene(resource_manager)
{
	this->InitTexture();
	this->InitBackground();
	this->InitButtons();

	for (int i = 0; i < 20; i++)
		Console::addLine(L"For testing numder " + std::to_wstring(i));
	std::wstring str;

	for (int i = 10; i < 150; i++)
		str += std::to_wstring(i) + L", ";
	str += std::to_wstring(150);
	Console::addLine(str);

}


Main_Menu::~Main_Menu()
{
	delete this->background;

	delete this->button_play;
	delete this->button_settings;
	delete this->button_exit;
}

void Main_Menu::update(float & dt, int &current_scene, sf::RenderWindow &window)
{
	if (this->button_play->isClicked(window))
	{
		Console::addLine(L"LOG: Button PLAY has been pressed!");
		current_scene++;
	}

	if (this->button_settings->isClicked(window))
	{
		this->button_settings->setOrigin({185.f, 25.f});
		this->button_settings->setPosition({185.f + 75.f, 25.f + 350.f});
		//this->button_settings->scale(sf::Vector2f(1.1, 1.1));
		this->button_settings->rotate(10.f);
		Console::addLine(L"LOG: Button SETTINGS has been pressed!");
	}

	if (this->button_exit->isClicked(window))
		current_scene--;
}

void Main_Menu::render(sf::RenderTarget & window)
{
	window.draw(*this->background);
	this->button_play->render(window);
	this->button_settings->render(window);
	this->button_exit->render(window);
}
