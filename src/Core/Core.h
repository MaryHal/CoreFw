#include <string>

class Renderer;
class CoreState;

struct ResourceManager;

class Input;

class Core
{
    private:
        static const std::string version;
        static std::string title;
        static unsigned int width;
        static unsigned int height;
        static bool fullscreen;

        static bool running;

        static CoreState* currentState;
        static CoreState* nextState;

        static Renderer* renderer;

        static ResourceManager* resourceManager;
        static Input* input;

        static bool initOpenGL();

    public:
        static void init(const std::string& filename);
        static void init(std::string title, unsigned int width, unsigned int height, bool fullscreen);
        static void deinit();

        static void run();

        static void changeState(CoreState* s);
        static void setNextState(CoreState* s);
        static void deleteState();

        static void exit();
        static const std::string& getStateName();

        static const std::string& getVersion();

        static void keyInput(int key, int action); 
        static void mouseMoveInput(int x, int y);
        static void mouseInput(int button, int action); 
};

