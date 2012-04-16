#ifndef _Menu_h_
#define _Menu_h_

#include "../src/Graphics/Drawable.h"
#include "../src/Graphics/Text.h"

#include "../src/Graphics/VertexBuffer.h"

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
        Font* font;
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
        Menu(const std::string& title, Font& f);
        ~Menu();

        void setTitle(const std::string& title);
        void setMetrics(const MenuMetrics& m);
        void addItem(const std::string& item);
        void make();

        void handleInput(Input& input, int key, int action);
        void draw(float x = 0.0f, float y = 0.0f) const;

        const std::string getChoice();
        void resetChoice();
};

#endif

