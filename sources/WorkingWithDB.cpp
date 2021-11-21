#include <WorkingWithDB.h>


bool WorkingWithDB::ComparingWithDB(const std::string &Hash) {
    std::fstream file(FindDBFile(), std::ios::in);
    if(file) {
        std::string HashFromFile;
        for(size_t rowNo = 0; !file.eof(); ++rowNo) {
            std::getline(file, HashFromFile);
            if(HashFromFile == Hash){
                return true;
            }
        }
        file.close();
    }



    return false;
}

std::string WorkingWithDB::FindDBFile() {
    std::string Name_repo = "Antivirus";
    std::filesystem::path path = std::filesystem::current_path();
    while (path.string() != "/") {
        if (path.string().rfind(Name_repo) + Name_repo.length() ==
            path.string().length()) {
            for (const std::filesystem::directory_entry& x :
                    std::filesystem::directory_iterator{path}) {
                if (x.path().string().find("DataBaseFiles") != std::string::npos) {
//                    std::cout << x.path().string().append("/DataBase.db") << std::endl;
                    return x.path().string().append("/DataBase.db");
                }
            }
        } else {
            path = path.parent_path();
        }
    }
    return std::filesystem::current_path().string();
}
