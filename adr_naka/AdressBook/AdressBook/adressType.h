#pragma once
/*�\���́A���[�U�[��`�p�w�b�_�[�t�@�C��*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// addressType.h
#ifndef ADDRESSTYPE_H
#define ADDRESSTYPE_H

typedef struct adress_t {
    unsigned char first[30];    // ��
    unsigned char secound[30]; // ��
    unsigned char postNum[8]; // �X�֔ԍ�1
    unsigned char adress1[255]; // �Z��1
    unsigned char adress2[255]; // �Z��2
    unsigned char email[255];  // ���[���A�h���X
    unsigned char tel1[32];    // �d�b�ԍ��i����j
    unsigned char tel2[32];    // �d�b�ԍ��i��Ёj
    unsigned char age[8];         // �N��
    unsigned char gender[8];  // ���� ("Female"/"Male")
} adressType;

#endif