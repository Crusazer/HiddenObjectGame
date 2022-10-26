#include "Game.h"
#include "Menu.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <fstream>
#include <windows.h>
constexpr int WINDOW_WIDTH = 1455;  
constexpr int WINDOW_HEIGHT = 606;   

int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow)
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Hidden Object");
	window.setFramerateLimit(60);

	Game game;
	game.loadLevel("1");

	Menu myMenu;
	myMenu.addButton("Continue", "images//menuButton.png", "fonts//Gomawo.ttf", 500, 50);
	myMenu.addButton("Levels", "images//menuButton.png", "fonts//Gomawo.ttf", 500, 160);
	myMenu.addButton("Exit", "images//menuButton.png", "fonts//Gomawo.ttf", 500, 270);

	myMenu.addLevelsButton("Level 1", "images//menuButton.png", "fonts//Gomawo.ttf", 250, 50);
	myMenu.addLevelsButton("Level 2", "images//menuButton.png", "fonts//Gomawo.ttf", 250, 160);
	myMenu.addLevelsButton("Level 3", "images//menuButton.png", "fonts//Gomawo.ttf", 550, 50);
	myMenu.addLevelsButton("Level 4", "images//menuButton.png", "fonts//Gomawo.ttf", 550, 160);
	myMenu.addLevelsButton("Back", "images//menuButton.png", "fonts//Gomawo.ttf", 375, 270);

	game.playMusic();
	myMenu.load();

	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{ 
				// Закрытие окна
			case sf::Event::Closed:
				myMenu.save();
				window.close();
				break;

				//Нажатие клавишами мыши 
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

					
					if (game.isOnPause() == false)
					{
					 	game.update(mousePosition);
					}
					
					// Обработка клитков мышью в меню, только если оно открыто
					if (game.isOnPause())
					{
						std::string buttonName;
						myMenu.updateClick(mousePosition, buttonName);


						if (buttonName == "Exit")
						{
							window.close();
							myMenu.save();
						}

						else if (buttonName == "Levels")
						{
							myMenu.setPage(Page::Levels);
							if (game.isPassedLevel())
								myMenu.addPressedLevel(game.getNumberLevel());
							myMenu.checkPassedLevels();
						}

						else if (buttonName == "Continue")
							game.unpause();

						else if (buttonName == "Back")
							myMenu.setPage(Page::Main);

						else if (buttonName == "Level 1")
							game.loadLevel("1");
						else if (buttonName == "Level 2")
							game.loadLevel("2");

						else if (buttonName == "Level 3")
							game.loadLevel("3");
						else if (buttonName == "Level 4")
							game.loadLevel("4");
					}
				}
				break;

				//Нажатия клавишей клавиатуры
			case event.KeyPressed:
				if (event.key.code == sf::Keyboard::Num1)
				{
					game.loadLevel("1");
					std::cout << "Key '1' is pressed!\n";
				}
				break;

				//движение мышью
			
			case event.MouseMoved:
				if (game.isOnPause())
					myMenu.update(sf::Mouse::getPosition(window));
				break;


			default:
				break;
			}
		
		}

		window.clear();
		game.show(window);
		if(game.isOnPause())
			myMenu.show(window);
		window.display();
	}

	return 0;
}