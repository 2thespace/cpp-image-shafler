#include <iostream>
#include <vector>
#include <fstream>
#include <cassert>

#include "Shaffler.hpp"
#include "ImageReader.hpp"
#include "ImageShaffler.hpp"
#include "ImageCoder.hpp"


int main(int argc, char** argv) {
    if (argc < 5) {
        std::cout << "try ./encoder path/to/first/png path/to/second/png encoding_key /path/to/result/png" << std::endl;
    }
    myImage::Codder merger;
    merger.ReadImagesWithEncode(argv[1], argv[2], argv[3]);
    merger.SaveResult(argv[4]);
    std::cout << "Result write to " << argv[4] << std::endl;
    return 0;
}