#pragma once
#include <vector>
#include <fstream>

#define HEIGHT_SCALE 1.0f

void WriteCube(std::ofstream &out, float x, float y, float z, float size){
    const float s = size;

    struct Face{
        float vx[3][3];
    };

    std::vector<Face> faces = {
        {{{x, y, z + s}, {x + s, y, z + s}, {x, y + s, z + s}}},
        {{{x + s, y, z + s}, {x + s, y + s, z + s}, {x, y + s, z + s}}},
        {{{x, y, z}, {x, y + s, z}, {x + s, y, z}}},
        {{{x + s, y, z}, {x, y + s, z}, {x + s, y + s, z}}},
        {{{x, y + s, z}, {x, y + s, z + s}, {x + s, y + s, z}}},
        {{{x + s, y + s, z}, {x, y + s, z + s}, {x + s, y + s, z + s}}},
        {{{x, y, z}, {x + s, y, z}, {x, y, z + s}}},
        {{{x + s, y, z}, {x + s, y, z + s}, {x, y, z + s}}},
        {{{x, y, z}, {x, y, z + s}, {x, y + s, z}}},
        {{{x, y + s, z}, {x, y, z + s}, {x, y + s, z + s}}},
        {{{x + s, y, z}, {x + s, y + s, z}, {x + s, y, z + s}}},
        {{{x + s, y + s, z}, {x + s, y + s, z + s}, {x + s, y, z + s}}},
    };
    
    for(const auto& f:faces) {
        out << "facet normal 0 0 0\n  outer loop\n";
        for(int i= 0; i<3; ++i){
            out << "    vertex " << f.vx[i][0] << " " << f.vx[i][1] << " " << f.vx[i][2] << "\n";
        }
        out << "  endloop\nendfacet\n";
    }

}

void img2stl(const std::vector<unsigned char>&image, int W, int H, char* filename){
    std::ofstream out(filename);
    out << "solid pixel_model\n";
    for (int y=0; y<H; ++y) {
        for (int x=0; x<W; ++x) {
            int idx=y*W+x;
            if (image[idx] < 128) {
                WriteCube(out, static_cast<float>(x), static_cast<float>(H - y - 1), 0.0f, HEIGHT_SCALE);
            }
        }
    }

    out << "endsolid pixel_model\n";
    out.close();
}