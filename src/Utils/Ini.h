#ifndef _Ini_h_
#define _Ini_h_

#include <map>
#include <string>

class Ini
{
    private:
        std::map<std::string, std::string> entries;

    public:
        Ini();
        Ini(const std::string& Filename);

        bool loadFile(const std::string& Filename);

        bool alreadyExists(const std::string& identifier);
        std::string operator[](const std::string& identifier);
        void __dump(FILE* f);
        void exportFile(const std::string& Filename);
};

#endif

