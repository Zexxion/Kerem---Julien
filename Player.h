#include "stdafx.h"
#include <SFML\Graphics.hpp>

class Player
{
private:
	std::string playerName;
	sf::Texture texturePerso;
	sf::Sprite spritePerso;
	sf::RenderWindow *window;
	sf::Vector2u playerSize;
	unsigned int frameNumber;
	std::vector<sf::Sprite> spritesArray;
	std::vector<sf::Texture> texturesArray;
	sf::Clock clock;
	enum States {IDLE, LEFT, RIGHT};
	float currentFrame = 1;
	float moveSpeed = 0.1;


public:
	Player(sf::RenderWindow*, unsigned int, std::string = "default");
	void Render();
	void setMoveSpeed(float);
	void Player::setPosition(float, float);
	void updateAnimation(float, float);
	void updateRender();
	void clearAnimation();
	void move(float, float);
	sf::FloatRect getHitbox();
	sf::Vector2f getPosition();
	~Player();
};