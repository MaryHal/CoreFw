#include "../src/Core/Core.h"
#include "../src/Core/CoreRegistry.h"

#include "../src/System/Debug.h"

int main(int argc, const char *argv[])
{
    Core::init("CoreFW Test", 640, 480, false);
    Core::changeState(CoreRegistry::getState("Test"));
    Core::run();
    Core::deinit();
    return 0;
}

