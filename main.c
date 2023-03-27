#include "image.h"
#include "BMPHandler.h"

void ProcessOption(int option);
void userMenu();

int main() {

    FILE *file_input = fopen("ttt.bmp","rb");
    struct BMP_Header *header = malloc(sizeof(struct BMP_Header));

    readBMPHeader(file_input,header);
    struct DIB_Header *dibHeader = malloc(sizeof(struct DIB_Header));
    readDIBHeader(file_input,dibHeader);

    struct Image* workingImage = malloc(sizeof(struct Image));

    workingImage->height = dibHeader->ImageHeight;
    workingImage->width = dibHeader->ImageWidth;

    struct Pixel** pixelArray = (struct Pixel**) malloc(workingImage->height * sizeof(struct Pixel*));

    for(int i = 0 ; i < workingImage->height; i++ ) {
        pixelArray[i] = (struct Pixel*) malloc(workingImage->width * sizeof(struct Pixel));
    }

    readPixelsBMP(file_input,pixelArray,workingImage->width,workingImage->height);
    workingImage->pArr =pixelArray;
    printf("The Values are: \n\n");
    for(int h = 0 ; h< workingImage->height ; h++){
        for(int w =0 ; w < workingImage->width; w++) {

            printf("[ R:%u,G:%u,B%u ]",pixelArray[h][w].red,pixelArray[h][w].green,pixelArray[h][w].blue);

        }
        printf("\n");
    }


    fclose(file_input);


    //image_apply_colorshift(workingImage,56,45,78);
    image_apply_bw(workingImage);

    FILE *file_out = fopen("ttt_Nawaf_copy_bw.bmp","wb");

    writeBMPHeader(file_out,header);
    writeDIBHeader(file_out,dibHeader);
    writePixelsBMP(file_out,workingImage->pArr,workingImage->width,workingImage->height);
    fclose(file_out);





    free(header);
    free(dibHeader);
    free(pixelArray);
    return 0;
}

