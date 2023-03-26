#include "image.h"
#include "BMPHandler.h"

int main() {

    FILE *file_input = fopen("ttt.bmp","rb");
    //FILE *file_input = fopen("test2.bmp","rb");
    struct BMP_Header *header = malloc(sizeof(struct BMP_Header));

    readBMPHeader(file_input,header);
    struct DIB_Header *dibHeader = malloc(sizeof(struct DIB_Header));
    readDIBHeader(file_input,dibHeader);
    //struct DIB_Header_Lazy *dibHeader = malloc(sizeof(struct DIB_Header_Lazy));
    //readDIBHeaderLazy(file_input,dibHeader);

    struct Image* workingImage = malloc(sizeof(struct Image));

    workingImage->height = dibHeader->ImageHeight;
    workingImage->width = dibHeader->ImageWidth;
//        workingImage->height=2;
//        workingImage->width=2;


    struct Pixel** pixelArray = (struct Pixel**) malloc(workingImage->height * sizeof(struct Pixel*));

    for(int i = 0 ; i < workingImage->height; i++ ) {
        pixelArray[i] = (struct Pixel*) malloc(workingImage->width * sizeof(struct Pixel));
    }

    readPixelsBMP(file_input,pixelArray,workingImage->width,workingImage->height);

    //printf("The Values are:- %d , %d , %d \n",pixelArray[0][0].red ,pixelArray[0][0].green,pixelArray[0][0].blue);

    workingImage->pArr =pixelArray;
    printf("The Values are: \n\n");
    for(int h = 0 ; h< workingImage->height ; h++){
        for(int w =0 ; w < workingImage->width; w++) {

            printf("[ R:%u,G:%u,B%u ]",pixelArray[h][w].red,pixelArray[h][w].green,pixelArray[h][w].blue);

        }
        printf("\n");
    }

    fclose(file_input);
    free(header);
    free(dibHeader);
    free(pixelArray);
    return 0;
}
