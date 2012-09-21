#include "QuadState.h"

#include <System/Input.h>
#include <Core/Core.h>
#include <Core/CoreRegistry.h>

#include <System/Log.h>

#include <GL/glfw.h>

REGISTER_GAME("Quad", QuadState);

QuadState::QuadState()
    : tree(0.0f, 0.0f, 480.0f, 480.0f)
{
}

QuadState::~QuadState()
{
}

void QuadState::init(ResourceManager& resources)
{
    CoreState::init(resources);
    background = textures->add("patternBackground", "data/graphics/Frac4.png");
}

void QuadState::deinit()
{
    CoreState::deinit();
}

void QuadState::handleInput(Input& input, int value, int action)
{
    if (value == 'Q' && action == GLFW_PRESS)
    {
        tree.clear();
    }
}

void QuadState::handleMouseInput(Input& input, int value, int action)
{
    if (value == GLFW_MOUSE_BUTTON_LEFT &&
        action == GLFW_PRESS)
    {
        int x;
        int y;
        glfwGetMousePos(&x, &y);
        tree.add(Vector2f(x, y));
        logf("%d %d", x, y);
    }
}

void QuadState::logic(float timeStep)
{
}

void QuadState::draw()
{
    //background->draw();

    // Draw rectangles
    glLineWidth(2.0f);
    const std::vector<Node>& nodes = tree.getNodes();
    for (std::vector<Node>::const_iterator iter = nodes.begin();
         iter != nodes.end();
         ++iter)
    {
        if (iter->active)
        {
            glBegin(GL_LINE_LOOP);
            glColor4f(0.0f, 0.0f, 1.0f, 0.8f);
            glVertex2f(iter->x, iter->y);
            glVertex2f(iter->x + iter->width, iter->y);
            glVertex2f(iter->x + iter->width, iter->y + iter->height);
            glVertex2f(iter->x, iter->y + iter->height);
            glEnd();
        }
    }

    // Draw Points
    glPointSize(3.0f);
    const std::vector<Vector2f>& points = tree.getPoints();
    for (std::vector<Vector2f>::const_iterator iter = points.begin();
         iter != points.end();
         ++iter)
    {
        glBegin(GL_POINTS);
        glColor4f(1.0f, 0.0f, 0.0f, 0.8f);
        glVertex2f(iter->x, iter->y);
        glEnd();
    }
}

