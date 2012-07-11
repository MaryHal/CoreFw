#ifndef _Menu_h_
#define _Menu_h_

#include <Graphics/Drawable.h>
#include <Graphics/Text.h>

#include <Graphics/VertexBuffer.h>

#include <System/ResourcePtr.h>

#include <vector>

class Input;

struct MenuMetrics
{
    int margin;
    int newline;
};

class Menu : public Drawable
{
    private:
        FontPtr font;
        Text title;

        std::vector<Text> items;
        int currentChoice;
        std::string choice;

        float longest;
        MenuMetrics metrics;

        VertexBuffer rect;
        VertexBuffer outline;
        VertexBuffer line;

        void __setLongest(float f);

    public:
        Menu();
        //Menu(const std::string& title);
        Menu(const std::string& title, const FontPtr& f);
        ~Menu();

        void setTitle(const std::string& title);
        void setMetrics(const MenuMetrics& m);
        void setMetrics(int margin, int newline);
        void addItem(const std::string& item);
        void addItems(const std::string items[], int numItems);
        void make();

        static const bool stringCmp(const Text& a, const Text& b);
        void sortItems();

        void handleInput(Input& input, int key, int action);
        void draw(float x = 0.0f, float y = 0.0f) const;

        const std::string getChoice() const;
        const bool checkChoice() const;
        void resetChoice();
};

#endif

