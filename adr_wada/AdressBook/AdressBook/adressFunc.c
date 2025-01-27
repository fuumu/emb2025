#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "adressProto.h"
#include "adressType.h"

unsigned int ViewFunction(adressType* adressDat, itemType const* const itemDat)
{

	unsigned char fmt[32] = { 0 };
	unsigned char* charPtr;
	unsigned int* intPtr = 0;

	for (int wi = 0; wi < 16; wi++)
	{
		if (itemDat[wi].pos < 0)
		{
			break;
		}
		else
		{
			if (itemDat[wi].itype == TYPE_STRING)
			{
				sprintf_s(fmt, sizeof(fmt), "%%-%ds ", itemDat[wi].dispWith); // �^�C�g���p�̕������肵�ăA�C�e�����Ƃ̃t�H�[�}�b�g���쐬

				charPtr = ((unsigned char*)adressDat + itemDat[wi].offset); // �^�L���X�g�ƕ��@���C��
				printf(fmt, charPtr);
			}
			else if (itemDat[wi].itype == TYPE_INT)
			{
				sprintf_s(fmt, sizeof(fmt), "%%-%dd ", itemDat[wi].dispWith); // �^�C�g���p�̕������肵�ăA�C�e�����Ƃ̃t�H�[�}�b�g���쐬

				intPtr = (unsigned int*)((unsigned char*)adressDat + itemDat[wi].offset); // �^�L���X�g�ƕ��@���C��
				printf(fmt, *intPtr);
			}
		}
	}
	printf("\n");
	return 0;
}

