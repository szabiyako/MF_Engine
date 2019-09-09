#include "Level_1.h"



Level_1::Level_1(Resource_Manager * resource_manager) : Scene(resource_manager)
{
	this->text = new sf::Text("", *resource_manager->getFontSystem(), 50);
	this->text->setFillColor(sf::Color::White);
	this->text->setPosition(sf::Vector2f(400.f, 200.f));

	this->list.push_back(L"Назад");
	this->list.push_back(L"1) Один");
	this->list.push_back(L"2) Два");
	this->list.push_back(L"3) Три");
	this->list.push_back(L"4) Четыре");
	this->list.push_back(L"5) Пять");
	this->cm = new UI::ContextMenu(this->list, "resources/fonts/arial.ttf", sf::Vector2f(200.f, 40.f), 30);

	this->button = new UI::ButtonText(this->resource_manager->getFontSystem(), L"Кнопка", { 200.f, 80.f }, 60);
	this->button->setPosition({1080.f, 640.f});
}


Level_1::~Level_1()
{
	delete this->cm;

	delete this->text;
	delete this->font;
}

void Level_1::update(float & dt, int & current_scene, sf::RenderWindow & window)
{
	int cmenu_chose = this->cm->run(window);
	if (cmenu_chose == 0)
	{
		current_scene = 0;
		Console::addLine(L"LOG: Button " + this->list.at(cmenu_chose) + " from ContextMenu has been pressed!");
	}
	else if (cmenu_chose == -1) {}
	else
	{
		this->text->setString(this->list.at(cmenu_chose));
		Console::addLine(L"LOG: Button " + this->list.at(cmenu_chose) + " from ContextMenu has been pressed!");

		auto ptr = this->cm->getList();
		ptr->erase(ptr->begin() + cmenu_chose);
		this->list.erase(this->list.begin() + cmenu_chose);
	}
	if (this->button->isClicked(window))
		Console::addLine(L"LOG: ButtonText has been pressed!");
}

void Level_1::render(sf::RenderTarget & window)
{
	window.draw(*this->text);
	this->button->render(window);
	this->cm->render(window);
}
