#include "Menu.h"

#include <System/Input.h>

#include <System/Log.h>

#include <cstdio>

Menu::Menu()
    : font(), currentChoice(0), choice(""), longest(0.0f)
{
}

/*
Menu::Menu(const std::string& title)
    : font(NULL), currentChoice(0), choice("")
{
}
*/

Menu::Menu(const std::string& title, const FontPtr& f)
    : font(f), title(font, title), currentChoice(0), choice(""), longest(0.0f)
{
    __setLongest(this->title.getLength());
}

Menu::~Menu()
{
}

void Menu::__setLongest(float f)
{
    if (longest < f)
        longest = f;
}

void Menu::setMetrics(const MenuMetrics& m)
{
    metrics = m;
}

void Menu::setTitle(const std::string& title)
{
    this->title.setText(title);
    this->title.setFont(font);
    __setLongest(this->title.getLength());
}

void Menu::addItem(const std::string& item)
{
    Text t(font, item);
    __setLongest(t.getLength());
    items.push_back(t);
}

void Menu::make()
{
    VertexBuffer::Rectangle(rect,
                            0.0f, 0.0f,
                            longest + 2 * metrics.margin,
                            (metrics.newline * (items.size() + 1) + 2 * metrics.margin),
                            Color(0.0f, 0.0f, 0.0f, 0.4f));

    VertexBuffer::Rectangle(outline,
                            0.0f, 0.0f,
                            longest + 2 * metrics.margin,
                            (metrics.newline * (items.size() + 1) + 2 * metrics.margin),
                            Color(1.0f, 1.0f, 1.0f, 0.3f));
    outline.setDrawType(PrimitiveType::LineLoop);

    VertexBuffer::Line(line,
                       metrics.margin, metrics.margin / 2 + metrics.newline,
                       longest, metrics.margin / 2 + metrics.newline, 
                       Color(1.0f, 1.0f, 1.0f, 0.3f));

    currentChoice = 0;
}

void Menu::handleInput(Input& input, int key, int action)
{
    if (action == KeyPress)
    {
        if (input["up"] == key)
            currentChoice--;
        if (input["down"] == key)
            currentChoice++;
        if (input["go"] == key)
            choice = items.at(currentChoice).getText();
    }

    if (currentChoice < 0)
        currentChoice = (signed)items.size() - 1;
    if (currentChoice > (signed)items.size() - 1)
        currentChoice = 0;
}

void Menu::draw(float x, float y) const
{
    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    rect.draw(0.0f, 0.0f);
    outline.draw(0.0f, 0.0f);
    line.draw(0.0f, 0.0f);

    title.draw(metrics.margin, metrics.margin);

    for (int i = 0; i < (signed)items.size(); ++i)
    {
        if (i == currentChoice)
            glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
        items[i].draw(metrics.margin, (metrics.newline * (i + 1)) + (metrics.margin * 2));
        if (i == currentChoice)
            glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    }

    glPopMatrix();
}

const std::string Menu::getChoice()
{
    return choice;
}

void Menu::resetChoice()
{
    choice = "";
}

