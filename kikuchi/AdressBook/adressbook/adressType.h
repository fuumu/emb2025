#include "adressDef.h"

#ifndef ADRESS_TYPE
#define ADRESS_TYPE

typedef  struct adress_t{
        unsigned char first[MAXNAME];    //姓
        unsigned char secound[MAXNAME];  //名
        unsigned char postNum[SCHAR];   // zip code
        unsigned char adress1[MAXADRESS]; //
        unsigned char adress2[MAXADRESS]; //
        unsigned char email[MAXADRESS];   //
        unsigned char tel1[MAXNAME];     //
        unsigned char tel2[MAXNAME];     //
        unsigned int  age;          //
        unsigned char gender[SCHAR];   // Female/male
} adressType;



typedef struct item_t {
    int             pos;                        // Number
    unsigned char   dispName[64];               // 表示する文字列
    int             dispWith;                   // 表示する幅
    item_type       itype;                      // 変数の型の種類
    unsigned long  offset;                   // オフセット
} itemType;



#endif
