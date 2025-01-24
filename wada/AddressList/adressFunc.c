#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#include "adressProto.h"
#include "adressType.h"

unsigned int ViewFunction(adressType* adressDat, itemType const* const itemDat) {

	unsigned char  fmt[32] = { 0 };
	unsigned char* charPtr;
	unsigned int* intPtr = 0;

	for (int wi = 0;wi < 16;wi++) {
		if (itemDat[wi].pos < 0) {
			break;
		}
		else
		{
			if (itemDat[wi].itype == TYPE_STRING) {
				sprintf_s(fmt, sizeof(fmt), "%%-%ds ", itemDat[wi].dispWith);        // �^�C�g���p�̕������肵�ăA�C�e�����Ƃ̃t�H�[�}�b�g���쐬

				charPtr = ((unsigned char*)adressDat + itemDat[wi].offset);         // �^�L���X�g�ƕ��@���C��
				printf(fmt, charPtr);
			}
			else if (itemDat[wi].itype == TYPE_INT) {
				sprintf_s(fmt, sizeof(fmt), "%%-%dd ", itemDat[wi].dispWith);        // �^�C�g���p�̕������肵�ăA�C�e�����Ƃ̃t�H�[�}�b�g���쐬

				intPtr = (unsigned int*)((unsigned char*)adressDat + itemDat[wi].offset);         // �^�L���X�g�ƕ��@���C��
				printf(fmt, *intPtr);
			}
		}

	}
	printf("\n");
	return 0;
}

unsigned int AddFunction(adressType* adressDat, itemType const* const itemDat, unsigned int count) { //�Z���^�Ƀf�[�^��ǉ�����֐�
	int roopflag = 1;
	while (roopflag) {
		unsigned char  fmtsmp[255] = { 0 };
		unsigned char* charPtr;
		unsigned int intValue;
		unsigned int* intPtr = 0;
		for (int i = 0; i < 16; i++) {
			if (itemDat[i].pos < 0) {
				break;
			}
			else {
				if (itemDat[i].itype == TYPE_STRING) {
					charPtr = ((unsigned char*)&adressDat[count] + (unsigned long)itemDat[i].offset);
					printf("%s����͂��Ă��������F", itemDat[i].dispName);
					scanf("%s", fmtsmp);
					sprintf(charPtr, "%s", fmtsmp);
				}
				else if (itemDat[i].itype == TYPE_INT) {
					intPtr = (unsigned int*)((unsigned char*)&adressDat[count] + itemDat[i].offset);
					printf("%s����͂��Ă��������F", itemDat[i].dispName);

					scanf("%d", &intValue);
					*intPtr = intValue;
				}
			}
		}
		printf("�f�[�^���ǉ�����܂����B\n");
		count++;
		printf("�ǉ���Ƃ𑱂��܂����H 1:���s 0:�I��\n");
		scanf("%d", &roopflag);
	}
	return count;
}

unsigned int DeleteFunction(adressType* adressDat, itemType const* const itemDat, unsigned int count) { //�Z���^�̃f�[�^���폜����֐�
	int roopflag = 1;
	int target;
	int input;
	unsigned char  fmt[32] = { 0 };
	unsigned char* charPtr;
	unsigned int* intPtr = 0;
	bool deside;
	while (roopflag) {
		printf("�폜�������f�[�^�̔ԍ�����͂��Ă��������F");
		scanf("%d", &target); //�폜�������f�[�^�ԍ�����͂�����

		for (int wi = 0;wi < 16;wi++) {
			if (itemDat[wi].pos < 0) {
				break;
			}
			else
			{
				if (itemDat[wi].itype == TYPE_STRING) {
					sprintf_s(fmt, sizeof(fmt), "%%-%ds ", itemDat[wi].dispWith);        // �^�C�g���p�̕������肵�ăA�C�e�����Ƃ̃t�H�[�}�b�g���쐬

					charPtr = ((unsigned char*)&adressDat[target] + itemDat[wi].offset);         // �^�L���X�g�ƕ��@���C��
					printf(fmt, charPtr);
				}
				else if (itemDat[wi].itype == TYPE_INT) {
					sprintf_s(fmt, sizeof(fmt), "%%-%dd ", itemDat[wi].dispWith);        // �^�C�g���p�̕������肵�ăA�C�e�����Ƃ̃t�H�[�}�b�g���쐬

					intPtr = (unsigned int*)((unsigned char*)&adressDat[target] + itemDat[wi].offset);         // �^�L���X�g�ƕ��@���C��
					printf(fmt, *intPtr);
				}
			}
		}
		printf("���̃f�[�^���폜���܂����H 1:�͂� 0:������\n");
		scanf("%d", &input);
		deside = (input != 0);
		if (deside) {
			adressDat[target] = adressDat[target + 1];
			count--;
			printf("�폜���������܂����B\n");
			printf("�폜��Ƃ𑱂��܂����H 1:���s 0:�I��\n");
			scanf("%d", &roopflag);
		}
	}
	return count;
}

