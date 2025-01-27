#pragma once
/*構造体、ユーザー定義用ヘッダーファイル*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// addressType.h
#ifndef ADDRESSTYPE_H
#define ADDRESSTYPE_H

typedef struct adress_t {
    unsigned char first[30];    // 姓
    unsigned char secound[30]; // 名
    unsigned char postNum[8]; // 郵便番号1
    unsigned char adress1[255]; // 住所1
    unsigned char adress2[255]; // 住所2
    unsigned char email[255];  // メールアドレス
    unsigned char tel1[32];    // 電話番号（自宅）
    unsigned char tel2[32];    // 電話番号（会社）
    unsigned char age[8];         // 年齢
    unsigned char gender[8];  // 性別 ("Female"/"Male")
} adressType;

#endif