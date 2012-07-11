#ifndef _Texture_h_
#define _Texture_h_

#include "../Graphics/Drawable.h"

#include <GL/glew.h>
#include <GL/glfw.h>
#include <string>

/*
 * Texture class. This class handles setting data to an OpenGL texture.
 */
class Texture : public Drawable
{
    protected:
        GLuint texture;
        int mode;

        int width;
        int height;

        bool loaded;

        bool __texturize(unsigned char* Buffer);

    public:
        // [Con/De]structor
        Texture();
        Texture(const std::string& Filename);
        Texture(const unsigned char* data, int size);
        virtual ~Texture();

        // Image Loading / Unloading
        bool loadImage(const std::string& Filename);
        bool loadImageMemory(const unsigned char* data, int size);

        void setTexture(GLuint tex, int w = 0, int h = 0);

        void killTexture();
        void bindTexture() const;

        // Texture Rendering
        void draw(float x = 0.0f, float y = 0.0f) const;

        // Accessors
        const int getWidth() const;
        const int getHeight() const;

        const GLuint getTexture() const;
};

#endif