unsigned int EditFunction(adressType* adressDat, itemType const* const itemDat, unsigned int count) { //�Z���^�̃f�[�^��ҏW����֐�
	int roopflag = 1;
	while (roopflag) {
		int target;
		int title;
		unsigned char  fmt[32] = { 0 };
		unsigned char  fmtsmp[255] = { 0 };
		unsigned char* charPtr;
		unsigned int* intPtr = 0;
		unsigned int intValue;
		printf("�ҏW�������f�[�^�̔ԍ�����͂��Ă��������F");
		scanf("%d", &target); //�ҏW�������f�[�^�ԍ�����͂�����

		for (int i = 0; i < 16; i++) {
			if (itemDat[i].pos < 0) {
				break;
			}
			sprintf_s(fmt, sizeof(fmt), "%%-%ds ", itemDat[i].dispWith);
			printf(fmt, itemDat[i].dispName);
		}

		for (int wi = 0;wi < 16;wi++) {
			if (itemDat[wi].pos < 0) {
				break;
			}
			else
			{
				if (itemDat[wi].itype == TYPE_STRING) {
					sprintf_s(fmt, sizeof(fmt), "%%-%ds ", itemDat[wi].dispWith );        // �^�C�g���p�̕������肵�ăA�C�e�����Ƃ̃t�H�[�}�b�g���쐬

					charPtr = ((unsigned char*)&adressDat[target] + itemDat[wi].offset);         // �^�L���X�g�ƕ��@���C��
					printf(fmt, charPtr);
				}
				else if (itemDat[wi].itype == TYPE_INT) {
					sprintf_s(fmt, sizeof(fmt), "%%-%dd ", itemDat[wi].dispWith);        // �^�C�g���p�̕������肵�ăA�C�e�����Ƃ̃t�H�[�}�b�g���쐬

					intPtr = (unsigned int*)((unsigned char*)&adressDat[target] + itemDat[wi].offset);         // �^�L���X�g�ƕ��@���C��
					printf(fmt, *intPtr);
				}
			}
		}
		printf("\n�ҏW���������ڂ���͂��Ă�������\n"); //�ҏW���������ڔԍ�����͂�����
		for (int wj = 0; wj < 16; wj++) {
			if (itemDat[wj].pos < 0) {
				break;
			}
			else {
				printf("%d:%s ", itemDat[wj].pos, itemDat[wj].dispName);
			}
		}
		printf("\n");
		scanf("%d", &title);
		title -= 1; // itemDat�̓Y�����ɍ����悤�ɂ��� itemDat[0].pos�@= 1 ->title "��", itemDat[title].dispName->"��"�ƂȂ�Y���Ă��܂��̂� 
		if (itemDat[target].itype == TYPE_STRING) {
			charPtr = ((unsigned char*)&adressDat[target] + (unsigned long)itemDat[title].offset);
			printf("%s����͂��Ă��������F", itemDat[title].dispName);
			scanf("%s", fmtsmp);
			sprintf(charPtr, "%s", fmtsmp);
		}
		else if (itemDat[target].itype == TYPE_INT) {
			intPtr = (unsigned int*)((unsigned char*)&adressDat[target] + itemDat[title].offset);
			printf("%s����͂��Ă��������F", itemDat[title].dispName);

			scanf("%d", &intValue);
			*intPtr = intValue;
		}

		printf("\n");



		if (title != 0) {
			printf("�f�[�^���X�V����܂����B\n");
			printf("�ҏW�𑱂��܂����H 1:���s 0:�I��\n");
			scanf("%d", &roopflag);
		}
	}
	return 0;
}

