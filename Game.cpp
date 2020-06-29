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
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (m_Window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		render();
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

void Game::update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	if (m_IsMovingUp)
		movement.y -= 1.0f;
	if (m_IsMovingDown)
		movement.y += 1.0f;
	if (m_IsMovingLeft)
		movement.x -= 1.0f;
	if (m_IsMovingRight)
		movement.x += 1.0f;

	m_Player.move(movement * deltaTime.asSeconds());
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
