#ifndef _Timer_h_
#define _Timer_h_

class Timer
{
    private:
        // Start and pause times
        float startTicks;
        float pauseTicks;

        // Timer Status
        bool started;
        bool paused;

    public:
        // [Con/De]structors
        Timer();

        // Clock actions
        void start();
        void stop();
        void pause();
        void unpause();

        // Set Time
        void offsetTime(float time);

        // Get Time
        float getTime();

        // Check status
        bool isStarted();
        bool isPaused();
};

#endif

