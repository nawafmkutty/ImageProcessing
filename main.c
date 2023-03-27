#include "image.h"
#include "BMPHandler.h"

void ProcessOption(int option);
void userMenu();

struct ColorFilter {
    int red;
    int blue;
    int green;
};

struct userArguments {
    char inputImageName[20];
    int scale;
    float scaleFactor;
    int grayScale;
    int colorFilter;
    struct ColorFilter filterValues;
    int output;
    char outputFileName[20];

};


int main(int argc , char *argv[]) {

struct userArguments ua;
    strcpy(ua.inputImageName,argv[1]);
    ua.filterValues.red = 0;
    ua.filterValues.green = 0;
    ua.filterValues.blue = 0;
    ua.grayScale = 0;
    ua.colorFilter = 0;
    ua.scale = 0;


    for(int i = 2 ; i < argc ; i++ ) {

        if (strcmp(argv[i],"-w") == 0) {
            ua.grayScale = 1;
        }
        else if (strcmp(argv[i],"-s") == 0) {
            ua.scale = 1;
            i++;
            ua.scaleFactor = atof(argv[i]);
        } else if (strcmp(argv[i],"-r") == 0) {
            ua.colorFilter = 1;
            i++;
            ua.filterValues.red = atoi(argv[i]);
        }else if (strcmp(argv[i],"-g") == 0) {
            ua.colorFilter = 1;
            i++;
            ua.filterValues.green = atoi(argv[i]);
        } else if (strcmp(argv[i],"-b") == 0){
            ua.colorFilter = 1;
            i++;
            ua.filterValues.blue = atoi(argv[i]);
        } else if (strcmp(argv[i],"-o") == 0){
            ua.output = 1;
            i++;
            strcpy(ua.outputFileName,argv[i]);

        }
    }


    printf("The Parameters are \n");
    printf("Input File: %s \n",ua.inputImageName);
    printf("Gray scale Flag is :%d\n",ua.grayScale);
    printf("scale Flag is :%d\n",ua.scale);
    printf("scale Factor is :%f\n",ua.scaleFactor);
    printf("Color Filter Flag is :%d\n",ua.colorFilter);
    printf("Color Filter is R:%d , G:%d ,B:%d \n",ua.filterValues.red,ua.filterValues.green,ua.filterValues.blue);
    printf("Output flag is :%d\n",ua.output);
    printf("Output File: %s \n",ua.outputFileName);


    if(ua.inputImageName != NULL) {

        FILE *file_input = fopen(ua.inputImageName, "rb");
        if(file_input == NULL) {
            printf("Input file is not available \n");
            return EXIT_FAILURE;
        }

//    FILE *file_input = fopen("ttt.bmp", "rb");
    struct BMP_Header *header = malloc(sizeof(struct BMP_Header));
    readBMPHeader(file_input, header);
    struct DIB_Header *dibHeader = malloc(sizeof(struct DIB_Header));
    readDIBHeader(file_input, dibHeader);

    struct Image *workingImage = malloc(sizeof(struct Image));

    workingImage->height = dibHeader->ImageHeight;
    workingImage->width = dibHeader->ImageWidth;

    struct Pixel **pixelArray = (struct Pixel **) malloc(workingImage->height * sizeof(struct Pixel *));

    for (int i = 0; i < workingImage->height; i++) {
        pixelArray[i] = (struct Pixel *) malloc(workingImage->width * sizeof(struct Pixel));
    }

    readPixelsBMP(file_input, pixelArray, workingImage->width, workingImage->height);
    workingImage->pArr = pixelArray;
    printf("The Values are: \n\n");
//    for (int h = 0; h < workingImage->height; h++) {
//        for (int w = 0; w < workingImage->width; w++) {
//
//            printf("[ R:%u,G:%u,B:%u ]", pixelArray[h][w].red, pixelArray[h][w].green, pixelArray[h][w].blue);
//
//        }
//        printf("\n");
//    }
    fclose(file_input);

        if(ua.grayScale == 1) {
            image_apply_bw(workingImage);
        }

        if (ua.colorFilter == 1) {
            image_apply_colorshift(workingImage,ua.filterValues.red,ua.filterValues.green,ua.filterValues.blue);
        }

        if (ua.scale == 1) {
            image_apply_resize(workingImage,ua.scaleFactor);
            dibHeader->ImageWidth =workingImage->width;
            dibHeader->ImageHeight =workingImage->height;
        }
        FILE *file_out;
        if (ua.output == 1) {
            file_out = fopen(ua.outputFileName, "wb");
        } else {
            file_out = fopen("inputImage_copy.bmp", "wb");
        }


    writeBMPHeader(file_out, header);
    writeDIBHeader(file_out, dibHeader);
    writePixelsBMP(file_out, workingImage->pArr, workingImage->width, workingImage->height);
    fclose(file_out);


    free(header);
    free(dibHeader);

    image_destroy(workingImage);
    } else {
        printf("Error in File Name \n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

