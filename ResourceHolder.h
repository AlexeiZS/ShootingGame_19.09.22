#pragma once
#include <SFML\Graphics.hpp>
#include <map>
#include <string>

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
	void load(Identifier id, const std::string& filename)
	{
		std::unique_ptr<Resource>resource(new Resource());
		if (!resource->loadFromFile(filename))
		{
			throw std::runtime_error
			("ResourceHolder::load-Failed to load" + filename);
		}
		auto inserted = mResourceMap.insert(
			std::make_pair(id, std::move(resource)));
		assert(inserted.second);
	}

	template <typename Resource,typename Identifier>
	Resource&  get (Identifier id)
	{
		auto found = mResourceMap.find(id);
		assert(found != mResourceMap.end());
		return *found->second;
	}

	template <typename Resource,typename Identifier>
	const Resource&  get (Identifier id)const
	{
		auto found = mResourceMap.find(id);
		assert(found != mResourceMap.end());
		return *found->second;
	}

	template <typename Resource,typename Identifier>
	void  insertResource(Identifier id, std::unique_ptr<Resource>resource)
	{
		auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
		assert(inserted.second);
	}
	
	
private:
	std::map<Identifier, std::unique_ptr<Resource>>mResourceMap;



};

