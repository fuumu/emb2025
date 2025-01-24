#include <stdio.h>
#include <string.h>


#include "adressDef.h"
#include "adressType.h"
#include "adressProto.h"




void itoa(int num, char* str) {
	sprintf_s(str,20, "%d", num);
}

void main() {

	// �Z���^�f�[�^�{��
#define DMYADRESSDAT
#ifndef DMYADRESSDAT
	adressType adressTbl[MAXTBL];
#else
	adressType adressTbl[MAXTBL] = {
		{"first",
		 "secound",
		 "postNum",
		 "adress",
		 "adress2",
		 "email",
		 "tel1",
		 "tel2",
		 25,
		 "male"},
		{"2first",
		 "2secound",
		 "2postNum",
		 "2adress",
		 "2adress2",
		 "2email",
		 "2tel1",
		 "2tel2",
		 25,
		 "2male"},
	};
#endif


	itemType  items[] = {
			{ 1,"��",10,TYPE_STRING,0x0L},
			{ 2,"��",10,TYPE_STRING,(unsigned long)(&adressTbl[0].secound[0] - &adressTbl[0].first[0])},
			{ 3,"�X�֔ԍ�",10,TYPE_STRING,(unsigned long)(adressTbl[0].postNum - adressTbl[0].first),},
			{ 4,"�Z��1",20,TYPE_STRING,(unsigned long)(adressTbl[0].adress1 - adressTbl[0].first)},
			{ 5,"�Z��2",20,TYPE_STRING,(unsigned long)(adressTbl[0].adress2 - adressTbl[0].first)},
			{ 6,"mail",10,TYPE_STRING,(unsigned long)(adressTbl[0].email - adressTbl[0].first)},
			{ 7,"TEL1",10,TYPE_STRING,(unsigned long)(adressTbl[0].tel1 - adressTbl[0].first)},
			{ 8,"TEL2",10,TYPE_STRING,(unsigned long)(adressTbl[0].tel2 - adressTbl[0].first)},
			{ 9,"AGE",10,TYPE_INT,(unsigned long)(&adressTbl[0].age - &adressTbl[0])},
			{ 10,"GENDER",10,TYPE_STRING,(unsigned long)(adressTbl[0].gender - adressTbl[0].first)},
			{ -1,},			// Pos == -1 �͏I���̈Ӗ���\���܂�
	};


	//typedef struct item_t {
	//	int             pos;                        // Number
	//	unsigned char   dispName[64];               // �\�����镶����
	//	int             dispWith;                   // �\�����镝
	//	item_type       itype;                      // �ϐ��̌^�̎��
	//	unsigned        offset;                 // �I�t�Z�b�g
	//} itemType;


	unsigned char	fmt[32];
	unsigned char	fmtstr[256]= "";

	int	dispOn[MAXTBL];	// �T�[�`���ĕ\�����邩�ǂ����̃X�C�b�`


	int itemCnt = sizeof(items) / sizeof(itemType);

	// �\���X�C�b�`�̏�����
	for (int wi = 0;wi < MAXTBL;wi++) {
		dispOn[wi] = 1;
	}


#if 0
	itemType items[] = {
		{ 1,"��",10,TYPE_STRING},
		{ 2,"��",10,TYPE_STRING},
		{ 3,"�X�֔ԍ�",10,TYPE_STRING},
		{ 4,"�Z��1",20,TYPE_STRING},
		{ 5,"�Z��2",20,TYPE_STRING},
		{ 6,"mail",10,TYPE_STRING},
		{ 7,"TEL1",10,TYPE_STRING},
		{ 8,"TEL2",10,TYPE_STRING},
		{ 9,"AGE",10,TYPE_INT},
		{ 10,"GENDER",10,TYPE_STRING},
	};
#endif

	for (int wi =  0; wi < itemCnt ; wi++) {
		sprintf_s(fmt, sizeof(fmt), "%%-%ds ", items[wi].dispWith);		// �^�C�g���p�̕������肵�ăA�C�e�����Ƃ̃t�H�[�}�b�g���쐬
		strcat_s(fmtstr,sizeof(fmtstr), fmt);							// 1�s���̃t�H�[�}�b�g������ɏ����ǉ�
	}
	strcat_s(fmtstr, sizeof(fmtstr), "\n");
	                                                
	unsigned char jkjk[20];

	printf(fmtstr, items[0].dispName, items[1].dispName, items[2].dispName, items[3].dispName, items[4].dispName, items[5].dispName, items[6].dispName, items[7].dispName, items[8].dispName, items[9].dispName);

	itoa(adressTbl[0].age, jkjk);
	printf(fmtstr, adressTbl[0].first, adressTbl[0].secound, adressTbl[0].postNum, adressTbl[0].adress1, adressTbl[0].adress2, adressTbl[0].email, adressTbl[0].tel1, adressTbl[0].tel2, jkjk, adressTbl[0].gender);

	itoa(adressTbl[1].age, jkjk);
	printf(fmtstr, adressTbl[1].first, adressTbl[1].secound, adressTbl[1].postNum, adressTbl[1].adress1, adressTbl[1].adress2, adressTbl[1].email, adressTbl[1].tel1, adressTbl[1].tel2, jkjk, adressTbl[1].gender);

	printf("%-10s %-10s (normal)\n", adressTbl[0].first, adressTbl[0].secound);
	
	unsigned char* charPtr;
	charPtr = adressTbl[0].secound;
	printf("%-10s %-10s (charPtr)\n", adressTbl[0].first, charPtr);


	unsigned char* charPtr2;
	charPtr2 = ((unsigned char*)&adressTbl[0].first + items[1].offset); // �^�L���X�g�ƕ��@���C��
	printf("%-10s %-10s (charPtr2[0])\n", adressTbl[0].first, charPtr2);

	charPtr2 = ((unsigned char*)&adressTbl[0].first + items[1].offset); // �^�L���X�g�ƕ��@���C��
	printf("%-10s %-10s (charPtr2[1])\n", adressTbl[0].first, charPtr2);

	charPtr2 = ((unsigned char*)&adressTbl[1].first + items[2].offset); // �^�L���X�g�ƕ��@���C��
	printf("%-10s %-10s (charPtr2[0] items[2])\n", adressTbl[1].first, charPtr2);

	charPtr2 = ((unsigned char*)&adressTbl[1].first + items[2].offset); // �^�L���X�g�ƕ��@���C��
	printf("%-10s %-10s (charPtr2[1] items[2])\n", adressTbl[1].first, charPtr2);

	//charPtr2 = ((unsigned char*)&adressTbl[0] + items[2].offset); // �^�L���X�g�ƕ��@���C��
	//printf("%-10s %-10s (charPtr2[0] items[2] first�Ȃ�)\n", adressTbl[0].first, charPtr2);

	//charPtr2 = ((unsigned char*)&adressTbl[1] + items[2].offset); // �^�L���X�g�ƕ��@���C��
	//printf("%-10s %-10s (charPtr2[1] items[2] first�Ȃ�)\n", adressTbl[0].first, charPtr2);

	//printf("%-10s ", adressTbl[0].first);

	//charPtr2 = ((unsigned char*)&adressTbl[0] + items[1].offset); // �^�L���X�g�ƕ��@���C��
	//printf("%-10s ", charPtr2);

	//charPtr2 = ((unsigned char*)&adressTbl[0] + items[2].offset); // �^�L���X�g�ƕ��@���C��
	//printf("%-10s ", charPtr2);

	//printf("�@(�΂�΂�)\n");


	printf("please select item\n");
		for (int wj = 0;wj < itemCnt; wj++) {
		printf("%02d:%s\n", items[wj].pos, items[wj].dispName);
	}

		print1record(&adressTbl[0], items);
		print1record(&adressTbl[1], items);
}

