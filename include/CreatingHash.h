
#ifndef TESTOPENSSL_CREATINGHASH_H
#define TESTOPENSSL_CREATINGHASH_H
#include <iostream>
#include <openssl/md5.h>
#include <fstream>
#include <sstream>
#include <cstdio>

class CreatingHash {
private:
    size_t GetNumberOfChars(const std::string& FileName);
    void GetCharsFromFile(const std::string& FileName, char* Massive);
public:
    std::string GetMD5Hash(const std::string& FileName);
};


#endif //TESTOPENSSL_CREATINGHASH_H
