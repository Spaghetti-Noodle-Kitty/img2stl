#pragma once
#include <vector>
#include <algorithm>

std::vector<unsigned char> pixelate(const std::vector<unsigned char> &in, int W, int H) {
    std::vector<unsigned char> out(W*H);

    for (int y=1; y<H-1; ++y){
        for(int x=1; x<W-1; ++x){
            std::vector<unsigned char> neighbours;
            for(int dy = -1; dy<=1; ++dy){
                for(int dx = -1; dx<=1; ++dx){
                    neighbours.push_back(in[(y+dy)*W+(x+dx)]);
                }
            }
            std::sort(neighbours.begin(), neighbours.end());
            out[y*W+x] = neighbours[4];
            neighbours.clear();
        }
    }

    for(int x=0; x<W; ++x){
        out[x]=in[x];
        out[(H-1)*W+x] = in[(H-1)*W+x];
    }

    for(int y=0; y<H; ++y){
        out[y*W] = in[y*W];
        out[y*W+(W-1)] = in[y*W+(W-1)];
    }
    return out;

}