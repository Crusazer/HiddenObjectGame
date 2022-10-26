#ifndef GAME_H
#define GAME_H

#include "Bar.h"
#include "level.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>

class Game
{
private:
	bool m_pause = true;
	int m_numberLevel;
	Level m_level;
	Bar m_bar;

	sf::Texture m_tButtonMenu;
	sf::Sprite m_sButtonMenu;

	sf::Music m_music;
	// Нужно переделать под массив
	sf::SoundBuffer m_soundsBufferClick;
	sf::SoundBuffer m_soundsBufferCorrect;

	sf::Sound m_soundClick;
	sf::Sound m_soundCorrect;


public:
	Game();
	bool isOnPause();
	bool isPassedLevel() const;
	int getNumberLevel() const;

	void loadLevel(const std::string& numberLevel);
	void show(sf::RenderWindow& window);
	void update(const sf::Vector2i& mousePosition);
	void addItem(const string& name, const int rectLeft, const int rectTop, const int rectWidth, const int rectHeight);
	void pause();
	void unpause();

	// музыка
	void playMusic();
	void playSoundClick();
	void playSoundCorrect();
};

#endif // !GAME_H


