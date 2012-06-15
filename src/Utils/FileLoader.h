#ifndef _FileLoader_h_
#define _FileLoader_h_

#include <string>

class FileLoader
{
    public:
        enum Mode
        {
            Read,
            Write,
            MAX
        };

    private:
        FILE* file;
        Mode mode;
        size_t length;

    public:
        FileLoader();
        FileLoader(const std::string& filename, Mode m = Read);
        ~FileLoader();

        void loadFile(const std::string& filename, Mode m);
        void gotoBeginning();
        size_t getLength();
        bool atEnd();

        bool readLine(std::string* line);
        bool isOpen();

        static bool exists(const std::string& filename);
};

#endif

