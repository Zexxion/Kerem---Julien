#include "stdafx.h"
#include "CollisionEngine.h"

CollisionEngine::CollisionEngine(Player *player, std::vector<sf::FloatRect> &tilesHitboxes)
{
	p = player;
	tiles = tilesHitboxes;
}

CollisionEngine::~CollisionEngine()
{
}

bool CollisionEngine::checkCollisions()
{
	for (int i = 0; i < tiles.size(); i++)
	{
		if (tiles[i].intersects(p->getHitbox()))
		{
			std::cout << "Collision avec la tuile numero " << i << std::endl;
			return true;
		}
	}
	return false;
}