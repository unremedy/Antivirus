
#ifndef ANTIVIRUS_WORKINGWITHBD_H
#define ANTIVIRUS_WORKINGWITHBD_H
#include <iostream>
#include <fstream>
#include <filesystem>

class WorkingWithDB{
private:
    std::string FindDBFile();
public:
    bool ComparingWithDB(const std::string& Hash);
};

#endif //ANTIVIRUS_WORKINGWITHBD_H
