#pragma once
#include "Entity.h"
#include "ResourceHolder.h"

class Aircraft : public Entity
{
public:
	enum Type
	{
		Eagle, Raptor
	};

public:
	explicit Aircraft(Type type, const TextureHolder& textures);
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	Type m_Type;
	sf::Sprite m_Sprite;
};

