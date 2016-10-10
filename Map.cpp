#include "stdafx.h"
#include "Map.h"
Map::Map(const std::string &tilesetPath, sf::Vector2u tileSize, const int *tilesArray, unsigned int width, unsigned int height)
{
	m_tilesetPath = tilesetPath;
	m_tileSize = tileSize;
	m_tilesArray = tilesArray;
	m_width = width;
	m_height = height;
	this->load();
}

bool Map::load()
{
	if (!m_tileset.loadFromFile(m_tilesetPath))
		return false;

	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(m_width * m_height * 4);

	for (unsigned int i = 0; i < m_width; ++i)
	{
		for (unsigned j = 0; j < m_height; ++j)
		{
			int tileNumber = m_tilesArray[i + j * m_width];
			int tu = tileNumber % (m_tileset.getSize().x / m_tileSize.x);
			int tv = tileNumber / (m_tileset.getSize().x / m_tileSize.x);

			sf::Vertex *quad = &m_vertices[(i + j * m_width) * 4];

			quad[0].position = sf::Vector2f(i * m_tileSize.x, j * m_tileSize.y);
			quad[1].position = sf::Vector2f((i + 1 )* m_tileSize.x, j *m_tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * m_tileSize.x, (j + 1) * m_tileSize.y);
			quad[3].position = sf::Vector2f(i * m_tileSize.x, (j +  1) * m_tileSize.y);


			quad[0].texCoords = sf::Vector2f(tu * m_tileSize.x, tv * m_tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * m_tileSize.x, tv * m_tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * m_tileSize.x, (tv + 1) * m_tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * m_tileSize.x, (tv + 1) * m_tileSize.y);

			if (tileNumber != 17)
				m_tileRectArray.push_back(sf::FloatRect(sf::Vector2f(i * m_tileSize.x, j * m_tileSize.y), sf::Vector2f(128, 128)));
		}
	}
}

sf::Vector2u Map::getTileSize()
{
	return m_tileSize;
}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = &m_tileset;
	target.draw(m_vertices, states);
}

std::vector<sf::FloatRect> Map::getTilesHitboxes()
{
	return m_tileRectArray;
}

Map::~Map()
{
	std::cout << "Destruction de la map" << std::endl;
}