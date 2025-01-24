#include "adressType.h"
#include "adressProt.h"
void print_a_record(adressType* adressDat, itemType itemDat[]) {

	unsigned char    fmt[32];
	unsigned char* charPtr2;
	int* intPtr;
	for (int wi = 0;wi < 16;wi++) {
		if (itemDat[wi].pos < 0) {
			break;
		}
		else {
			if (itemDat[wi].itype == TYPE_STRING) {
				sprintf_s(fmt, sizeof(fmt), "%%-%ds ", itemDat[wi].dispWith);        // タイトル用の幅を決定してアイテムごとのフォーマットを作成

				charPtr2 = ((unsigned char*)adressDat + itemDat[wi].offset);         // 型キャストと文法を修正
				printf(fmt, charPtr2);
			}
			else if (itemDat[wi].itype == TYPE_INT) {
				sprintf_s(fmt, sizeof(fmt), "%%-%dd ", itemDat[wi].dispWith);        // タイトル用の幅を決定してアイテムごとのフォーマットを作成

				intPtr = ((int*)adressDat + itemDat[wi].offset);         // 型キャストと文法を修正
				printf(fmt, *intPtr);
			}
		}
	}
	printf("\n");
}