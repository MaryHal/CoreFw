#ifndef _Debug_h_
#define _Debug_h_

#if defined(DEBUG)
    #include <string>
    #define coreAssert(x,y) if(!(x)){ coreFailedAssert(#x, y, __FILE__, __LINE__); }
    void coreFailedAssert(const std::string& condition, 
                          const std::string message, 
                          const char* file, 
                          int line);
#else
    #define coreAssert(x,y) {}
#endif

#endif

