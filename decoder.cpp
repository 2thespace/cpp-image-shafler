#include <iostream>
#include <vector>
#include <fstream>
#include <cassert>

#include "Shaffler.hpp"
#include "ImageReader.hpp"
#include "ImageShaffler.hpp"
#include "ImageCoder.hpp"


int main(int argc, char** argv) {
    if (argc < 4) {
        std::cout << "try ./decoder path/to/encode/png  encoding_key /path/to/result/png" << std::endl;
        return 0;
    }
    myImage::Codder merger;
    merger.DecodeAndSave(argv[1], argv[2], argv[3]);
    std::cout << "Result write to " << argv[3] << std::endl;
    return 0;
}
