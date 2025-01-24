#ifndef ADRESS_TYPE
#define ADRESS_TYPE

#include "adressDef.h"

typedef struct adress_t{
        unsigned char first[middleValue];    //姓
        unsigned char second[middleValue];  //名
        unsigned char postNum[smallValue];   //郵便番号
        unsigned char address1[largeValue];   //住所1（都道府県・市区町村）
        unsigned char address2[largeValue];   //住所2（町名・番地）
        unsigned char email[largeValue];     //メールアドレス
        unsigned char tel1[middleValue];     //電話番号（自宅）
        unsigned char tel2[middleValue];     //電話番号（会社）
        unsigned int  age;                   //年齢
        unsigned char gender[smallValue];    //男性/女性
} adressType;

typedef struct item_t {
    int             pos;                        // Number
    unsigned char   dispName[64];               // 表示する文字列
    int             dispWith;                   // 表示する幅
    item_type       itype;                      // 変数の型の種類
    unsigned long   offset;                   // オフセット
} itemType;

// typedef struct menu_t {
//     int             pos;
//     unsigned char   menuName[64];
//     int             dispWith;
//     unsigned long   offset;
// }menuType;
#endif // !ADRESS_TYPE