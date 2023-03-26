//
// Created by mcsonline on 26/03/23.
//

#include "image.h"
#include "BMPHandler.h"

void readBMPHeader(FILE *file_input, struct BMP_Header *header) {

    fread(header->headerSignature,sizeof(char) * 2,1,file_input);
    fread((int *) &header->fileSize, sizeof(int), 1, file_input);
    fread(header->reserved01, sizeof(short ), 1, file_input);
    fread(header->reserved02, sizeof(short ), 1, file_input);
    fread((int *) &header->pixesOffset, sizeof(int), 1, file_input);
//    printf("The output is %s , %d ,%d , %d ,%d  ",header->headerSignature,header->fileSize,header->reserved01,header->reserved02,header->pixesOffset);
}

void readDIBHeader(FILE* file, struct DIB_Header* header) {

//    fread(header->dibHeaderValue,sizeof(char) ,40,file);

    fread((int *) &header->DIBHeaderSize,sizeof(int),1,file);
    fread((int *) &header->ImageWidth,sizeof(int ),1,file);
    fread((int *) &header->ImageHeight,sizeof(int ),1,file);
    fread(header->planes,sizeof(char),2,file);
    fread(header->bitsPerPixels,sizeof(short),1,file);
    fread((int *) &header->xPixelMeter,sizeof(int ),1,file);
    fread((int *) &header->yPixelMeter,sizeof(int ),1,file);
    fread((int *) &header->colorIncolorTable,sizeof(int ),1,file);
    fread((int *) &header->impColorCount,sizeof(int ),1,file);
}