unsigned int AddFunction(adressType* adressDat, itemType const* const itemDat, unsigned int count)
{ // �Z���^�Ƀf�[�^��ǉ�����֐�
	int roopflag = 1;
	while (roopflag)
	{
		unsigned char fmtsmp[255] = { 0 };
		unsigned char* charPtr;
		unsigned int intValue;
		unsigned int* intPtr = 0;
		for (int i = 0; i < 16; i++)
		{
			if (itemDat[i].pos < 0)
			{
				break;
			}
			else
			{
				if (itemDat[i].itype == TYPE_STRING)
				{
					charPtr = ((unsigned char*)&adressDat[count] + (unsigned long)itemDat[i].offset);
					printf("%s����͂��Ă��������F", itemDat[i].dispName);
					scanf("%s", fmtsmp);
					sprintf(charPtr, "%s", fmtsmp);
				}
				else if (itemDat[i].itype == TYPE_INT)
				{
					intPtr = (unsigned int*)((unsigned char*)&adressDat[count] + itemDat[i].offset);
					if (strcmp(itemDat[i].dispName, "ID") == 0) {
						*intPtr = count + 1;
					} else {
						printf("%s����͂��Ă��������F", itemDat[i].dispName);

						scanf("%d", &intValue);
						*intPtr = intValue;
					}
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

unsigned int DeleteFunction(adressType* adressDat, itemType const* const itemDat, unsigned int count)
{ // �Z���^�̃f�[�^���폜����֐�
	int roopflag = 1;
	int target;
	int input;
	unsigned char fmt[32] = { 0 };
	unsigned char* charPtr;
	unsigned int* intPtr = 0;
	bool deside;
	while (roopflag)
	{
		printf("�폜�������f�[�^�̔ԍ�����͂��Ă��������F");
		scanf("%d", &target); // �폜�������f�[�^�ԍ�����͂�����

		for (int wi = 0; wi < 16; wi++)
		{
			if (itemDat[wi].pos < 0)
			{
				break;
			}
			else
			{
				if (itemDat[wi].itype == TYPE_STRING)
				{
					sprintf_s(fmt, sizeof(fmt), "%%-%ds ", itemDat[wi].dispWith); // �^�C�g���p�̕������肵�ăA�C�e�����Ƃ̃t�H�[�}�b�g���쐬

					charPtr = ((unsigned char*)&adressDat[target] + itemDat[wi].offset); // �^�L���X�g�ƕ��@���C��
					printf(fmt, charPtr);
				}
				else if (itemDat[wi].itype == TYPE_INT)
				{
					sprintf_s(fmt, sizeof(fmt), "%%-%dd ", itemDat[wi].dispWith); // �^�C�g���p�̕������肵�ăA�C�e�����Ƃ̃t�H�[�}�b�g���쐬

					intPtr = (unsigned int*)((unsigned char*)&adressDat[target] + itemDat[wi].offset); // �^�L���X�g�ƕ��@���C��
					printf(fmt, *intPtr);
				}
			}
		}
		printf("���̃f�[�^���폜���܂����H 1:�͂� 0:������\n");
		scanf("%d", &input);
		deside = (input != 0);
		if (deside)
		{
			adressDat[target] = adressDat[target + 1];
			count--;
			printf("�폜���������܂����B\n");
			printf("�폜��Ƃ𑱂��܂����H 1:���s 0:�I��\n");
			scanf("%d", &roopflag);
		}
	}
	return count;
}

unsigned int EditFunction(adressType* adressDat, itemType const* const itemDat, unsigned int count)
{ // �Z���^�̃f�[�^��ҏW����֐�
	int roopflag = 1;
	while (roopflag)
	{
		int target;
		int title;
		unsigned char fmt[32] = { 0 };
		unsigned char fmtsmp[255] = { 0 };
		unsigned char* charPtr;
		unsigned int* intPtr = 0;
		unsigned int intValue;
		printf("�ҏW�������f�[�^�̔ԍ�����͂��Ă��������F");
		scanf("%d", &target); // �ҏW�������f�[�^�ԍ�����͂�����

		for (int i = 0; i < 16; i++)
		{
			if (itemDat[i].pos < 0)
			{
				break;
			}
			sprintf_s(fmt, sizeof(fmt), "%%-%ds ", itemDat[i].dispWith);
			printf(fmt, itemDat[i].dispName);
		}

		for (int wi = 0; wi < 16; wi++)
		{
			if (itemDat[wi].pos < 0)
			{
				break;
			}
			else
			{
				if (itemDat[wi].itype == TYPE_STRING)
				{
					sprintf_s(fmt, sizeof(fmt), "%%-%ds ", itemDat[wi].dispWith); // �^�C�g���p�̕������肵�ăA�C�e�����Ƃ̃t�H�[�}�b�g���쐬

					charPtr = ((unsigned char*)&adressDat[target] + itemDat[wi].offset); // �^�L���X�g�ƕ��@���C��
					printf(fmt, charPtr);
				}
				else if (itemDat[wi].itype == TYPE_INT)
				{
					sprintf_s(fmt, sizeof(fmt), "%%-%dd ", itemDat[wi].dispWith); // �^�C�g���p�̕������肵�ăA�C�e�����Ƃ̃t�H�[�}�b�g���쐬

					intPtr = (unsigned int*)((unsigned char*)&adressDat[target] + itemDat[wi].offset); // �^�L���X�g�ƕ��@���C��
					printf(fmt, *intPtr);
				}
			}
		}
		printf("\n�ҏW���������ڂ���͂��Ă�������\n"); // �ҏW���������ڔԍ�����͂�����
		for (int wj = 0; wj < 16; wj++)
		{
			if (itemDat[wj].pos < 0)
			{
				break;
			}
			else
			{
				printf("%d:%s ", itemDat[wj].pos, itemDat[wj].dispName);
			}
		}
		printf("\n");
		scanf("%d", &title);
		title -= 1; // itemDat�̓Y�����ɍ����悤�ɂ��� itemDat[0].pos�@= 1 ->title "��", itemDat[title].dispName->"��"�ƂȂ�Y���Ă��܂��̂�
		if (itemDat[target].itype == TYPE_STRING)
		{
			charPtr = ((unsigned char*)&adressDat[target] + (unsigned long)itemDat[title].offset);
			printf("%s����͂��Ă��������F", itemDat[title].dispName);
			scanf("%s", fmtsmp);
			sprintf(charPtr, "%s", fmtsmp);
		}
		else if (itemDat[target].itype == TYPE_INT)
		{
			intPtr = (unsigned int*)((unsigned char*)&adressDat[target] + itemDat[title].offset);
			printf("%s����͂��Ă��������F", itemDat[title].dispName);

			scanf("%d", &intValue);
			*intPtr = intValue;
		}

		printf("\n");

		if (title != 0)
		{
			printf("�f�[�^���X�V����܂����B\n");
			printf("�ҏW�𑱂��܂����H 1:���s 0:�I��\n");
			scanf("%d", &roopflag);
		}
	}
	return 0;
}