#include "stdafx.h"
#include <iostream>
#include "Player.h"

Player::Player(sf::RenderWindow *w, unsigned int frames, std::string pName)
{
	playerName = pName;
	window = w;
	frameNumber = frames;
	this->Render();
}

void Player::Render()
{
	sf::Sprite sprite;
	sf::Texture texture;
	for (int i = 1; i <= frameNumber; i++)
	{
		if (!texture.loadFromFile("resources/character/"+playerName+"/run-right-"+std::to_string(i)+".png"))
			std::cout << "Impossible de charger resources/character/"+playerName+"/run-"+std::to_string(i)+".png";
		texturesArray.push_back(texture);
	}

	for (int i = 0; i < texturesArray.size(); i++)
	{
		sprite.setTexture(texturesArray[i]);
		spritesArray.push_back(sprite);
	}

	if (!texturePerso.loadFromFile("resources/character/"+playerName+"/idle-1.png"))
		std::cout << "Impossible de charger resources/character/"+playerName+"/idle-1.png";

	spritePerso.setTexture(texturePerso);
	window->draw(spritePerso);
}

void Player::setMoveSpeed(float m)
{
	moveSpeed /= m;
}

void Player::setPosition(float x, float y)
{
	spritePerso.setPosition(x, y);
	for (int i = 0; i < spritesArray.size(); i++)
		spritesArray[i].setPosition(x, y);
}

void Player::updateAnimation(float x, float y)
{
	if (clock.getElapsedTime().asSeconds() > moveSpeed)
	{
		currentFrame++;

		if (currentFrame >= frameNumber)
			currentFrame = 0;
			
		for (int i = 0; i < spritesArray.size(); i++)
			spritesArray[i].move(x,y);
		spritePerso.move(x, y);
		clock.restart();
	}
}

void Player::updateRender()
{
	window->draw(spritesArray[currentFrame]);
}

void Player::clearAnimation()
{
	currentFrame = 0;
	window->draw(spritePerso);
}

void Player::move(float x, float y)
{	
	spritePerso.move(x, y);
}

sf::Vector2f Player::getPosition()
{
	return spritePerso.getPosition();
}

sf::FloatRect Player::getHitbox()
{
	if (playerName == "kerem")
	{
		sf::FloatRect rect(spritePerso.getPosition().x + 48, spritePerso.getPosition().y + 20, 38, 100);
		return rect;
	}

	else
	{
		return spritePerso.getGlobalBounds();
	}

}

Player::~Player()
{
	std::cout << "Destruction de l'objet Player" << std::endl;
}