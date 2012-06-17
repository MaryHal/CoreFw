#include "ResourceCache.h"

#include "../Graphics/Texture.h"
#include "../Graphics/Font.h"
#include "../Graphics/Text.h"

#include "../Audio/Sound.h"

// ==================================== ResourceCache


// ==================================== TextureCache
void TextureCache::add(const std::string& identifier, const std::string& filename)
{
    if (alreadyExists(identifier))
        return;

    boost::shared_ptr<Texture> resource = boost::shared_ptr<Texture>(new Texture(filename));

    resmap[identifier] = resource;
}

// ==================================== FontCache
void FontCache::add(const std::string& identifier, 
                    const std::string& filename, 
                    unsigned int charSize)
{
    if (alreadyExists(identifier))
        return;

    boost::shared_ptr<Font> resource = boost::shared_ptr<Font>(new Font(filename, charSize));

    resmap[identifier] = resource;
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
void SoundCache::add(const std::string& identifier, 
                                         const std::string& filename, 
                                         const int type)
{
    if (alreadyExists(identifier))
        return;

    boost::shared_ptr<Sound> resource = boost::shared_ptr<Sound>(new Sound(filename, type));

    resmap[identifier] = resource;
}

/*
void SoundCache::addComplex(const std::string& identifier, 
                                         const std::string& filename, 
                                         const int type)
{
    if (alreadyExists(identifier))
        return;

    boost::shared_ptr<Sound> resource = boost::shared_ptr<Sound>(new ComplexSound(filename, type));

    resmap[identifier] = resource;
}
*/

