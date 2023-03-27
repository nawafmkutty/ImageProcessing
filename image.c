#include "image.h"
#include "BMPHandler.h"

void image_apply_colorshift(Image* img, int rShift, int gShift, int bShift) {


    for(int h = 0 ; h< img->height ; h++){
        for(int w =0 ; w < img->width; w++) {

//            printf("[ R:%u,G:%u,B%u ]",pixelArray[h][w].red,pixelArray[h][w].green,pixelArray[h][w].blue);

if (img->pArr[h][w].red + rShift > 255) {
    img->pArr[h][w].red = 255;
}   else if(img->pArr[h][w].red + rShift < 0) {
    img->pArr[h][w].red = 0;
} else {
    img->pArr[h][w].red = img->pArr[h][w].red + rShift;
}

            if (img->pArr[h][w].blue + bShift > 255) {
                img->pArr[h][w].blue = 255;
            }   else if(img->pArr[h][w].blue + bShift < 0) {
                img->pArr[h][w].blue = 0;
            } else {
                img->pArr[h][w].blue = img->pArr[h][w].blue + bShift;
            }

            if (img->pArr[h][w].green + gShift > 255) {
                img->pArr[h][w].green = 255;
            }   else if(img->pArr[h][w].green + gShift < 0) {
                img->pArr[h][w].green = 0;
            } else {
                img->pArr[h][w].green = img->pArr[h][w].green + gShift;
            }
        }
    }

}

void image_apply_bw(Image* img) {

    float rGrayScale = 0.299;
    float gGrayScale = 0.587;
    float bGrayScale = 0.114;

    for(int h = 0 ; h< img->height ; h++) {
        for (int w = 0; w < img->width; w++) {
                img->pArr[h][w].red = img->pArr[h][w].red * rGrayScale;
                img->pArr[h][w].blue = img->pArr[h][w].blue * bGrayScale;
                img->pArr[h][w].green = img->pArr[h][w].green * gGrayScale;
        }

    }


}