#include <Scanning.h>
//#include <CreatingHash.h>
//#include <WorkingWithDB.h>
// 428ece7fc10f05889874db7ce152fae2
//a3e8189bb7412c7a3e8a5eb5b4fb224d

int main(int argc, char* argv[]) {
    char pointer[] = "/home/unremedy/Documents";
    char first[] = "first/dir";
    char* mas[] = {first, pointer};
    Scanning sc;
    sc.ScanningDirectory(2, mas);

    return 0;
}
