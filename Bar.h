#ifndef BAR_H
#define BAR_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "Button.h"

using std::vector;
using std::string;

class Bar
{
private:
	sf::Font m_font;
	sf::Texture m_tBackground;
	sf::Sprite m_sBackround;
	vector<sf::Text> m_itemsName;
	sf::Vector2i m_position{1000, 0};
	


public:
	Bar();
	void addItem(const string& name);
	void update(const string& name);
	const void show(sf::RenderWindow& window) const;
	void clearItem();
};
#endif // !BAR_H


