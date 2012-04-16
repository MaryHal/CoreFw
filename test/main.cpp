#include "../src/Core/Core.h"
#include "../src/Core/CoreRegistry.h"

#include "../src/System/Debug.h"

int main(int argc, const char *argv[])
{
    Core::init("Particle Demo", 640, 480, false);
    Core::changeState(CoreRegistry::getGame("Test"));
    Core::run();
    Core::deinit();
    return 0;
}

