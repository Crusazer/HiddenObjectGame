#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include <SFML/Graphics.hpp>


class Button
{
private:
	std::string m_name;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Font m_font;
	sf::Text m_text;

public:
	Button(const std::string& name, const std::string& pathToTexture, 
		const std::string& pathToFont, int posX, int posY);

	Button(const Button&) = delete;


	void update(const sf::Vector2i& mousePosition);
	void show(sf::RenderWindow& window) const;
	bool onButton(const sf::Vector2i& mousePositoin) const;
	void getName(std::string& buttonName) const;
	void setColor(sf::Color color);

};



#endif // !BUTTON_H


