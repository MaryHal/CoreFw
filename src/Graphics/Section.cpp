#include "Section.h"

Section::Section()
    : texture(NULL)
{
}

Section::Section(Texture* t, Rect<float>* r)
    : texture(t)
{
    float sectWidth(r->getWidth());
    float sectHeight(r->getHeight());

    float texCoordx(r->left / t->getWidth());
    float texCoordy(r->top / t->getHeight());
    float texCoordx2(r->right / t->getWidth());
    float texCoordy2(r->bottom / t->getHeight());

    vb.set(4, PrimitiveType::Quads, BufferLayout::TV, BufferType::StaticBuffer);
    vb.init();

    // Top Left
    vb.writeVector(texCoordx, texCoordy);
    vb.writeVector(0.0f, 0.0f);

    // Top Right
    vb.writeVector(texCoordx2, texCoordy);
    vb.writeVector(sectWidth, 0.0f);

    // Bottom Right
    vb.writeVector(texCoordx2, texCoordy2);
    vb.writeVector(sectWidth, sectHeight);

    // Bottom Left
    vb.writeVector(texCoordx, texCoordy2);
    vb.writeVector(0.0f, sectHeight);

    vb.updateBuffers();
}

Section::~Section()
{
}


void Section::setTexture(Texture* tex)
{
    texture = tex;
}

void Section::createSection(Texture* t, Rect<float>* r)
{
    texture = t;
    float sectWidth(r->getWidth());
    float sectHeight(r->getHeight());

    float texCoordx(r->left / t->getWidth());
    float texCoordy(r->top / t->getHeight());
    float texCoordx2(r->right / t->getWidth());
    float texCoordy2(r->bottom / t->getHeight());

    vb.set(4, PrimitiveType::Quads, BufferLayout::TV, BufferType::StaticBuffer);
    vb.init();

    // Top Left
    vb.writeVector(texCoordx, texCoordy);
    vb.writeVector(0.0f, 0.0f);

    // Top Right
    vb.writeVector(texCoordx2, texCoordy);
    vb.writeVector(sectWidth, 0.0f);

    // Bottom Right
    vb.writeVector(texCoordx2, texCoordy2);
    vb.writeVector(sectWidth, sectHeight);

    // Bottom Left
    vb.writeVector(texCoordx, texCoordy2);
    vb.writeVector(0.0f, sectHeight);

    vb.updateBuffers();
}

void Section::draw(float x, float y) const
{
    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    glEnable(GL_TEXTURE_2D);
    texture->bindTexture();

    vb.drawTexture();

    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
}

