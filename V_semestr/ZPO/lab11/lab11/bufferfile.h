#ifndef BUFFERFILE_H
#define BUFFERFILE_H

#include <iostream>
#include <fstream>
#include <string>

#include "buffer.h"

using namespace std;


class BufferFile : public Buffer
{
private:
    string filePath;

public:
    BufferFile(const string& path);
    ~BufferFile() override;

    void add(int a) override;
    void write() override;
};

#endif // BUFFERFILE_H
