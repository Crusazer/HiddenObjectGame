#ifndef MENU_H
#define MENU_H

#include "Button.h"

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>


enum Page
{
	Main,
	Levels,
	Max_page
};

class Menu
{
private:
	std::vector<Button*> m_buttons;
	std::vector<Button*> m_levelButtons;
	Page m_page{ Main };
	std::vector<int> m_passedLevels;

	sf::SoundBuffer m_soundBuffer;
	sf::Sound m_soundClickOnButton;
	int m_maxNumberLevel{ 4 };

public:
	Menu();
	void addButton(const std::string& name, const std::string& pathToTexture,
					const std::string& pathToFont, int posX, int posY);
	void addLevelsButton(const std::string& name, const std::string& pathToTexture, 
					const std::string& pathToFont, int posX, int posY);
	void update(const sf::Vector2i& mousePosition);
	void show(sf::RenderWindow& window);
	void updateClick(const sf::Vector2i& mousePostion, std::string& buttonName);
	void setPage(const Page& page);
	void checkPassedLevels();

	void load();
	void save();
	void addPressedLevel(int numb);
};
#endif // !MENU_H


