#pragma once
#include <vector>
#include <fstream>

#define STB_IMAGE_IMPLEMENTATION
#define STBI_ASSERT(x)
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"


class Image{

public:
    int Width;
    int Height;

    std::vector<unsigned char> Data;

    void Load(char* filename){
        int channels=1;
        unsigned char* img = stbi_load(filename, &Width, &Height, &channels, 1);
        
        if(img==NULL)
        {return;}else{
            size_t total = static_cast<size_t>(Width)*Height*channels;
            Data.assign(img, img+total);
        }
        stbi_image_free(img);
        return;
    };

    void Save(char* filename){
        stbi_write_png(filename, Width, Height, 1, Data.data(), Width);
    };
};