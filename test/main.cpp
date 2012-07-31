#include <Core/Core.h>
#include <Core/CoreRegistry.h>

int main(int argc, const char *argv[])
{
    Core::init("CoreFW Test", 640, 480, false);
    Core::pushState(CoreRegistry::getState("Test"));
    Core::run();
    Core::deinit();

    return 0;
}

