#ifndef _IMAGE_CODER_HPP_
#define _IMAGE_CODER_HPP_

#include <filesystem>
#include <string_view>

#include "ImageReader.hpp"
#include "ImageShaffler.hpp"

namespace myImage {
    class Codder {
    public:
        void ReadImagesWithEncode(std::filesystem::path const& firstInput, std::filesystem::path const& secondInput, std::string_view key);
        void ReadImages(std::filesystem::path const& firstInput, std::filesystem::path const& secondInput);
        void DecodeAndSave(std::filesystem::path const& input, std::string_view key, std::filesystem::path const& outputPath);
        void EncodeReading(std::string_view key);
        myImage::image_struct  ResizeImage(myImage::image_struct const& intputImage, std::size_t scaleFactor);
        void SaveResult(std::filesystem::path const& input);

    private:
        void MergeImage(myImage::image_struct const& firstImage, myImage::image_struct const& secondImage);
        

    private:
        Shuffle::ImageShuffler _worker;
        myImage::image_struct _resultImage;
        
    };
}


#endif // #ifndef _IMAGE_CODER_HPP_