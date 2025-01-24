
#include <stdio.h>
#include <string.h>


#include "adressDef.h"
#include "adressType.h"
#include "adressProto.h"

int saveDataDelete(adressType * adrTblPtr, int dataPos) {

	for (int wi = dataPos;wi < MAXTBL - 1; wi++) {
		adrTblPtr[wi] = adrTblPtr[wi+1];
	}
	return 0;

}
//
//	Search TOP
//
//　adrTblPtr[MAXTBL]	のアドレス
//	dispTbl[MAXTBL]		のアドレス
//
int searchAdressData(adressType* adrTblPtr,  int* dispTbl)
{
	// 項目の選択 いったん　仮の項目だけで検討
	//　検索文字列の入力
	//unsigned char	searchStr[32];

	//printf("検索文字列を入力してください\n");
	//scanf_s("%s", searchStr, sizeof(searchStr));

	// 選択した項目と検索文字列が一致するかどうかの判定

	for (int wi = 0; wi < MAXTBL; wi++) {
		//adrTblPtr[wi].adress1
		// searchStr
		//文字列の比較
		if (1) {
			dispTbl[wi] = 1;
		}
		else {
			dispTbl[wi] = 0;
		}
	}
}

int sortAdressData(adressType* adrTblPtr) {

	adressType tmpdata;
	// 項目の選択 いったん　仮の項目だけで検討
	// 昇順か降順か指定

	for (int wi = 0; wi < MAXTBL; wi++) {
		for (int wj = wi +1 ;wj < MAXTBL  ;wj++) {
			//adrTblPtr[wi].adress1
			//.adress1　の値で昇順にソート
			if(strcmp( adrTblPtr[wi].adress1, adrTblPtr[wj].adress1) > 0 ) {
				tmpdata = adrTblPtr[wi];
				adrTblPtr[wi] = adrTblPtr[wj];
				adrTblPtr[wj] = tmpdata;
			}
		}
	}
}

