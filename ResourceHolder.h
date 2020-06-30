#pragma once
#include <map>
#include <memory>
#include <SFML/Graphics.hpp>

namespace Textures
{
	enum ID
	{
		Eagle, Raptor
	};
}

template <typename Resource, typename Identifier>
class ResourceHolder
{
private:
	std::map<Identifier, std::unique_ptr<Resource>> m_ResourceMap;

public:
	template <typename Parameter>
	void load(Identifier id, const std::string& filename, const Parameter& secondParam);
	Resource& get(Identifier id);
	const Resource& get(Identifier id) const;
};

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

