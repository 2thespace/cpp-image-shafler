#ifndef IMAGE_SHAFFLER_H_
#define IMAGE_SHAFFLER_H_


#include "common.hpp"

#include <filesystem>

namespace Shuffle {
    struct ImageShuffler {
        myImage::image_struct shaffleImage(myImage::image_struct const& inputPath, std::string_view key);
        myImage::image_struct  deshaffleImage(myImage::image_struct const& inputPath, std::string_view key);
        
    };
}

#endif // IMAGE_SHAFFLER_H_