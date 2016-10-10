#include "stdafx.h"
#include <iostream>
#include <SFML\Graphics.hpp>

class Map : public sf::Drawable, public sf::Transformable
{
private:
	std::string m_tilesetPath;
	sf::Vector2u m_tileSize;
	const int *m_tilesArray;
	unsigned int m_width;
	unsigned int m_height;
	sf::RenderWindow *window;
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
	std::vector<sf::FloatRect> m_tileRectArray;
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

public:
	Map(const std::string &tilesetPath, sf::Vector2u tileSize, const int *tilesArray, unsigned int width, unsigned int height);
	bool load();
	sf::Vector2u getTileSize();
	std::vector<sf::FloatRect> Map::getTilesHitboxes();
	~Map();
};
