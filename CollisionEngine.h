#include "stdafx.h"
#include "Player.h"
#include <iostream>
#include <SFML\Graphics.hpp>

class CollisionEngine
{
private:
	Player *p;
	std::vector<sf::FloatRect> tiles;

public:
	CollisionEngine(Player*, std::vector<sf::FloatRect>&);
	~CollisionEngine();
	bool checkCollisions();
};