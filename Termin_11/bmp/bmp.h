#ifndef BMP_H
#define BMP_H

typedef unsigned char PixelType;

typedef struct
{
    int width;
    int height;
    PixelType **data;
} BmpData;

typedef enum
{
    NO_ERROR,
    ERROR_UNKNOWN_FILE_FORMAT,
    ERROR_NO_MEMORY,
    ERROR_UNSUPPORTED_PIXEL_TYPE,
    ERROR_UNKNOWN_COMPRESSION,
    ERROR_IMAGE_DATA_NOT_FOUND,
} BmpErrorType;

BmpData *readBmpFile(const char *path);
void clearBmpData(BmpData *bmpData);
void showContent(const BmpData *bmpData);
BmpErrorType getLastError();

#endif