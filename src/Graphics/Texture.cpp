#include "Texture.h"

#include <cstdlib>

#include "../Math/Math.h"

#include "../Graphics/ImageLoader.h"

Texture::Texture()
    : texture(0), mode(0), loaded(false)
{
}

Texture::Texture(const std::string& Filename)
{
    __texturize(
            ImageLoader::loadImage(Filename, width, height, mode)
            );
}

Texture::Texture(const unsigned char* data, int size)
{
    __texturize(
            ImageLoader::loadImage(data, size, width, height, mode)
            );
}

Texture::~Texture()
{
    glDeleteTextures(1, &texture);
    loaded = false;
}

bool Texture::__texturize(unsigned char* Buffer)
{
    glGenTextures(1, &texture);
    this->bindTexture();

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,
            0, GL_RGBA, GL_UNSIGNED_BYTE, Buffer);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    /*
    // First list is the full texture
    glNewList(displayList, GL_COMPILE);
    glBegin(GL_QUADS);
    // Top Left
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);

    // Top Right
    glTexCoord2f(1.0f, 0);
    glVertex2f(float(width), 0.0f);

    // Bottom Right
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(float(width), float(height));

    // Bottom Left
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(0.0f, float(height));
    glEnd();
    glEndList();
    */

    free(Buffer);

    loaded = true;
    return true;
}

bool Texture::loadImage(const std::string& Filename)
{
    return __texturize(
            ImageLoader::loadImage(Filename, width, height, mode)
            );

}

bool Texture::loadImageMemory(const unsigned char* data, int size)
{
    return __texturize(
            ImageLoader::loadImage(data, size, width, height, mode)
            );
}

void Texture::setTexture(GLuint tex, int w, int h)
{
    // Only set if not zero
    if (tex)
        texture = tex;
    if (w)
        width = w;
    if (h)
        height = h;
    loaded = true;
}

void Texture::killTexture()
{
    glDeleteTextures(1, &texture);
    loaded = false;
}

// Texture Rendering
void Texture::bindTexture() const
{
    glBindTexture(GL_TEXTURE_2D, this->texture);
}

void Texture::draw(float x, float y) const
{
    if (!loaded)
        return;

    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, this->texture);
    // glCallList(displayList);
    glBegin(GL_QUADS);
    // Top Left
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);

    // Top Right
    glTexCoord2f(1.0f, 0);
    glVertex2f(float(width), 0.0f);

    // Bottom Right
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(float(width), float(height));

    // Bottom Left
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(0.0f, float(height));
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
}

const int Texture::getWidth() const
{
    return width;
}

const int Texture::getHeight() const
{
    return height;
}

