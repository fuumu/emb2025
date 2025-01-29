#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "addressProto.h"
#include "addressType.h"

int SaveFunction(addressType* addressTbl, unsigned int count)
{
    FILE* file;
    errno_t err;

    // ファイルをバイナリ書き込みモードで開く
    err = fopen_s(&file, "addressTbl.bin", "wb");
    if (err != 0 || file == NULL)
    {
        perror("Error opening file");
        return -1;
    }

    // データを書き込む
    if (fwrite(addressTbl, sizeof(addressType), count, file) != count)
    {
        perror("Error writing file");
        fclose(file);
        return -1;
    }

    fclose(file);
    return 0;
}

int LoadFunction(addressType* addressTbl)
{
    FILE* file;
    errno_t err;
    int count = 0;

    // ファイルをバイナリ読み取りモードで開く
    err = fopen_s(&file, "addressTbl.bin", "rb");
    if (err != 0 || file == NULL)
    {
        perror("Error opening file");
        return -1;
    }

    // データを読み込む
    while (fread(&addressTbl[count], sizeof(addressType), 1, file) == 1)
    {
        count++;
    }

    fclose(file);
    return count;
}
