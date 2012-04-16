class FpsCounter
{
    private:
        int frameCount;
        float startTime;
        float currentTime;
        float lastTime;
        float fps;

    public:
        FpsCounter();
        ~FpsCounter();

        void calculate();

        float getFrameTime() const;
        float getFps() const;
};
