#include "Renderer.h"

#include "../Graphics/Drawable.h"

#include <GL/glfw.h>
#include <cstdio>

#include "../System/Log.h"

Renderer::Renderer(int w, int h)
    : dispWidth(w), dispHeight(h)
{
    // Set Default ClearColor
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    // Set projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, dispWidth, dispHeight, 0, -1, 1);

    // Initialize modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Set alpha blending and disable lighting
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);

    glEnable(GL_LINE_SMOOTH);

    // If there was any errors
    if (glGetError() != GL_NO_ERROR)
        log("Could not initialize OpenGL.");
    log("Renderer Initialized.");
}

Renderer::~Renderer()
{
}

void Renderer::init() const
{
}

void Renderer::deinit() const
{
}

void Renderer::pre() const
{
    glClear(GL_COLOR_BUFFER_BIT);
    //glScalef(xStretch, yStretch, 1.0f);
}

void Renderer::draw(Drawable& Object, float x, float y)
{
    Object.draw(x, y);
}

void Renderer::draw(Drawable& Object, Vector2f& loc)
{
    Object.draw(loc);
}

void Renderer::post() const
{
    //glFinish();
    glfwSwapBuffers();
}

void Renderer::rotate(float rotation)
{
    glRotatef(rotation, 0.0f, 0.0f, 1.0f);
}

void Renderer::scale(float x, float y)
{
    glScalef(x, y, 1.0f);
}

