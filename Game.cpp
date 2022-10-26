#include "Game.h"
#include <fstream>
#include <string>

Game::Game()
{
	m_tButtonMenu.loadFromFile("images//button.png");
	m_sButtonMenu.setTexture(m_tButtonMenu);
	m_sButtonMenu.setPosition(1150, 483);

	// Музыка и звуки
	m_music.openFromFile("music//wondrousWaters.wav");
	m_soundsBufferClick.loadFromFile("music//click.wav");
	m_soundClick.setBuffer(m_soundsBufferClick);
	
	m_soundsBufferCorrect.loadFromFile("music//correct.wav");
	m_soundCorrect.setBuffer(m_soundsBufferCorrect);

}

bool Game::isOnPause()
{
	return m_pause;
}

void Game::loadLevel(const std::string& numberLevel) 
{
	m_level.setTextureBackground(numberLevel);
	m_numberLevel = atoi(numberLevel.c_str());

	// Загружаем из файла txt координаты всех предметов для поиска
	std::fstream inf("levels//level" + numberLevel + ".txt");
	if (inf)
	{
		//Очищаем старый список предметов
		m_bar.clearItem();
		m_level.clearItem();
		std::string name;
		int rectLeft;
		int rectTop;
		int rectWidth;
		int rectHeight;

		while (!inf.eof())
		{
			inf >> name;
			inf >> rectLeft;
			inf >> rectTop;
			inf >> rectWidth;
			inf >> rectHeight;

			addItem(name, rectLeft, rectTop, rectWidth, rectHeight);
		}
	}
}

void Game::show(sf::RenderWindow& window)
{
	m_level.show(window);
	m_bar.show(window);
	window.draw(m_sButtonMenu);
}

void Game::update(const sf::Vector2i& mousePosition)
{
	std::string name = "None";
	m_level.update(mousePosition, name);
	m_bar.update(name);

	// Звуки
	if (name == "None")
		m_soundClick.play();
	else
		m_soundCorrect.play();	

	if (m_sButtonMenu.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
		m_pause = true;
}

void Game::addItem(const string& name, const int rectLeft, const int rectTop, const int rectWidth, const int rectHeight)
{
	m_level.addItem(name, rectLeft, rectTop, rectWidth, rectHeight);
	m_bar.addItem(name);
}

void Game::pause()
{
	m_pause = true;
}

void Game::unpause()
{
	m_pause = false;
}

void Game::playMusic()
{
	m_music.setLoop(true);
	m_music.play();
}

void Game::playSoundClick()
{
	m_soundClick.play();
}

void Game::playSoundCorrect()
{
	m_soundCorrect.play();
}

bool Game::isPassedLevel() const
{
	return m_level.isComplied();
}

int Game::getNumberLevel() const
{
	return m_numberLevel;
}
