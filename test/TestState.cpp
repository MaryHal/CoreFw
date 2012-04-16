#include "TestState.h"

#include <cstdio>

#include "Menu.h"

#include <Utils/StringUtils.h>

#include <System/Input.h>

#include <Core/Core.h>
#include <Core/CoreRegistry.h>

REGISTER_GAME("Test", TestState);

TestState::TestState()
{
}

TestState::~TestState()
{
}

void TestState::init(ResourceManager& resources)
{
    CoreState::init(resources);

    fonts->add("default", "data/fonts/DroidSans.ttf", 14);
    font = fonts->get("default");
    textures->add("background", "data/graphics/Frac3.png");
    background = textures->get("background");

    text = fonts->makeText("default", "\"This above all: to thine own self be true\"\n~ Hamlet");

    menu = new Menu("Main Menu", *font);
    MenuMetrics m = { 4, 20 };
    menu->setMetrics(m);
    menu->addItem("Hello");
    menu->addItem("Hi");
    menu->addItem("Howdy");
    menu->addItem("Hey");
    menu->make();

    vb = new VertexBuffer(4, PrimitiveType::Quads, BufferLayout::VC, BufferType::StaticBuffer);
    glLineWidth(2.0f);

    vb->writeVector(0.0f, 0.0f);
    vb->writeColor(1.0f, 1.0f, 1.0f, 0.5f);
    vb->writeVector(256.0f, 0.0f);
    vb->writeColor(1.0f, 0.0f, 0.0f, 0.5f);
    vb->writeVector(256.0f, 256.0f);
    vb->writeColor(0.0f, 1.0f, 0.0f, 0.5f);
    vb->writeVector(0.0f, 256.0f);
    vb->writeColor(0.0f, 0.0f, 1.0f, 0.5f);

    vb->updateBuffers();
    //vb->printDebug();
}

void TestState::deinit()
{
    delete menu;
    delete vb;
}

void TestState::handleInput(Input& input, int value, int action)
{
    menu->handleInput(input, value, action);
}

void TestState::logic(float timeStep)
{
    if (menu->getChoice() != "")
    {
        //printf("%s\n", menu->getChoice().c_str());
        std::string choice = menu->getChoice();
        if (choice == "Hello")
        {
            //Core::changeState(CoreRegistry::getGame("Game"));
            //vb->dumpBuffer();
        }
        menu->resetChoice();
    }
}

void TestState::draw()
{
    background->draw(0.0f, 0.0f);
    menu->draw(480.0f, 300.0f);
    vb->draw(64.0f, 64.0f);
    text.draw(8.0f, 8.0f);
}

