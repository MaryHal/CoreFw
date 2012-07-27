#include "ImageLoader.h"

#include "../stblib/stb_image.h"
#include "../System/Log.h"

#include <GL/glfw.h>
#include <cstdio>

unsigned char* ImageLoader::loadImage(const std::string& Filename, 
        int& width, int& height, int& mode)
{
    unsigned char* buffer = NULL;
    buffer = stbi_load(Filename.c_str(), 
            &width, &height, &mode, STBI_rgb_alpha);

    // Check if everything went alright?
    if (buffer == NULL)
        logf("Failed to load image @ %s: %s.", 
                Filename.c_str(), stbi_failure_reason());

    logf("Image @ %s loaded.", Filename.c_str());

    return buffer;
}

unsigned char* ImageLoader::loadImage(const unsigned char* data, int size, 
        int& width, int& height, int& mode)
{
    unsigned char* buffer = NULL;
    buffer = stbi_load_from_memory(data, size,
            &width, &height, &mode, STBI_rgb_alpha);

    // Check if everything went alright?
    if(buffer == NULL)
        logf("Failed to load image @ <internal>: %s.", 
                stbi_failure_reason());

    log("Image @ <internal> loaded.");

    return buffer;
}

