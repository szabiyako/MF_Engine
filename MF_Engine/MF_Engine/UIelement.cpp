#include "UIelement.h"



UIelement::UIelement()
{
}


UIelement::~UIelement()
{
}

void UIelement::render(sf::RenderTarget & window, sf::RenderStates states) const
{
	this->draw(window, states);
}
