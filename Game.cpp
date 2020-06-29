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
		if (event.type == sf::Event::Closed)
			m_Window.close();
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
