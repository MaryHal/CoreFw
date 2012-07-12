#ifndef _ResourceCache_h_
#define _ResourceCache_h_

#include <cstdio>

#include <string>
#include <map>

#include "../Graphics/Texture.h"
#include "../Graphics/Font.h"
#include "../Graphics/Text.h"

#include "../Audio/Sound.h"
#include "../System/Log.h"

#include <boost/shared_ptr.hpp>

template <class T>
class ResourceCache
{
    protected:
        typedef boost::shared_ptr<T> ResourcePointer;
        std::map<std::string, ResourcePointer> resmap;

    public:
        ResourceCache()
        {
        }
        ~ResourceCache()
        {
            removeAll();
        }

        bool alreadyExists(const std::string& identifier)
        {
            //coreAssert(resmap.find(identifier) != resmap.end()," ## Trying to load resource with already existing identifier");
            return resmap.find(identifier) != resmap.end();
        }

        ResourcePointer add(const std::string& identifier, const ResourcePointer& ptr)
        {
            if (alreadyExists(identifier))
                return;

            /*
            T* resource = new T(filename);
            if(!resource)
            {
                delete resource;
                resource = NULL;
                return;
            }
            */
            resmap[identifier] = ptr;
        }

        void remove(const std::string& identifier)
        {
            delete resmap[identifier];
            resmap.erase(identifier);
        }

        virtual void removeAll()
        {
            if (resmap.empty()) 
                return;

            while (resmap.begin() != resmap.end())
            {
                //delete resmap.begin()->second;
                resmap.erase(resmap.begin());
            }
            resmap.clear();
        }

        ResourcePointer get(const std::string& identifier)
        {
            //std::map<std::string, sf::Image*>::iterator search;
            //search = resmap.find(identifier);
            if (!alreadyExists(identifier))
            {
                log(" ## Error: Invalid Identifier in ResourceCache.");
            }
            return resmap[identifier];
        }

        ResourcePointer operator[] (const std::string& identifier)
        {
            return get(identifier);
        }
};



class TextureCache : public ResourceCache<Texture>
{
    public:
        boost::shared_ptr<Texture> add(const std::string& identifier, const std::string& filename);
};

class FontCache : public ResourceCache<Font>
{
    public:
        boost::shared_ptr<Font> add(const std::string& identifier, const std::string& filename, unsigned int charSize);

        Text makeText(const std::string& identifier, const std::string& str);
        Text makeText(const std::string& identifier);
};

class SoundCache : public ResourceCache<Sound>
{
    public:
        boost::shared_ptr<Sound> addSample(const std::string& identifier, const std::string& filename);
        boost::shared_ptr<Sound> addMusic(const std::string& identifier, const std::string& filename);
};

#endif

