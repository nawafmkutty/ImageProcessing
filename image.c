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

            int x  = (img->pArr[h][w].red + img->pArr[h][w].blue + img->pArr[h][w].green) / 3 ;

            img->pArr[h][w].red = x;
            img->pArr[h][w].blue = x;
            img->pArr[h][w].green = x;

//                img->pArr[h][w].red = img->pArr[h][w].red * rGrayScale;
//                img->pArr[h][w].blue = img->pArr[h][w].blue * bGrayScale;
//                img->pArr[h][w].green = img->pArr[h][w].green * gGrayScale;
        }

    }


}

int image_get_height(Image* img) {
    return img->height;
}

int image_get_width(Image* img){
    return img->width;
}

struct Pixel** image_get_pixels(Image* img) {
    return img->pArr;
}

void image_destroy(Image** img) {

    free(img);

//    int i = 0;
//    while(img[i] != NULL)
//    {
//    for(int h = 0 ; h< img[i]->height  ; h++) {
//        for (int w = 0; w < img[i]->width ; w++) {
//            free(img[h][w].pArr);
//        }
//        free(img[h]);
//        }
//}


}



void image_apply_resize(Image* img, float factor){

    int newImageWidth = img->width * factor;
    int newImageHeight = img->height * factor;

//    img->height = img->height * factor;
//    img->width = img->width * factor;

    struct Pixel** pixelArray = (struct Pixel**) malloc(img->height * factor * sizeof(struct Pixel*));

    for(int i = 0 ; i < img->height * factor; i++ ) {
        pixelArray[i] = (struct Pixel*) malloc(img->width * factor * sizeof(struct Pixel));
    }

    struct Pixel** IgImagepixelArray = img->pArr;
    for(int h = 0 ; h< img->height * factor ; h++) {
        for (int w = 0; w < img->width * factor; w++) {

            int og_h = h/factor;
            int og_w = w/factor;

        pixelArray[h][w].red = IgImagepixelArray[og_h][og_w].red;
        pixelArray[h][w].green = IgImagepixelArray[og_h][og_w].green;
        pixelArray[h][w].blue = IgImagepixelArray[og_h][og_w].blue;

        }}

    img->height = newImageHeight;
    img->width = newImageWidth;
    img->pArr = pixelArray;
    free(IgImagepixelArray);

}


Image* image_create(struct Pixel** pArr, int width, int height) {
    struct Image *newImage = malloc(sizeof(struct Image));
    newImage->pArr = pArr;
    newImage->width = width;
    newImage->height=height;

    return newImage;
}