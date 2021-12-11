
#include <CreatingHash.h>
#include <cstring>

size_t CreatingHash::GetNumberOfChars(const std::string &FileName) {
    size_t length = 0;
    std::ifstream is(FileName, std::ifstream::binary);
    if (is) {
        is.seekg(0, std::ifstream::end);
        length = is.tellg();
        is.close();
    }
    return length;
}

void CreatingHash::GetCharsFromFile(const std::string &FileName, char *Massive) {
    Massive[GetNumberOfChars(FileName)];
    std::ifstream File(FileName, std::ifstream::binary);
    if (File) {
        size_t length = GetNumberOfChars(FileName);
        char *point = Massive;
        File.read(point, length);
        File.close();
    }
}

std::string CreatingHash::GetMD5Hash(const std::string &FileName) {
    char mas[GetNumberOfChars(FileName)];
    GetCharsFromFile(FileName, mas);
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5(reinterpret_cast<const unsigned char *>(mas), GetNumberOfChars(FileName), (unsigned char *) &digest);
    char mdString[33];
    for (int i = 0; i < 16; i++)
        sprintf(&mdString[i * 2], "%02x", (unsigned int) digest[i]);

    return mdString;
}
