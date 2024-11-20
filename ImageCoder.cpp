#include "ImageCoder.hpp"
#include "CImg.h"

void myImage::Codder::ReadImagesWithEncode(std::filesystem::path const &firstInput, std::filesystem::path const &secondInput, std::string_view key)
{
    auto first_image = myImage::ReadImage(firstInput);
    auto second_image = myImage::ReadImage(secondInput);
    auto width_scale = first_image.width/second_image.width;
    auto height_scale = first_image.height/second_image.height;

    if(std::max(width_scale, height_scale) < 4) {
        auto scale_factor = width_scale == 0 ?  second_image.width/first_image.width*4: 4;
        second_image = ResizeImage(second_image, scale_factor);

    }
    auto encodeImage = Shuffle::ImageShuffler{}.shaffleImage(second_image, key);

    MergeImage(first_image, encodeImage);
}

void myImage::Codder::ReadImages(std::filesystem::path const &firstInput, std::filesystem::path const &secondInput)
{
     auto first_image = myImage::ReadImage(firstInput);
    auto second_image = myImage::ReadImage(secondInput);
    auto width_scale = first_image.width/second_image.width;
    auto height_scale = first_image.height/second_image.height;

    if(std::max(width_scale, height_scale) < 4) {
        auto scale_factor = width_scale == 0 ?  second_image.width/first_image.width*4: 4;
        second_image = ResizeImage(second_image, scale_factor);
    }
    MergeImage(first_image, second_image);
}

void myImage::Codder::DecodeAndSave(std::filesystem::path const &input, std::string_view key, std::filesystem::path const &outputPath)
{
    auto encoding_image = myImage::ReadImage(input);
    std::size_t width = encoding_image.width/4;
    std::size_t height = encoding_image.height/4;
    std::size_t channels =  encoding_image.channels;
    auto encodingVector = encoding_image._image;
    std::vector<decltype(encoding_image._image)::value_type> imageVector;
    imageVector.reserve(encodingVector.size());
    for(auto i =0; i < encodingVector.size(); i+=4) {
        if(encoding_image._image[i]= 'm' && encoding_image._image[i +1] == 'd' && encoding_image._image[i+2] == 'e' && encoding_image._image[i+3] == 'c') {
            std::vector<std::uint8_t> tmp = {encoding_image._image.begin() + i+4, encoding_image._image.begin() +i+20};
            std::memcpy(&width, &tmp[0], 4);
            std::memcpy(&height, &tmp[4], 4);
            std::memcpy(&channels, &tmp[8], 4);
            break;
        }
        imageVector.push_back(encodingVector[i]);
    }
    myImage::image_struct encode_result;
    encode_result._image = std::move(imageVector);
    encode_result.channels = channels;
    encode_result.width = width;
    encode_result.height = height;
    auto result = Shuffle::ImageShuffler{}.deshaffleImage(encode_result, key);
    myImage::SaveImage(result, outputPath);
}

void myImage::Codder::EncodeReading(std::string_view key)
{
}

myImage::image_struct myImage::Codder::ResizeImage(myImage::image_struct const &inputImage, std::size_t scaleFactor)
{
    cimg_library::CImg<std::uint8_t> scaledImage(inputImage._image.data(), inputImage.width, inputImage.height, 1, inputImage.channels);
    scaledImage.resize(inputImage.width/scaleFactor, inputImage.height/scaleFactor, 1, 3 ,3);
    myImage::image_struct result;
    result.channels = scaledImage.spectrum();
    result.width = scaledImage.width();
    result.height = scaledImage.height();
    result._image = {scaledImage.data(), scaledImage.data() + scaledImage.size()};
    return result;
}

void myImage::Codder::SaveResult(std::filesystem::path const &input)
{
    myImage::SaveImage(_resultImage, input);
}

void myImage::Codder::MergeImage(myImage::image_struct const &firstImage, myImage::image_struct const &secondImage)
{
    auto resultVector = firstImage._image;
    auto secondVector = secondImage._image;
    for(auto i = 0, j = 0; j < secondImage._image.size(); i+=4, j++){
        resultVector[i] = secondVector[j];
    }
    auto last_index = 4*secondImage._image.size();
    resultVector[last_index] = 'm';
    resultVector[last_index+1] = 'd';
    resultVector[last_index+2] = 'e';
    resultVector[last_index+3] = 'c';
    std::memcpy(&resultVector[last_index+4], &secondImage.width, 4);
    std::memcpy(&resultVector[last_index+8], &secondImage.height, 4);
    std::memcpy(&resultVector[last_index+12], &secondImage.channels, 4);
    std::vector<std::uint8_t> tmp = {resultVector.begin() + last_index+4, resultVector.begin() + last_index+20};
    _resultImage.channels = firstImage.channels;
    _resultImage.width =  firstImage.width;
    _resultImage.height = firstImage.height;
    _resultImage._image = std::move(resultVector);
}


