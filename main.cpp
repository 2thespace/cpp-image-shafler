#include <iostream>
#include <vector>
#include <fstream>
#include <cassert>

#include "Shaffler.hpp"
#include "ImageReader.hpp"
#include "ImageShaffler.hpp"
#include "ImageCoder.hpp"

void ShaffleTest() {
    using my_type = std::uint32_t;
    std::vector<my_type> v(10);
    std::iota(v.begin(), v.end(), 0);
    auto key = std::hash<std::string>{}("HelloWorld2");
    std::cout << "K =" << key << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    auto res = Shuffle::Worker<my_type>{}.shaffleSequence(v, key);
    std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, " "));
    auto desh = Shuffle::Worker<my_type>{}.deshaffleSequence(res);
    std::cout << std::endl;
    std::copy(desh.begin(), desh.end(), std::ostream_iterator<int>(std::cout, " "));
}


void ImageTest() {
    std::cout << "Start image Test" << std::endl;
    auto input_image = myImage::ReadImage("saved_cimg1.png");
    auto shaffled_image = Shuffle::ImageShuffler{}.shaffleImage(input_image, "helloworld");
    myImage::SaveImage(shaffled_image, "shaffled_image.png");
    auto deshaffled_image = Shuffle::ImageShuffler{}.deshaffleImage(shaffled_image, "helloworld");
    myImage::SaveImage(deshaffled_image, "deshaffled_image.png");
}

void MergeTest() {
    std::cout << "Start merge Test" << std::endl;
    myImage::Codder merger;
    merger.ReadImagesWithEncode("inpit_big.png", "input_image1.png", "helloworld");
    // merger.ReadImages("inpit_big.png", "input_image1.png");
    merger.SaveResult("result_image.png");
    merger.DecodeAndSave("result_image.png",  "helloworld", "decoding_image.png");
}

void Test() {
    ShaffleTest();
    ImageTest();
    MergeTest();
}

int main() {
    Test();
    return 0;
}