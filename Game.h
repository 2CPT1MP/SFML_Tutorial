#pragma once
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	void run();

private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
	sf::RenderWindow m_Window;

	sf::Texture m_Texture;
	sf::Sprite m_Player;

	bool m_IsMovingUp = false;
	bool m_IsMovingDown = false;
	bool m_IsMovingLeft = false;
	bool m_IsMovingRight = false;
	
	const sf::Time TimePerFrame = sf::seconds(1.0f / 60.0f);
	const float PlayerSpeed = 50.0f;
};

