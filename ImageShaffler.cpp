#include "ImageShaffler.hpp"

#include "Shaffler.hpp"



myImage::image_struct Shuffle::ImageShuffler::shaffleImage(myImage::image_struct const &inputImage, std::string_view key)
{

    using imageType = decltype(inputImage._image)::value_type;

    auto keyHash = std::hash<std::string_view>{}(key);
    std::vector<std::uint32_t> indexPixel(inputImage._image.size());
    std::iota(indexPixel.begin(), indexPixel.end(), 0);
   
    auto shaffledPixel = Shuffle::Worker<std::uint32_t>{}.shaffleSequence(indexPixel, keyHash);
    std::vector<std::uint8_t> resultImage(inputImage._image.size());
    std::transform(shaffledPixel.begin(), shaffledPixel.end(), resultImage.begin(), [&img = inputImage._image](auto index) {
        return img[index];
    });

    myImage::image_struct result = {
        ._image = std::move(resultImage),
        .width = inputImage.width,
        .height = inputImage.height,
        .channels = inputImage.channels,
    };

    return result;
}

myImage::image_struct  Shuffle::ImageShuffler::deshaffleImage(myImage::image_struct const &inputImage, std::string_view key)
{
    using imageType = decltype(inputImage._image)::value_type;

    auto keyHash = std::hash<std::string_view>{}(key);  

    std::vector<std::uint32_t> indexPixel(inputImage._image.size());
    
    std::iota(indexPixel.begin(), indexPixel.end(), 0);
    auto res = Shuffle::Worker<uint32_t>{}.shaffleSequence(indexPixel, keyHash);
    std::vector<std::uint8_t> resultImage(inputImage._image.size());
    for(auto i = 0; i < res.size(); ++i) {
        resultImage[res[i]] = inputImage._image[i];
    }
    // std::transform(res.begin(), res.end(), resultImage.begin(), [&img = inputImage._image](std::size_t index){
    //     return img[index];
    // });

    myImage::image_struct result = {
        ._image = std::move(resultImage),
        .width = inputImage.width,
        .height = inputImage.height,
        .channels = inputImage.channels,
    };

    return result;
}
