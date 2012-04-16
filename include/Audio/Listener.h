#ifndef _Listener_h_
#define _Listener_h_

namespace FMOD
{
    class System;
}

class Listener
{
    public:
        static FMOD::System* system;

        static void init();
        static void deinit();

        static void update();

        static FMOD::System* getSystem();
};

#endif

