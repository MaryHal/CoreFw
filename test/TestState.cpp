#include "TestState.h"

#include <cstdio>

#include <Utils/StringUtils.h>
#include <System/Input.h>

#include <Core/Core.h>
#include <Core/CoreRegistry.h>

#include "Menu.h"

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

    fonts->add("default", "data/fonts/DroidSans.ttf", 16);
    fonts->add("big", "data/fonts/DroidSans.ttf", 100);
    font = fonts->get("default");
    background = textures->add("background", "data/graphics/Frac1.png");

    sound = sounds->addSample("noise", "data/sound/sfx.wav");

    text = fonts->makeText("default", "\"This above all: to thine own self be true\" ~ Hamlet Act 1, scene 3, 78 82\nasdf\nasd\nas\na\nDefinitely no kerning :(");
    text2 = fonts->makeText("big", "AVAVAV");

    menu = new Menu("Main Menu", font);
    menu->setMetrics(6, 20);
    menu->addItem("Hello");
    menu->addItem("Hi");
    menu->addItem("Howdy");
    menu->addItem("Hey");
    menu->addItem("WA");
    menu->addItem("KO");
    menu->addItem("AV");
    menu->addItem("OOOOOOOOOO");
    menu->make();
    glLineWidth(2.0f);

    vb = new VertexBuffer(4, PrimitiveType::Quads, BufferLayout::VC, BufferType::StaticBuffer);

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
    
    line = new VertexBuffer(2, PrimitiveType::Lines, BufferLayout::VC, BufferType::StaticBuffer);
    line->writeVector(0.0f, 0.0f);
    line->writeColor(1.0f, 1.0f, 1.0f, 0.5f);
    line->writeVector(400.0f, 0.0f);
    line->writeColor(1.0f, 1.0f, 1.0f, 0.5f);

    line->updateBuffers();
}

void TestState::deinit()
{
    CoreState::deinit();
    delete menu;
    delete vb;
}

void TestState::handleInput(Input& input, int value, int action)
{
    menu->handleInput(input, value, action);

    if (value == 'Q' && action == KeyRelease)
    {
        sound->play();
    }
}

void TestState::logic(float timeStep)
{
    if (menu->checkChoice())
    {
        std::string choice = menu->getChoice();
        if (choice == "Hello")
        {
            Core::pushState(CoreRegistry::getState("Game"));
        }
        else if (choice == "Hi")
        {
            Core::pushState(CoreRegistry::getState("Pattern"));
        }
        else if (choice == "Howdy")
        {
            Core::pushState(CoreRegistry::getState("Music"));
        }

        menu->resetChoice();
    }
}

void TestState::draw()
{
    background->draw(0.0f, 0.0f);
    menu->draw(440.0f, 240.0f);
    vb->draw(64.0f, 64.0f);

    line->draw(13.0f, 13.0f);
    line->draw(13.0f, 200.0f);

    text.draw(13.0f, 13.0f);
    text2.draw(13.0f, 200.0f);
}


