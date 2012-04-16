#ifndef _Resources_h_
#define _Resources_h_

#include <boost/shared_ptr.hpp>
#include "../Graphics/Texture.h"
#include "../Graphics/Font.h"
#include "../Audio/Sound.h"

typedef boost::shared_ptr<Texture> TexturePtr;
typedef boost::shared_ptr<Font> FontPtr;
typedef boost::shared_ptr<Sound> SoundPtr;

#endif

