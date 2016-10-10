#include "funcs.h"

void handleEvents()
{
	switch (event.type)
	{
	case sf::Event::Closed:
		fen.close();
		break;
	case sf::Event::KeyPressed:
		switch (event.key.code)
		{
		case sf::Keyboard::Right:
			std::cout << "Droite !" << std::endl;
			rect.move(5, 0);
			break;
		case sf::Keyboard::Left:
			std::cout << "Gauche !" << std::endl;
			rect.move(-5, 0);
			break;
		case sf::Keyboard::Up:
			std::cout << "Haut !" << std::endl;
			rect.move(0, -5);
			break;
		case sf::Keyboard::Down:
			std::cout << "Bas !" << std::endl;
			rect.move(0, 5);
			break;
		}

	}
}