//printf("%-10s%-10s%-6s%-8s%-12s%-15s%-20s%-12s%-12s\n",
//	"��", "��", "�N��", "����", "�X�֔ԍ�", "�s���{��", "�����E�Ԓn", "�d�b(����)", "�d�b(���)");
//printf("%-10s%-10s%-6d%-8s%-12s%-15s%-20s%-12s%-12s\n",
//	adressTbl[targetpage].first,    // ��
//	adressTbl[targetpage].second,   // ��
//	adressTbl[targetpage].age,      // �N��
//	adressTbl[targetpage].gender,   // ����
//	adressTbl[targetpage].postNum,  // �X�֔ԍ�
//	adressTbl[targetpage].address1, // �s���{��
//	adressTbl[targetpage].address2, // �����E�Ԓn
//	adressTbl[targetpage].tel1,     // �d�b(����)
//	adressTbl[targetpage].tel2);    // �d�b(���)

		//printf("1:�� 2:�� 3:�N�� 4:���� 5:�X�֔ԍ� 6:�s���{�� 7:�����E�Ԓn 8:�d�b�i����j 9:�d�b�i��Ёj\n");
		//scanf("%d", &targettitle);
		//switch (targettitle) {
		//case 1:
		//	printf("�V����������͂��Ă�������: ");
		//	scanf("%s", adressTbl[targetpage].first);
		//	break;
		//case 2:
		//	printf("�V����������͂��Ă�������: ");
		//	scanf("%s", adressTbl[targetpage].second);
		//	break;
		//case 3:
		//	printf("�V�����N�����͂��Ă�������: ");
		//	scanf("%u", &adressTbl[targetpage].age);
		//	break;
		//case 4:
		//	printf("�V�������ʂ���͂��Ă�������: ");
		//	scanf("%s", adressTbl[targetpage].gender);
		//	break;
		//case 5:
		//	printf("�V�����X�֔ԍ�����͂��Ă�������: ");
		//	scanf("%s", adressTbl[targetpage].postNum);
		//	break;
		//case 6:
		//	printf("�V�����s���{������͂��Ă�������: ");
		//	scanf(" %s", adressTbl[targetpage].address1);
		//	break;
		//case 7:
		//	printf("�V���������E�Ԓn����͂��Ă�������: ");
		//	scanf(" %s", adressTbl[targetpage].address2);
		//	break;
		//case 8:
		//	printf("�V�����d�b�ԍ��i����j����͂��Ă�������: ");
		//	scanf("%s", adressTbl[targetpage].tel1);
		//	break;
		//case 9:
		//	printf("�V�����d�b�ԍ��i��Ёj����͂��Ă�������: ");
		//	scanf("%s", adressTbl[targetpage].tel2);
		//	break;
		//case 0:
		//	roopflag = 0; // ���[�v�I��
		//	break;
		//default:
		//	printf("�����ȑI���ł��B�ē��͂��Ă��������B\n");
		//}

