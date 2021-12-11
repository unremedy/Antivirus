#include <Scanning.h>

void Scanning::ScanningDirectory(int argc, char **argv) {
    if (argc == 2) {
        std::filesystem::path EnteredPath(argv[1]);
        if (std::filesystem::exists(EnteredPath)) {
            if (is_regular_file(EnteredPath)) {
                WorkingWithFile(EnteredPath);
            } else if (is_directory(EnteredPath)) {
                for (const std::filesystem::directory_entry &x:
                        std::filesystem::recursive_directory_iterator{EnteredPath}) {
                    if (x.is_regular_file()) {
                        WorkingWithFile(x.path());
                    }

                }
            } else if (EnteredPath.empty()) {
                std::cout << "Directory is empty" << std::endl;
            }
        } else {
            throw std::invalid_argument("Path doesn't exist");
        }

    } else {
        throw std::invalid_argument("Wrong arguments");
    }
}

void Scanning::WorkingWithFile(std::filesystem::path Path) {
    if (FindExtension(Path.filename().extension().string())) {
        std::string Hash_;
        WorkingWithDB k;
        CreatingHash f;
        Hash_ = f.GetMD5Hash(Path);
        if (k.ComparingWithDB(Hash_)) {
            std::cout << "found: " << Path << std::endl;
        }
    }
}

bool Scanning::FindExtension(const std::string &extension) {
    std::vector<std::string> VectExt{".txt", ".exe", ".doc", ".xls", ".dll", ".xlxs", ".vbs", ".ppt", "docx"};
    auto it = VectExt.begin();
    while (it != VectExt.end()) {
        if (*it == extension) {
            return true;
        }
        ++it;
    }
    return false;
}

