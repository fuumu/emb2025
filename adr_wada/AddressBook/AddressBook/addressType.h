#ifndef address_TYPE
#define address_TYPE

#include "addressDef.h"

typedef struct address_t
{
    unsigned int  id[SMALLVALUE];       // 登録番号
    unsigned char first[MIDDLEVALUE];   // 姓
    unsigned char second[MIDDLEVALUE];  // addressTbl
    unsigned char postNum[SMALLVALUE];  // 郵便番号
    unsigned char address1[LARGEVALUE]; // 住所1（都道府県・市区町村）
    unsigned char address2[LARGEVALUE]; // 住所2（町addressTbl・番地）
    unsigned char email[LARGEVALUE];    // メールアドレス
    unsigned char tel1[MIDDLEVALUE];    // 電話番号（自宅）
    unsigned char tel2[MIDDLEVALUE];    // 電話番号（会社）
    unsigned int age;                   // 年齢
    unsigned char gender[SMALLVALUE];   // 男性/女性
} addressType;

typedef struct item_t
{
    int pos;                    // Number
    unsigned char dispName[64]; // 表示する文字列
    int dispWith;               // 表示する幅
    item_type itype;            // 変数の型の種類
    unsigned long offset;       // オフセット
} itemType;

 //menuType構造体の定義とmenus配列の設定
typedef struct {
    int id;
    int always;
    const char* name;
    unsigned int (*func)(addressType*, itemType const*, unsigned int);
} menuType;
#endif // !address_TYPE