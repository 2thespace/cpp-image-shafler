#include "ImageReader.hpp"




myImage::image_struct myImage::ReadImage(std::filesystem::path  const &pathToImage)
{
    cimg_library::CImg<std::uint8_t> image(pathToImage.string().c_str());
    
    std::vector<std::uint8_t> tmp;
    tmp.resize(image.size());
    std::size_t width    = image.width();
    std::size_t height   = image.height();
    std::uint8_t channels = image.spectrum();

    std::vector tmp2(image.data(), image.data() + image.size());
    image_struct result {
        ._image = std::move(tmp2),
        .width = width,
        .height = height,
        .channels = channels,        
    };
    return result;
}

void myImage::SaveImage(image_struct const &image, std::filesystem::path const &pathToImage)
{
    cimg_library::CImg<std::uint8_t> tmp(image._image.data(), image.width, image.height, 1, image.channels);
    tmp.save_png(pathToImage.string().c_str());
}
