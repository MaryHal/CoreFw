#include "VertexBuffer.h"

#include "../Math/Vector2.h"
#include "../Math/Trig.h"

#include "../System/Log.h"

#include <GL/glew.h>
#include <GL/glfw.h>

#include <cstdio>

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

const int VertexBuffer::gl_BufferType[BufferType::MAX_BUFFER] = 
{
    GL_STATIC_DRAW,
    GL_DYNAMIC_DRAW,
    GL_STREAM_DRAW
};

const int VertexBuffer::gl_PrimitiveType[PrimitiveType::MAX_PRIMITIVE] = 
{
    GL_POINTS,
    GL_LINE_STRIP,
    GL_LINE_LOOP,
    GL_LINES,
    GL_TRIANGLE_STRIP,
    GL_TRIANGLE_FAN,
    GL_TRIANGLES,
    GL_QUAD_STRIP,
    GL_QUADS,
    GL_POLYGON
};

const int VertexBuffer::bytesNeeded[BufferLayout::MAX_LAYOUT] = 
{
    0,                  // None
    2 * sizeof(float),  // Vertex
    4 * sizeof(float),  // Color
    2 * sizeof(float),  // TexCoord
    6 * sizeof(float),  // VC
    4 * sizeof(float),  // TV
    8 * sizeof(float)   // TVC
};

VertexBuffer::VertexBuffer()
    : Buffer(),
      vertexCount(0),
      bufferType(BufferType::MAX_BUFFER),
      primitiveType(PrimitiveType::MAX_PRIMITIVE),
      bufferNum(-1)
{
}

VertexBuffer::VertexBuffer(int numVertices, int ptype, int bufferLayout, int type)
    : Buffer(numVertices * bytesNeeded[bufferLayout]),
      vertexCount(numVertices),
      bufferType(type),
      primitiveType(ptype),
      bufferNum(-1)
{
    init();
}

VertexBuffer::~VertexBuffer()
{
    //log("### Destructing");
    glDeleteBuffers(1, &bufferNum);
}

void VertexBuffer::set(int numVertices, int ptype, int bufferLayout, int type)
{
    vertexCount = numVertices;
    primitiveType = ptype;
    bufferType = type;

    this->allocateData(numVertices * bytesNeeded[bufferLayout]);
}

void VertexBuffer::setDrawType(int t)
{
    primitiveType = t;
}


void VertexBuffer::init()
{
    if (GLEW_ARB_vertex_buffer_object)
    {
        // Create a new VBO
        glGenBuffers(1, &bufferNum);

        glBindBuffer(GL_ARRAY_BUFFER, bufferNum);

        glBufferData(GL_ARRAY_BUFFER,
                     length,
                     NULL,
                     gl_BufferType[bufferType]);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}

void VertexBuffer::updateBuffers()
{
    glBindBuffer(GL_ARRAY_BUFFER, bufferNum);

    glBufferData(GL_ARRAY_BUFFER,
                 length,
                 data,
                 gl_BufferType[bufferType]);

    /*
    glBufferSubData(GL_ARRAY_BUFFER_ARB, 
                    0, 
                    vertexBufferSize,
                    vertices);
                    */

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::draw(float x, float y) const
{
    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    drawShape();

    glPopMatrix();
}

void VertexBuffer::drawShape() const
{
    glBindBuffer(GL_ARRAY_BUFFER, bufferNum);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(2, GL_FLOAT, sizeof(float) * 6, BUFFER_OFFSET(0));
    glColorPointer (4, GL_FLOAT, sizeof(float) * 6, BUFFER_OFFSET(8));

    glDrawArrays(gl_PrimitiveType[primitiveType], 0, vertexCount);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::drawTexture() const
{
    glBindBuffer(GL_ARRAY_BUFFER, bufferNum);

    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);

    glTexCoordPointer(2, GL_FLOAT, sizeof(float) * 4, BUFFER_OFFSET(0));
    glVertexPointer  (2, GL_FLOAT, sizeof(float) * 4, BUFFER_OFFSET(8));

    glDrawArrays(gl_PrimitiveType[primitiveType], 0, vertexCount);

    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::printDebug()
{
    logf("%d", bufferNum);
    log("Hello");
}

// Static methods
void VertexBuffer::Line(VertexBuffer& b, 
                        float x1, float y1, float x2, float y2,
                        const Color& color)
{
    b.set(2, PrimitiveType::Lines, BufferLayout::VC, BufferType::StaticBuffer);
    b.init();

    b.writeVector(x1, y1);
    b.writeColor(color.r, color.g, color.b, color.a);
    b.writeVector(x2, y2);
    b.writeColor(color.r, color.g, color.b, color.a);

    b.updateBuffers();
}

void VertexBuffer::Line(VertexBuffer& b,
                        const Vector2f& v1, const Vector2f& v2,
                        const Color& color)
{
    VertexBuffer::Line(b, v1.x, v1.y, v2.x, v2.y, color);
}

void VertexBuffer::Rectangle(VertexBuffer& b, 
                             float x1, float y1, float x2, float y2,
                             const Color& color)
{
    b.set(4, PrimitiveType::Quads, BufferLayout::VC, BufferType::StaticBuffer);
    b.init();

    b.writeVector(x1, y1);
    b.writeColor(color.r, color.g, color.b, color.a);
    b.writeVector(x2, y1);
    b.writeColor(color.r, color.g, color.b, color.a);
    b.writeVector(x2, y2);
    b.writeColor(color.r, color.g, color.b, color.a);
    b.writeVector(x1, y2);
    b.writeColor(color.r, color.g, color.b, color.a);

    b.updateBuffers();
}

void VertexBuffer::Rectangle(VertexBuffer& b, 
                             const Vector2f& v1, const Vector2f& v2,
                             const Color& color)
{
    VertexBuffer::Rectangle(b, v1.x, v1.y, v2.x, v2.y, color);
}

void VertexBuffer::Circle(VertexBuffer& b, 
                          float x, float y, float r,
                          const Color& color)
{
    static const int segments = 40;

    b.set(segments, PrimitiveType::Polygon, BufferLayout::VC, BufferType::StaticBuffer);
    b.init();

    for (int i = 0; i < segments; ++i)
    {
        float angle = i * 2 * Trig::Pi() / segments;
        b.writeVector(x + r * Trig::Cos(angle),
                      y + r * Trig::Sin(angle));
        b.writeColor(color.r, color.g, color.b, color.a);
    }

    b.updateBuffers();
}

void VertexBuffer::Circle(VertexBuffer& b, 
                          const Vector2f& v, float r,
                          const Color& color)
{
    VertexBuffer::Circle(b, v.x, v.y, r, color);
}

