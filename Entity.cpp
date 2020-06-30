#include "Entity.h"

void Entity::setVelocity(sf::Vector2f velocity)
{
	m_Velocity = velocity;
}

void Entity::setVelocity(float vx, float vy)
{
	m_Velocity.x = vx;
	m_Velocity.y = vy;
}

sf::Vector2f Entity::getVelocity() const
{
	return m_Velocity;
}
