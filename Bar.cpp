#include "Bar.h"
#include <iostream>

Bar::Bar() 
{
	m_font.loadFromFile("fonts//Comic_CAT.otf");
	m_tBackground.loadFromFile("images//bar.png");
	m_sBackround.setTexture(m_tBackground);
	m_sBackround.setPosition(m_position.x, m_position.y);
}

void Bar::addItem(const string& name)
{
	
	m_itemsName.push_back(sf::Text(sf::String::fromUtf8(name.begin(), name.end()), m_font, 20));
	m_itemsName.back().setFillColor(sf::Color::Black);
	m_itemsName.back().setPosition(sf::Vector2f(m_position.x+50, (30 * m_itemsName.size() + 50)));
}

void Bar::update(const string& name)
{
	for (int i = 0; i < m_itemsName.size(); i++)
	{
		if (m_itemsName[i].getString() == sf::String::fromUtf8(name.begin(), name.end()))
			m_itemsName[i].setFillColor(sf::Color::Green);
	}
}

const void Bar::show(sf::RenderWindow& window) const
{
	window.draw(m_sBackround);
	for (int i = 0; i < m_itemsName.size(); i++)
	{
		window.draw(m_itemsName[i]);
	}
}

void Bar::clearItem()
{
	if(!m_itemsName.empty())
		m_itemsName.clear();
}
