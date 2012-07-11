#include "MusicState.h"

#include <Core/Core.h>
#include <Core/CoreRegistry.h>

#include "Menu.h"
#include <Utils/StringUtils.h>

REGISTER_GAME("Music", MusicState);

MusicState::MusicState()
{
}

MusicState::~MusicState()
{
}

void MusicState::init(ResourceManager& resources)
{
    CoreState::init(resources);

    fonts->add("default", "data/fonts/DroidSans.ttf", 16);
    text = fonts->makeText("default", "");

    sounds->addMusic("song1", "data/music/song1.flac");
    sounds->addMusic("song2", "data/music/song2.ogg");
    sounds->addMusic("song3", "data/music/song3.ogg");
    sounds->addMusic("song4", "data/music/song4.ogg");
    sounds->addMusic("song5", "data/music/song5.ogg");
    sounds->addMusic("song6", "data/music/song6.wav");

    background = textures->add("musicBackground", "data/graphics/Frac2.png");

    menu = new Menu("Songs", fonts->get("default"));
    menu->setMetrics(6, 20);
    menu->addItem("PainAndPossibility");
    menu->addItem("NocturneOfLove");
    menu->addItem("LostMemories");
    menu->addItem("KindredSpirit");
    menu->addItem("WithRainyEyes");
    menu->addItem("Nevergreen");
    menu->sortItems();
    menu->make();
}

void MusicState::deinit()
{
    //music->stop();
    CoreState::deinit();
    delete menu;
}

void MusicState::handleInput(Input& input, int value, int action)
{
    menu->handleInput(input, value, action);
}

void MusicState::logic(float timeStep)
{
    if (menu->checkChoice())
    {
        if (music)
            music->stop();

        std::string choice = menu->getChoice();
        if (choice == "PainAndPossibility")
        {
            music = sounds->get("song1");
        }
        else if (choice == "NocturneOfLove")
        {
            music = sounds->get("song2");
        }
        else if (choice == "LostMemories")
        {
            music = sounds->get("song3");
        }
        else if (choice == "KindredSpirit")
        {
            music = sounds->get("song4");
        }
        else if (choice == "WithRainyEyes")
        {
            music = sounds->get("song5");
        }
        else if (choice == "Nevergreen")
        {
            music = sounds->get("song6");
        }
        music->play();

        menu->resetChoice();
    }
    if (music)
        text.setText(toString<float>(music->getTime()) + '/' + toString<float>(music->getDuration()));
}

void MusicState::draw()
{
    background->draw(0.0f, 0.0f);
    menu->draw(440.0f, 240.0f);
    text.draw(13.0f, 13.0f);
}



