#ifndef address_PROTTO
#define address_PROTTO
#include "addressType.h"

//unsigned int generateUniqueId(addressType* addressTbl, unsigned int count); // 住所録のIDを生成する関数
void DisplayMenu(menuType* menus, unsigned int count);
unsigned int HeaderFunction(itemType const* const itemTbl); // 住所録のヘッダーを表示する関数
unsigned int ViewFunction(addressType* addressTbl, itemType const* const itemTbl, unsigned int count);                       // 住所録内の全てのデータを表示する関数
unsigned int AddFunction(addressType* addressTbl, itemType const* const itemTbl, unsigned int count);    // 住所録にデータを追加する関数
unsigned int DeleteFunction(addressType* addressTbl, itemType const* const itemTbl, unsigned int count); // 住所録のデータを削除する関数
unsigned int EditFunction(addressType* addressTbl, itemType const* const itemTbl, unsigned int count);   // 住所録のデータを編集する関数
unsigned int SearchFunction(addressType* addressTbl, itemType const* const itemTbl, unsigned int count); //住所録のデータを検索する関数
unsigned int SortFunction(addressType* addressTbl, itemType const* const itemTbl, unsigned int count); //住所録のデータをソートする関数
unsigned int SaveFunction(addressType* addressTbl, itemType const* const itemTbl, unsigned int count); //ファイルにデータを保存する関数
unsigned int LoadFunction(addressType* addressTbl, itemType const* const itemTbl, unsigned int count); //ファイルからデータを読み込み関数
#endif // !address_PROTTO