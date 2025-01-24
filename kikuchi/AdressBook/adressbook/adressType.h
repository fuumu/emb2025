#include "adressDef.h"

#ifndef ADRESS_TYPE
#define ADRESS_TYPE

typedef  struct adress_t{
        unsigned char first[MAXNAME];    //��
        unsigned char secound[MAXNAME];  //��
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
    unsigned char   dispName[64];               // �\�����镶����
    int             dispWith;                   // �\�����镝
    item_type       itype;                      // �ϐ��̌^�̎��
    unsigned long  offset;                   // �I�t�Z�b�g
} itemType;



#endif
