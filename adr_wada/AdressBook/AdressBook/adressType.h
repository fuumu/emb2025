#ifndef ADRESS_TYPE
#define ADRESS_TYPE

#include "adressDef.h"

typedef struct adress_t
{
    unsigned int  id;       // �o�^�ԍ�
    unsigned char first[middleValue];   // ��
    unsigned char second[middleValue];  // ��
    unsigned char postNum[smallValue];  // �X�֔ԍ�
    unsigned char address1[largeValue]; // �Z��1�i�s���{���E�s�撬���j
    unsigned char address2[largeValue]; // �Z��2�i�����E�Ԓn�j
    unsigned char email[largeValue];    // ���[���A�h���X
    unsigned char tel1[middleValue];    // �d�b�ԍ��i����j
    unsigned char tel2[middleValue];    // �d�b�ԍ��i��Ёj
    unsigned int age;                   // �N��
    unsigned char gender[smallValue];   // �j��/����
} adressType;

typedef struct item_t
{
    int pos;                    // Number
    unsigned char dispName[64]; // �\�����镶����
    int dispWith;               // �\�����镝
    item_type itype;            // �ϐ��̌^�̎��
    unsigned long offset;       // �I�t�Z�b�g
} itemType;

//typedef struct menu_t
//{
//    int pos;
//    unsigned char menuName[64];
//    int dispWith;
//    unsigned long offset;
//} menuType;
#endif // !ADRESS_TYPE