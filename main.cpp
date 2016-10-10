// SFML Intro.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Map.h"
#include "CollisionEngine.h"
#include <iostream>

int main()
{
	const unsigned int width = sf::VideoMode::getDesktopMode().width;
	const unsigned int height = sf::VideoMode::getDesktopMode().height;
	short speed = 15;
	sf::RenderWindow fen(sf::VideoMode(width, height), "Fenêtre", sf::Style::Resize);
	fen.setPosition(sf::Vector2i(0,0));
	std::cout << "Lancement du jeu" << std::endl;

	const int level[] =
	{
		17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
		17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
		17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
		17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
		17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
		17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
		17, 17, 17, 17, 17, 17, 17, 17, 17, 10, 17, 17, 17, 17, 17, 17, 17, 17, 17,
		0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 17, 17, 17,
	};

	Map map("resources/tiles/tiles-h.png", sf::Vector2u(128, 128), level, 19, 8);
	Player p(&fen, 21, "kerem");
	p.setPosition(500,756);
	p.setMoveSpeed(2);
	CollisionEngine collision(&p, map.getTilesHitboxes());

	while (fen.isOpen())
	{
		fen.draw(map);
		bool update = false;
		sf::Event event;
		/*
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			p.move(0, -speed);
			if (!collision.checkCollisions())
			{
				p.updateAnimation(0, -speed);
				update = true;
			}
			p.move(0, speed);
		}
			
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			p.move(0, speed);
			if (!collision.checkCollisions())
			{
				p.updateAnimation(0, speed);
				update = true;
			}
			p.move(0, -speed);
		}*/

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			p.move(speed, 0);
			if (!collision.checkCollisions())
			{
				p.updateAnimation(speed, 0);
				update = true;
			}
			p.move(-speed, 0);
		}
			
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			p.move(-speed, 0);
			if (!collision.checkCollisions() && p.getPosition().x > -35)
			{
				p.updateAnimation(-speed, 0);
				update = true;
			}
			p.move(speed, 0);
		}

		while (fen.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				fen.close();
			case sf::Event::KeyReleased:
				p.clearAnimation();
				break;
			case sf::Keyboard::Escape:
				fen.close();
				break;
			}
		}
		p.updateRender();
		fen.display();
		fen.clear(sf::Color(59, 156, 251));
	}
	//system("pause");
	return 0;
}
