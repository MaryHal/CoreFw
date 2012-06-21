#include "ResourceCache.h"

#include "../Graphics/Texture.h"
#include "../Graphics/Font.h"
#include "../Graphics/Text.h"

#include "../Audio/Sound.h"
#include "../Audio/Sample.h"

// ==================================== ResourceCache


// ==================================== TextureCache
boost::shared_ptr<Texture> TextureCache::add(const std::string& identifier, const std::string& filename)
{
    if (alreadyExists(identifier))
        return resmap[identifier];

    boost::shared_ptr<Texture> resource = boost::shared_ptr<Texture>(new Texture(filename));

    resmap[identifier] = resource;

    return resource;
}

// ==================================== FontCache
boost::shared_ptr<Font> FontCache::add(const std::string& identifier, 
                               const std::string& filename, 
                               unsigned int charSize)
{
    if (alreadyExists(identifier))
        return resmap[identifier];

    boost::shared_ptr<Font> resource = boost::shared_ptr<Font>(new Font(filename, charSize));

    resmap[identifier] = resource;

    return resource;
}

Text FontCache::makeText(const std::string& identifier, const std::string& str)
{
    return Text(resmap[identifier], str);
}

Text FontCache::makeText(const std::string& identifier)
{
    return Text(resmap[identifier], "");
}

// ==================================== SoundCache
boost::shared_ptr<Sound> SoundCache::add(const std::string& identifier, 
                                         const std::string& filename)
{
    if (alreadyExists(identifier))
        return resmap[identifier];

    boost::shared_ptr<Sound> resource = boost::shared_ptr<Sound>(new Sample(filename));

    resmap[identifier] = resource;

    return resource;
}

