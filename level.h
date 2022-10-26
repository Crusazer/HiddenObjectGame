#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <list>
#include <string>

#include "item.h"

#ifndef LEVEL_H
#define LEVEL_H


class Level
{
private:
	std::list<Item> m_items;
	sf::Texture m_textureBackround;
	sf::Sprite m_spriteBackGround;

	bool m_isComplied;
	sf::SoundBuffer m_soundBufferWin;
	sf::Sound m_soundWin;

public:
	Level();
	void addItem(const std::string& name, const int rectLeft, const int rectTop, const int rectWidth, const int rectHeight);
	void clearItem();
	void setTextureBackground(const std::string& levelNumber);
	void update(const sf::Vector2i& mousePosition, std::string& name);
	void show(sf::RenderWindow& window);
	bool isComplied() const;

};
#endif // !LEVEL_H


