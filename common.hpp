#ifndef _COMMON_H_
#define _COMMON_H_

#include <vector>
#include <cstdint>

namespace myImage {
    struct image_struct {
        std::vector<std::uint8_t> _image;
        std::size_t width;
        std::size_t height;
        std::uint8_t channels;
    };
}

#endif  //_COMMON_H_