
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
//�@adrTblPtr[MAXTBL]	�̃A�h���X
//	dispTbl[MAXTBL]		�̃A�h���X
//
int searchAdressData(adressType* adrTblPtr,  int* dispTbl)
{
	// ���ڂ̑I�� ��������@���̍��ڂ����Ō���
	//�@����������̓���
	//unsigned char	searchStr[32];

	//printf("�������������͂��Ă�������\n");
	//scanf_s("%s", searchStr, sizeof(searchStr));

	// �I���������ڂƌ��������񂪈�v���邩�ǂ����̔���

	for (int wi = 0; wi < MAXTBL; wi++) {
		//adrTblPtr[wi].adress1
		// searchStr
		//������̔�r
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
	// ���ڂ̑I�� ��������@���̍��ڂ����Ō���
	// �������~�����w��

	for (int wi = 0; wi < MAXTBL; wi++) {
		for (int wj = wi +1 ;wj < MAXTBL  ;wj++) {
			//adrTblPtr[wi].adress1
			//.adress1�@�̒l�ŏ����Ƀ\�[�g
			if(strcmp( adrTblPtr[wi].adress1, adrTblPtr[wj].adress1) > 0 ) {
				tmpdata = adrTblPtr[wi];
				adrTblPtr[wi] = adrTblPtr[wj];
				adrTblPtr[wj] = tmpdata;
			}
		}
	}
}

