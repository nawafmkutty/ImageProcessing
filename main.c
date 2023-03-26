#include "image.h"
#include "BMPHandler.h"

int main() {

    FILE *file_input = fopen("ttt.bmp","rb");
    struct BMP_Header *header = malloc(sizeof(struct BMP_Header));

    readBMPHeader(file_input,header);
    struct DIB_Header *dibHeader = malloc(sizeof(struct DIB_Header));
    readDIBHeader(file_input,dibHeader);






    fclose(file_input);

    free(header);
    free(dibHeader);
    return 0;
}
