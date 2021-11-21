
#ifndef TESTOPENSSL_SCANNING_H
#define TESTOPENSSL_SCANNING_H
#include <WorkingWithDB.h>
#include <CreatingHash.h>
#include <vector>

class Scanning {
private:
    void WorkingWithFile(std::filesystem::path Path);
    bool FindExtension(const std::string& extension);
public:
    void ScanningDirectory(int argc, char* argv[]);
};


#endif //TESTOPENSSL_SCANNING_H
