#include "Menu.h"
#include <iostream>

Menu::Menu()
{
	m_soundBuffer.loadFromFile("music//button.wav");
	m_soundClickOnButton.setBuffer(m_soundBuffer);
}

void Menu::addButton(const std::string& name, const std::string& pathToTexture, const std::string& pathToFont, int posX, int posY)
{
	Button* newButton = new Button(name, pathToTexture, pathToFont, posX, posY);
	m_buttons.push_back(newButton);
}

void Menu::addLevelsButton(const std::string& name, const std::string& pathToTexture, const std::string& pathToFont, int posX, int posY)
{
	Button* newButton = new Button(name, pathToTexture, pathToFont, posX, posY);
	m_levelButtons.push_back(newButton);
}

void Menu::update(const sf::Vector2i& mousePosition)
{
	if (m_page == Main)
		for (auto button : m_buttons)
			button->update(mousePosition);

	else if (m_page == Levels)
		for (auto button : m_levelButtons)
			button->update(mousePosition);
}

void Menu::show(sf::RenderWindow& window)
{
	if (m_page == Main)
		for (auto button : m_buttons)
			button->show(window);

	else if (m_page == Levels)
		for (auto button : m_levelButtons)
			button->show(window);
}

void Menu::updateClick(const sf::Vector2i& mousePostion, std::string& buttonName)
{
	buttonName = "None";

	if (m_page == Main)
	{
		for (auto& button : m_buttons)
			if (button->onButton(mousePostion))
				button->getName(buttonName);
	}

	else if (m_page == Levels) 
	{
		for (auto& button : m_levelButtons)
			if (button->onButton(mousePostion))
				button->getName(buttonName);
	}

	if (buttonName != "None")
		m_soundClickOnButton.play();

}

void Menu::setPage(const Page& page)
{
	m_page = page;
}

void Menu::checkPassedLevels()
{
	if(!m_passedLevels.empty())
	for(int i = 0; i < m_passedLevels.size(); ++i)
	{
		m_levelButtons[m_passedLevels[i] - 1]->setColor(sf::Color(0, 175, 0, 255));
	}
}

void Menu::load()
{
	std::fstream inf("saves//save.txt");
	if (inf)
	{

		if (!m_passedLevels.empty())
			m_passedLevels.clear();

		int numberLevel;

		if (inf.tellg() > 0)
			while (!inf.eof())
			{
				inf >> numberLevel;
				if (numberLevel > 0 && numberLevel << m_maxNumberLevel)
					m_passedLevels.push_back(numberLevel);
			}
	}

	inf.close();
}

void Menu::save()
{
	std::fstream outf("saves//save.txt");

	for (int i = 0; i < m_passedLevels.size(); ++i)
	{
		outf << ' ';
		outf << m_passedLevels[i];
	}
}

void Menu::addPressedLevel(int numb)
{
	if(numb > 0 && numb <= m_maxNumberLevel)
		m_passedLevels.push_back(numb);
}
