#pragma once
#include "adressType.h"
#include "adressDef.h"
/*プロトタイプ宣言用ヘッダーファイル*/
#ifndef ADDRESSPROTO_H
#define ADDRESSPROTO_H

typedef struct item_t {
    int             pos;                        // Number
    unsigned char   dispName[64];               // 表示する文字列
    int             dispWith;                   // 表示する幅
    item_type       itype;                      // 変数の型の種類
    unsigned long  offset;                   // オフセット
} itemType;
void menu1(adressType* adressTblptr, int* dspTbl, itemType* items);
int loadAdressData(adressType* adrTblPtr);
int saveAdressData(adressType* adrTblPtr, int dataCnt);
int switchFn(adressType* adressTblptr, int com, int* dspTbl, int datacount, itemType * items);
void displayAll(adressType* adrTblPtr, int count, itemType *items);
void add(adressType* adressTbl, int count, itemType* items);
void sort(adressType* adrTblPtr);
void resetFlags(int* dspTbl, int size);
void search(adressType* adressTbl, int* dspTbl);
void edit(adressType* adressTbl, int count, itemType* items);
void del(adressType* adressTbl, int count);
void print_a_record(adressType* adressDat, itemType itemDat[]);


#endif