//void SearchFunction(adressType * adressTbl, unsigned int count) { //�Z���^�̃f�[�^����������֐�
//	int roopflag = 1;
//	while (roopflag) {
//		int choice;
//		unsigned char target[largeValue];
//		printf("�������ڂ�I�����Ă�������:\n");
//		printf("1. ��\n");
//		printf("2. ��\n");
//		printf("3. �N��\n");
//		printf("4. ����\n");
//		printf("5. �X�֔ԍ�\n");
//		printf("6. �Z��1\n");
//		printf("7. �Z��2\n");
//		printf("8. ���[���A�h���X\n");
//		printf("9. �d�b�ԍ��i����j\n");
//		printf("10. �d�b�ԍ��i��Ёj\n");
//		printf("�I��: ");
//		scanf("%d", &choice);
//		printf("�������������͂��Ă�������: ");
//		scanf("%s", &target);
//		printf("%-10s%-10s%-6s%-8s%-12s%-15s%-20s%-12s%-12s\n",
//			"��", "��", "�N��", "����", "�X�֔ԍ�", "�s���{��", "�����E�Ԓn", "�d�b(����)", "�d�b(���)");
//		for (unsigned int i = 0; i < count; i++) {
//			if (adressTbl[i].age == 0) {
//				// ��f�[�^�̌��o�i���j
//				break;
//			}
//			int found = 0;
//			switch (choice)
//			{
//			case 1:
//				found = (strcmp((char*)adressTbl[i].first, target) == 0);
//				break;
//			case 2:
//				found = (strcmp((char*)adressTbl[i].second, target) == 0);
//				break;
//			case 3:
//				found = (adressTbl[i].age == atoi((char*)target));
//				break;
//			case 4:
//				found = (strcmp((char*)adressTbl[i].gender, target) == 0);
//				break;
//			case 5:
//				found = (strcmp((char*)adressTbl[i].postNum, target) == 0);
//				break;
//			case 6:
//				found = (strcmp((char*)adressTbl[i].address1, target) == 0);
//				break;
//			case 7:
//				found = (strcmp((char*)adressTbl[i].address2, target) == 0);
//				break;
//			case 8:
//				found = (strcmp((char*)adressTbl[i].email, target) == 0);
//				break;
//			case 9:
//				found = (strcmp((char*)adressTbl[i].tel1, target) == 0);
//				break;
//			case 10:
//				found = (strcmp((char*)adressTbl[i].tel2, target) == 0);
//				break;
//			default:
//				printf("�����ȑI�����ł��B�ēx�I�����Ă��������B\n");
//				continue;
//			}
//			if (found) {
//				printf("%-10s%-10s%-6d%-8s%-12s%-15s%-20s%-12s%-12s\n",
//					adressTbl[i].first,    // ��
//					adressTbl[i].second,   // ��
//					adressTbl[i].age,      // �N��
//					adressTbl[i].gender,   // ����
//					adressTbl[i].postNum,  // �X�֔ԍ�
//					adressTbl[i].address1, // �s���{��
//					adressTbl[i].address2, // �����E�Ԓn
//					adressTbl[i].tel1,     // �d�b(����)
//					adressTbl[i].tel2);    // �d�b(���)
//			}
//		}
//		printf("�����𑱂��܂����H 1:���s 0:�I��\n");
//		scanf("%d", &roopflag);
//	}
//}

//void SortFunction(adressType * adressTbl, unsigned int count) {
//	int roopflag = 1;
//	while (roopflag) {
//		// �������~�����w��
//		//int choice;
//		//printf("�������ڂ�I�����Ă�������:\n");
//		//printf("1. ��\n");
//		//printf("2. ��\n");
//		//printf("3. �N��\n");
//		//printf("4. ����\n");
//		//printf("5. �X�֔ԍ�\n");
//		//printf("6. �Z��1\n");
//		//printf("7. �Z��2\n");
//		//printf("8. ���[���A�h���X\n");
//		//printf("9. �d�b�ԍ��i����j\n");
//		//printf("10. �d�b�ԍ��i��Ёj\n");
//		//printf("�I��: ");
//		//scanf("%d", &choice);
//		for (unsigned int wi = 0; wi < count; wi++) {
//			for (unsigned int wj = wi + 1;wj < count;wj++) {
//				//adressTbl[wi].adress1
//				//.adress1�@�̒l�ŏ����Ƀ\�[�g
//				if (strcmp(adressTbl[wi].address1, adressTbl[wj].address1) > 0) {
//					adressType tmpdata = adressTbl[wi];
//					adressTbl[wi] = adressTbl[wj];
//					adressTbl[wj] = tmpdata;
//				}
//			}
//		}
//		printf("�\�[�g���������܂����B\n");
//		printf("�\�[�g�𑱂��܂����H 1:���s 0:�I��\n");
//		scanf("%d", &roopflag);
//	}
//}

		//printf("��������͂��Ă�������:");
		//scanf("%s", adressTbl[count].first);

		//printf("���O����͂��Ă�������:");
		//scanf("%s", adressTbl[count].second);

		//printf("�N�����͂��Ă�������:");
		//scanf("%d", &adressTbl[count].age);

		//printf("���ʂ���͂��Ă�������:");
		//scanf("%s", adressTbl[count].gender);

		//printf("�X�֔ԍ�����͂��Ă�������:");
		//scanf("%s", adressTbl[count].postNum);

		//printf("�Z���i���j����͂��Ă�������:");
		//scanf(" %s", adressTbl[count].address1);

		//printf("�Z���i���E�Ԓn����͂��Ă�������:");
		//scanf(" %s", adressTbl[count].address2);

		//printf("���[���A�h���X���͂��Ă�������:");
		//scanf("%s", adressTbl[count].email);

		//printf("�d�b�ԍ��i����j����͂��Ă�������:");
		//scanf("%s", adressTbl[count].tel1);

		//printf("�d�b�ԍ��i��Ёj����͂��Ă�������:");
		//scanf("%s", adressTbl[count].tel2);
