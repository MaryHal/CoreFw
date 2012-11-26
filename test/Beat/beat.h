#ifndef _Beat_h_
#define _Beat_h_

#include <queue>

struct Beat
{
    float time;
    unsigned int keys;
};

class BeatMap
{
    private:
    class CompareBeat
    {
        public:
        bool operator()(Beat& a, Beat& b)
        {
            return a.time < b.time;
        }
    };
    std::priority_queue<Beat, std::vector<Beat>, CompareBeat> beatQueue;

    public:
    BeatMap();
    ~BeatMap();
};

#endif

