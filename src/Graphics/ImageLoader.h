#ifndef _ImageLoader_h_
#define _ImageLoader_h_

#include <string>

class ImageLoader
{
    private:

    public:
        static unsigned char* loadImage(const std::string& Filename, 
                                        int& width, int& height, int& mode);
        static unsigned char* loadImage(const unsigned char* data, int size, 
                                        int& width, int& height, int& mode);
};

#endif

