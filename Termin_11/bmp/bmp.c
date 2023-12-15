#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

static BmpErrorType lastError = NO_ERROR;

BmpErrorType getLastError()
{
    return lastError;
}

void showContent(const BmpData *bmpData)
{

}

void clearBmpData(BmpData *bmpData)
{
    if(bmpData->data != NULL)
    {
        for(int i = 0; i < bmpData->height; i++)
        {
            free(bmpData->data[i]);
        }
    }

    free(bmpData->data);
    free(bmpData);
}

/*
 * Zu lesende Informationen (bei Fehler entsprechenden Fehlercode zurückgeben, ansonsten NO_ERROR):
 * Bitmap-Datei?                                  --> BM am Anfang?
 * Offset zu Bilddaten                            --> 4 Bytes ab Offset 0xa
 * Bildbreite                                     --> 4 Bytes ab Offset 0x12
 * Bildhöhe                                       --> 4 Bytes ab Offset 0x16 (bzw. nach Bildbreite)
 * Anzahl an Bits pro Pixel
 * (unterstützt wird nur die Größe von Pixeltype) --> 2 Bytes ab Offset 0x1c
 * Kompressionsart (nur 0 (keine) ist erlaubt)    --> 4 Bytes ab Offset 0x1e
 */
static BmpErrorType readBmpHeader(FILE *file, BmpData *bmpData, unsigned int *offsetToImageData)
{

    return NO_ERROR;
}

/*
 * Bilddaten ab offset lesen. Bei Fehler entsprechenden Fehlercode zurückgeben bzw. ansonsten NO_ERROR
 * Hinweis: Speicher muss noch reserviert werden.
 */
static BmpErrorType readBmpData(FILE *file, unsigned int offset, BmpData *bmpData)
{
    return NO_ERROR;
}

BmpData *readBmpFile(const char *path)
{
    FILE *bmpFile = fopen(path, "rb");

    if(bmpFile != NULL)
    {
        BmpData *bmpData = (BmpData *)calloc(1, sizeof(BmpData));

        if(bmpData != NULL)
        {
            unsigned int offsetToImageData = 0;
            lastError = readBmpHeader(bmpFile, bmpData, &offsetToImageData);
            if(lastError == NO_ERROR)
            {
                lastError = readBmpData(bmpFile, offsetToImageData, bmpData);
                if(lastError != NO_ERROR)
                {
                    clearBmpData(bmpData);
                    bmpData = NULL;
                }
            }
            else
            {
                clearBmpData(bmpData);
                bmpData = NULL;
            }
        }

        fclose(bmpFile);

        return bmpData;
    }

    return NULL;
}