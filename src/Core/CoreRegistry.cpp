#include "CoreRegistry.h"
#include "CoreState.h"

#include "../System/Log.h"

std::map<std::string, CoreState*>& CoreRegistry::registry()
{
    static std::map<std::string, CoreState*>* r = new std::map<std::string, CoreState*>();
    return *r;
}

RegisterState::RegisterState(const std::string& identifier, CoreState* state)
{
    CoreRegistry::registerState(identifier, state);
}

bool CoreRegistry::alreadyExists(const std::string& identifier)
{
    return registry().find(identifier) != registry().end();
}

void CoreRegistry::registerState(const std::string& identifier, CoreState* entry)
{
    if (alreadyExists(identifier))
        return;

    registry()[identifier] = entry;
}

CoreState* CoreRegistry::getState(const std::string& identifier)
{
    return alreadyExists(identifier) ? registry()[identifier] : NULL;
}

const std::string& CoreRegistry::getStateName(CoreState* s)
{
    for (std::map<std::string, CoreState*>::iterator iter = registry().begin();
         iter != registry().end();
         ++iter)
    {
        if (iter->second == s)
            return iter->first;
    }

    static std::string str = "<No State Name>";
    return str;
}

int CoreRegistry::getStateCount()
{
    return registry().size();
}

void CoreRegistry::unregisterAll()
{
    for (std::map<std::string, CoreState*>::iterator iter = registry().begin();
         iter != registry().end();
         ++iter)
    {
        if (iter->second)
        {
            delete iter->second;
            registry()[iter->first] = NULL;
        }
    }
}

