#include "Button.h"

Button::Button(const std::string& name, const std::string& pathToTexture, 
	const std::string& pathToFont, int posX, int posY) : m_name(name)
{
	// Устанавливаем тексутуру кнопки
	m_texture.loadFromFile(pathToTexture);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(posX, posY);

	//Создаём надпись на кнопке
	m_font.loadFromFile(pathToFont);
	m_text.setFont(m_font);
	m_text.setString(name);
	m_text.setCharacterSize(70);
	m_text.setFillColor(sf::Color::Black);

	sf::Vector2i cetnerButton;
	cetnerButton.x = m_sprite.getGlobalBounds().left + m_sprite.getGlobalBounds().width / 2;
	cetnerButton.y = m_sprite.getGlobalBounds().top;
	m_text.setPosition( (cetnerButton.x - m_text.getGlobalBounds().width / 2), cetnerButton.y + 5); // 5 - offset
}

void Button::update(const sf::Vector2i& mousePosition)
{
	if (m_sprite.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
		m_text.setFillColor(sf::Color(230,40,25)); // RED
	else
		m_text.setFillColor(sf::Color::Black);
}

void Button::show(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
	window.draw(m_text);
}

bool Button::onButton(const sf::Vector2i& mousePositoin) const
{
	return m_sprite.getGlobalBounds().contains(mousePositoin.x, mousePositoin.y);
}

void Button::getName(std::string& buttonName) const
{
	buttonName = m_name;
}

void Button::setColor(sf::Color color)
{
	m_sprite.setColor(color);
}
