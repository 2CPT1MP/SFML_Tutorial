#include "Game.h"

Game::Game()
	: m_Window(sf::VideoMode(640, 480), "SFML Application"),
	  m_Player()
{
	m_Player.setRadius(40.0f);
	m_Player.setPosition(100.0f, 100.0f);
	m_Player.setFillColor(sf::Color::Cyan);
}

void Game::run()
{
	while (m_Window.isOpen())
	{
		processEvents();
		render();
		update();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_Window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			m_Window.close();
			break;
		}
	}
}

void Game::update()
{
	//TODO implement
}

void Game::render()
{
	m_Window.clear();
	m_Window.draw(m_Player);
	m_Window.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W)
		m_IsMovingUp = true;
	else if (key == sf::Keyboard::S)
		m_IsMovingDown = true;
	else if (key == sf::Keyboard::A)
		m_IsMovingLeft = true;
	else if (key == sf::Keyboard::D)
		m_IsMovingRight = true;
		
}
