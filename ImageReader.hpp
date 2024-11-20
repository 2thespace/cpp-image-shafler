#ifndef IMAGE_READER_H_
#define IMAGE_READER_H_

#define cimg_display 0
#include "CImg.h"


#include <filesystem>
#include "common.hpp"


namespace myImage {

    image_struct ReadImage(std::filesystem::path const& pathToImage);
    void SaveImage(image_struct const& image, std::filesystem::path const& pathToImage);
}

#endif // IMAGE_READER_H_