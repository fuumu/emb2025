#ifndef address_PROTTO
#define address_PROTTO
#include "addressType.h"

unsigned int ViewFunction(addressType* addressDat, itemType const* const itemDat);                       // 住所録内の全てのデータを表示する関数
unsigned int AddFunction(addressType* addressDat, itemType const* const itemDat, unsigned int count);    // 住所録にデータを追加する関数
unsigned int DeleteFunction(addressType* addressDat, itemType const* const itemDat, unsigned int count); // 住所録のデータを削除する関数
unsigned int EditFunction(addressType* addressDat, itemType const* const itemDat, unsigned int count);   // 住所録のデータを編集する関数
// void SearchFunction(addressType* addressTbl, unsigned int count); //住所録のデータを検索する関数
// void SortFunction(addressType* addressTbl, unsigned int count); //住所録のデータをソートする関数
// int SaveFunction(addressType* addressTbl, unsigned int count); //ファイルにデータを保存する関数
// int LoadFunction(addressType* addressTbl); //ファイルからデータを読み込み関数

#endif // !address_PROTTO