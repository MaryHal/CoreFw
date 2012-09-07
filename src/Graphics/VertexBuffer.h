#ifndef _VertexBuffer_h_
#define _VertexBuffer_h_

#include "Drawable.h"
#include "../Memory/Buffer.h"

#include <cstddef>
#include <map>

template <typename T> class Vector2;
typedef Vector2<float> Vector2f;

class Color;

namespace BufferType
{
    enum
    {
        StaticBuffer,  // Set data once, render that data lots
        DynamicBuffer, // Change data from time to time
        StreamBuffer,  // Write data a lot (like once per frame)

        MAX_BUFFER
    };
};

namespace PrimitiveType
{
    enum
    {
        Points,
        LineStrip,
        LineLoop,
        Lines,
        TriangleStrip,
        TriangleFan,
        Triangles,
        QuadStrip,
        Quads,
        Polygon,

        MAX_PRIMITIVE
    };
};

namespace BufferLayout
{
    enum
    {
        None,
        Vertex,
        Color,
        TexCoord,

        VC,
        TV,
        TVC,

        MAX_LAYOUT
    };


};

class VertexBuffer : public Buffer, public Drawable
{
    private:
        static const int gl_BufferType[BufferType::MAX_BUFFER];
        static const int gl_PrimitiveType[PrimitiveType::MAX_PRIMITIVE];
        static const int bytesNeeded[BufferLayout::MAX_LAYOUT];

        int vertexCount;
        int bufferType;
        int primitiveType;
        unsigned int bufferNum;

    public:
        VertexBuffer();
        VertexBuffer(int numVertices, int ptype, int bufferLayout, int type);
        ~VertexBuffer();

        void set(int numVertices, int ptype, int bufferLayout, int type);
        void setDrawType(int t);
        void init();

        void updateBuffers();
        void draw(float x = 0.0f, float y = 0.0f) const;

        void drawShape() const;
        void drawTexture() const;

        void printDebug();

        // Static methods
        static void Line(VertexBuffer& b,
                         float x1, float y1, float x2, float y2,
                         const Color& color);
        static void Line(VertexBuffer& b,
                         const Vector2f& v1, const Vector2f& v2,
                         const Color& color);

        static void Rectangle(VertexBuffer& b,
                              float x1, float y1, float x2, float y2,
                              const Color& color);
        static void Rectangle(VertexBuffer& b,
                              const Vector2f& v1, const Vector2f& v2,
                              const Color& color);

        static void Circle(VertexBuffer& b,
                           float x, float y, float r,
                           const Color& color);
        static void Circle(VertexBuffer& b,
                           const Vector2f& v, float r,
                           const Color& color);
};

#endif
