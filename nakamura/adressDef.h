#pragma once
/*DEFINEを保存するファイル*/
#ifndef ADDRESSDEF_H
#define ADDRESSDEF_H

#define MAX_RECORDS 16
#define DATA_FILE "adressDat.bin"
int datacount;

typedef enum item_type {
	TYPE_STRING = 0,
	TYPE_INT
} item_type;


#endif