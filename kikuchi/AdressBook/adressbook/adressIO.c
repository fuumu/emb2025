#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// KIKUCHI

#include "adressType.h"
#if 1
int loadAdressData(adressType* adrTblPtr)
{
    FILE* file;
    errno_t err;
    int count = 0;

    err = fopen_s(&file, "adressDat.bin", "rb");
    if (file == NULL)
    {
        perror("Error opening file");
        return -1;
    }
    if (err != 0) { // エラー処理 
        printf("ファイルを開くのに失敗しました\n");
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
    errno_t err;

    err = fopen_s(&file, "adressDat.bin", "wb");
    if (file == NULL)
    {
        perror("Error opening file");
        return -1;
    }
    if (err != 0) { // エラー処理
        printf("ファイルを開くのに失敗しました\n"); 
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







