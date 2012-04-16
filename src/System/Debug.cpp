#include "Debug.h"

//#include <assert.h>
#include <cstdio>
#include <cstdlib>

#include "Log.h"

void coreFailedAssert(const std::string& condition, 
                      const std::string message, 
                      const char* file, 
                      int line)
{
    logf(" ## Failed Assertion ##"); 
    logf("Condition: (%s)", condition.c_str());
    logf("Assertion: %s", message.c_str());
    logf("At: %s:%d", file, line);
    exit(1);
}

