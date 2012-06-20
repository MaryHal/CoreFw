#ifndef _Listener_h_
#define _Listener_h_

typedef struct ALCdevice_struct ALCdevice;
typedef struct ALCcontext_struct ALCcontext;

class Listener
{
    private:
        static ALCdevice* device;
        static ALCcontext* context;

    public:
        static void init();
        static void deinit();

        static void setVolume(float volume);
        static float getVolume();
};

#endif