// adressType adressTbl
// itemType items[]
// 1�A�C�e�����\������
// itemDat�̏������Ɍʂ̕ϐ��̃A�h���X���@�擪�A�h���X�ƃI�t�Z�b�g����v�Z����Print����
// �f�[�^�̐��� itemdat��Pos���|1�ɂȂ�܂ł̌���
// �S���̃G�[�^��Print������Ō��"\n"��print
//�@�O�̂��߂� itemdat�̌������s���͈͂́@0����16�܂łƂ���

void print1record(adressType * adressDat, itemType const * itemDat) {

	unsigned char	fmt[32];
	unsigned char* charPtr2;
	int	* intPtr;


	//fmt = "AAA";
	//fmt[0] = "AAA";
	//&fmt[0] = "AAA";
	//strncpy(fmt, "AAA",sizeof(fmt));

	for (int wi = 0;wi < 16;wi++) {
		if (itemDat[wi].pos < 0) {
			break;
		}
		else {
			if (itemDat[wi].itype == TYPE_STRING) {
				sprintf_s(fmt, sizeof(fmt), "%%-%ds ", itemDat[wi].dispWith);		// �^�C�g���p�̕������肵�ăA�C�e�����Ƃ̃t�H�[�}�b�g���쐬

				charPtr2 = ((unsigned char*)adressDat + itemDat[wi].offset);		 // �^�L���X�g�ƕ��@���C��
				printf(fmt, charPtr2);

				//printf(itemDat[wi].fmt, intPtr);
#if 0
				{ 1, "��", 10, TYPE_STRING, 0x0L, "%-10s" },
				{ 2,"��",10,TYPE_STRING,(unsigned long)(&adressTbl[0].secound[0] - &adressTbl[0].first[0]),"%-10s" },
#endif
					//*charPtr2 = "AAA";
				//*charPtr2 = 'A'
			}
			else if(itemDat[wi].itype == TYPE_INT) {
				sprintf_s(fmt, sizeof(fmt), "%%-%dd ", itemDat[wi].dispWith);		// �^�C�g���p�̕������肵�ăA�C�e�����Ƃ̃t�H�[�}�b�g���쐬

				intPtr = ((int *)adressDat + itemDat[wi].offset);		 // �^�L���X�g�ƕ��@���C��
				printf(fmt,intPtr);
			}
		}
	}
	printf("\n");
}

