#include <SFML/Graphics.hpp>
#include <string>

#ifndef ITEMS_H
#define ITEMS_H

class Item
{
private:
	sf::IntRect m_rect;
	std::string m_name;

public:
	Item(const std::string& name, const int rectLeft, const int rectTop, const int rectWidth, const int rectHeight);
	
	const std::string& getName() const;
	sf::Vector2i getPostion() const;
	sf::Vector2i getSize() const;
	bool contains(const int x, const int y) const;
};

#endif // !ITEMS_H



