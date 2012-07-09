#ifndef _CoreRegistry_h_
#define _CoreRegistry_h_

#include <map>
#include <string>

class CoreState;

#define REGISTER_GAME(name,game)  static RegisterState thisEntry(std::string(name), new game);

struct RegisterState
{
    public:
        RegisterState(const std::string& identifier, CoreState* state);
};

class CoreRegistry
{
    private:
        static std::map<std::string, CoreState*>& registry();

    public:
        static bool alreadyExists(const std::string& identifier);

        static void registerState(const std::string& identifier, CoreState* entry);
        static CoreState* getState(const std::string& identifier);

        static const std::string& getStateName(CoreState* s);
        static int getStateCount();

        static void unregisterAll();
};

#endif

