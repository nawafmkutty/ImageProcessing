
#ifndef IMAGEPROCESSING_BMPHANDLER_H
#define IMAGEPROCESSING_BMPHANDLER_H

/**
* Implementation of several functions to manipulate BMP files.
*
* Completion time: 6
*
* @author Nawaf Kutty, Ruben Acuna
* @version 1.0
*/

//#include <stdio.h>
#include "image.h"

struct BMP_Header {
    //TODO: Finish struct
    char headerSignature[2];
    int fileSize;
    char reserved01[2];
    char reserved02[2];
    int pixesOffset;
};

struct DIB_Header{
    //TODO: Finish struct
    int DIBHeaderSize;
    int ImageWidth;
    int ImageHeight;
    char planes[2];
    char bitsPerPixels[2];
    int compression;
    int imageSize;
    int xPixelMeter;
    int yPixelMeter;
    int colorIncolorTable;
    int impColorCount;

};

struct DIB_Header_Lazy{
    //TODO: Finish struct
    char dibHeaderValue[40];
};

/**
 * Read BMP header of a BMP file.
 *
 * @param  file: A pointer to the file being read
 * @param  header: Pointer to the destination BMP header
 */
void readBMPHeader(FILE* file, struct BMP_Header* header);

/**
 * Write BMP header of a file. Useful for creating a BMP file.
 *
 * @param  file: A pointer to the file being written
 * @param  header: The header to write to the file
 */
void writeBMPHeader(FILE* file, struct BMP_Header* header);

/**
 * Read DIB header from a BMP file.
 *
 * @param  file: A pointer to the file being read
 * @param  header: Pointer to the destination DIB header
 */
void readDIBHeader(FILE* file, struct DIB_Header* header);
void readDIBHeaderLazy(FILE* file, struct DIB_Header_Lazy* header);

/**
 * Write DIB header of a file. Useful for creating a BMP file.
 *
 * @param  file: A pointer to the file being written
 * @param  header: The header to write to the file
 */
void writeDIBHeader(FILE* file, struct DIB_Header* header);

/**
 * Make BMP header based on width and height. Useful for creating a BMP file.
 *
 * @param  header: Pointer to the destination DIB header
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
void makeBMPHeader(struct BMP_Header* header, int width, int height);

/**
* Make new DIB header based on width and height.Useful for creating a BMP file.
*
* @param  header: Pointer to the destination DIB header
* @param  width: Width of the image that this header is for
* @param  height: Height of the image that this header is for
*/
void makeDIBHeader(struct DIB_Header* header, int width, int height);

/**
 * Read Pixels from BMP file based on width and height.
 *
 * @param  file: A pointer to the file being read
 * @param  pArr: Pixel array to store the pixels being read
 * @param  width: Width of the pixel array of this image
 * @param  height: Height of the pixel array of this image
 */
void readPixelsBMP(FILE* file, struct Pixel** pArr, int width, int height);

/**
 * Write Pixels from BMP file based on width and height.
 *
 * @param  file: A pointer to the file being read or written
 * @param  pArr: Pixel array of the image to write to the file
 * @param  width: Width of the pixel array of this image
 * @param  height: Height of the pixel array of this image
 */
void writePixelsBMP(FILE* file, struct Pixel** pArr, int width, int height);


#endif //IMAGEPROCESSING_BMPHANDLER_H
