/*
 * Vervollständigen Sie das Modul des folgenden Programms, das Grauwert-Bilder im BMP-Dateiformat einlesen und binär 
 * ausgeben soll.
 * Ergänzen Sie dazu die öffentliche Funktion showContent(...), die das Bild übergeben bekommt und dann alle Pixel mit 
 * einem Stern auf der Konsole ausgibt, die mindestens einen Grauwert von 128 haben.
 * Ergänzen Sie zudem die beiden internen Funktion readBmpHeader(...) und readBmpData(...).
 */

#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

int main(int argc, char *argv[])
{
    BmpData *img;

    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s <path to bmp file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    img = readBmpFile(argv[1]);

    if(img == NULL)
    {
        BmpErrorType error = getLastError();

        fprintf(stderr, "Error while reading %s --> ", argv[1]);

        if(error == ERROR_UNKNOWN_FILE_FORMAT)
            fprintf(stderr, "no bitmap file format\n");
        else if(error == ERROR_NO_MEMORY)
            fprintf(stderr, "no memory\n");
        else if(error == ERROR_UNSUPPORTED_PIXEL_TYPE)
            fprintf(stderr, "unsupported pixel type\n");
        else if(error == ERROR_UNKNOWN_COMPRESSION)
            fprintf(stderr, "unknown compression\n");
        else if(error == ERROR_IMAGE_DATA_NOT_FOUND)
            fprintf(stderr, "image data not found\n");
        else
            fprintf(stderr, "unknown reason\n");

        return EXIT_FAILURE;
    }
    else
    {
        showContent(img);
        clearBmpData(img);
    }

    return EXIT_SUCCESS;
}