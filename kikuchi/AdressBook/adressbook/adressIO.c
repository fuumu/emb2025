#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "adressType.h"
#if 0
int loadAdressData(adressType* adrTblPtr)
{
    FILE* file;
    int count = 0;

    file = fopen("adressDat.bin", "rb");
    if (file == NULL)
    {
        perror("Error opening file");
        return -1;
    }

    while (fread(&adrTblPtr[count], sizeof(adressType), 1, file) == 1)
    {
        count++;
    }

    fclose(file);
    return count;
}
//
int saveAdressData(adressType* adrTblPtr, int dataCnt)
{
    FILE* file;

    file = fopen("adressDat.bin", "wb");
    if (file == NULL)
    {
        perror("Error opening file");
        return -1;
    }

    if (fwrite(adrTblPtr, sizeof(adressType), dataCnt, file) != dataCnt)
    {
        perror("Error writing file");
        fclose(file);
        return -1;
    }

    fclose(file);
    return 0;
}

#endif



