#pragma once
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	void run();

private:
	void processEvents();
	void update();
	void render();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
	sf::RenderWindow m_Window;
	sf::CircleShape m_Player;
	bool m_IsMovingUp;
	bool m_IsMovingDown;
	bool m_IsMovingLeft;
	bool m_IsMovingRight;

};

