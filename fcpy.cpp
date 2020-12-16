#include <iostream>
#include <fstream>
#include <filesystem>
#include "progress_bar.h"

const static int BUFFER_SIZE = 8192;

using std::ios_base;

int main(int argc, char** argv) {
    std::filesystem::path p("./txt");
    char buf[BUFFER_SIZE];
    int i = 0;
    double fsize = std::filesystem::file_size(p);
    std::cout << "fsize = " << fsize << std::endl;
    std::ifstream in("./txt", ios_base::in | ios_base::binary);
    std::ofstream out("./txt_out", ios_base::in | ios_base::binary);
    
    do {
        
        in.read(&buf[0], BUFFER_SIZE);
        out.write(&buf[0], in.gcount());
        setProgress((double) i/fsize * 100.0);
        i = i + BUFFER_SIZE;
    } while (in.gcount() > 0);

    in.close();
    out.close();
}