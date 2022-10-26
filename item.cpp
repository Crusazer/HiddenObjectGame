#include "Item.h"

Item::Item(const std::string& name, const int rectLeft, const int rectTop, const int rectWidth, const int rectHeight) :
	m_name(name), m_rect(rectLeft, rectTop, rectWidth, rectHeight)
{
}

const std::string& Item::getName() const
{
	return m_name;
}

sf::Vector2i Item::getPostion() const
{
	return sf::Vector2i(m_rect.left, m_rect.top);
}

sf::Vector2i Item::getSize() const
{
	return sf::Vector2i(m_rect.width, m_rect.height);
}

bool Item::contains(const int x, const int y) const
{
	return m_rect.contains(x,y);
}
