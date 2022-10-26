#include "level.h"
#include <iostream>

Level::Level()
{
	m_soundBufferWin.loadFromFile("music//win.wav");
	m_soundWin.setBuffer(m_soundBufferWin);
}

void Level::addItem(const std::string& name, const int rectLeft, const int rectTop, const int rectWidth, const int rectHeight)
{
	m_items.push_back(Item(name, rectLeft, rectTop, rectWidth, rectHeight));
}

void Level::clearItem()
{
	if (!m_items.empty())
		m_items.clear();
	m_isComplied = false;
}

void Level::setTextureBackground(const std::string& fileName)
{
	m_textureBackround.loadFromFile("images//background" + fileName + ".jpg");
	m_spriteBackGround.setTexture(m_textureBackround);
}

void Level::update(const sf::Vector2i& mousePosition, std::string& name)
{
	for ( std::list<Item>::const_iterator iter = m_items.begin(); iter != m_items.end(); ++iter)
	{
		if (iter->contains(mousePosition.x, mousePosition.y))
		{
			name = iter->getName();
			m_items.erase(iter);
			
			// Уровень пройден, если был удалён последний предмет
			if (m_items.empty())
			{
				m_isComplied = true;
				m_soundWin.play();
			}
			break;
		}
	}	
}

void Level::show(sf::RenderWindow& window)
{
	window.draw(m_spriteBackGround);
}

bool Level::isComplied() const
{
	return m_isComplied;
}
