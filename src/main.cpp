#include <iostream>
#include <vector>

#include "image.hpp"
#include "pixelate.hpp"
#include "dot.hpp"
#include "img2stl.hpp"


int main(int argc, char *argv[])
{
    char* imageSrc;
    char* stlPath;
    char bwPath[256];

    if(argc<=1) {
        std::cout << "usage: img2stl file.png outputname.stl\n";
        return 1;

    } else {
        imageSrc = argv[1];
        stlPath = argv[2];
        strncpy(bwPath, imageSrc, strlen(imageSrc)-3);
        strcat(bwPath, "bw.png");
    }

    Image _img;
    _img.Load(imageSrc);
    _img.Data = pixelate(_img.Data, _img.Width, _img.Height);
    _img.Data = dot(_img.Data, _img.Width, _img.Height);
    _img.Save(bwPath);

    img2stl(_img.Data, _img.Width, _img.Height, stlPath);


}
