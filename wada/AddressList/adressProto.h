#ifndef ADRESS_PROTTO
#define ADRESS_PROTTO
#include "adressType.h"

unsigned int ViewFunction(adressType *adressDat, itemType const *const itemDat);                       // 住所録内の全てのデータを表示する関数
unsigned int AddFunction(adressType *adressDat, itemType const *const itemDat, unsigned int count);    // 住所録にデータを追加する関数
unsigned int DeleteFunction(adressType *adressDat, itemType const *const itemDat, unsigned int count); // 住所録のデータを削除する関数
unsigned int EditFunction(adressType *adressDat, itemType const *const itemDat, unsigned int count);   // 住所録のデータを編集する関数
// void SearchFunction(adressType* adressTbl, unsigned int count); //住所録のデータを検索する関数
// void SortFunction(adressType* adressTbl, unsigned int count); //住所録のデータをソートする関数
// int SaveFunction(adressType* adressTbl, unsigned int count); //ファイルにデータを保存する関数
// int LoadFunction(adressType* adressTbl); //ファイルからデータを読み込み関数

#endif // !ADRESS_PROTTO