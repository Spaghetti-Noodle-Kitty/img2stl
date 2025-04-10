#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define THRESHOLD 128
#define WHITE 255
#define BLACK 0
#define SPACING 8

std::vector<unsigned char> dot(std::vector<unsigned char>& image, int Width, int Height) {
    std::vector<unsigned char> result(Width*Height, WHITE);

    for(int y=0; y<Height; ++y){
        for(int x=0; x<Width; ++x){
            int idx = y*Width+x;
            unsigned char px = image[idx];

            if(px < THRESHOLD){
                if((x+y)%SPACING==0){
                    result[idx] = BLACK;
                }
            }
        }
    }
    return result;
}