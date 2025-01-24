#include <stdio.h>
#include <stddef.h>

#include "adressType.h"
#include "adressProto.h"

int main(void)
{
#define DMYADRESSDAT
#ifndef DMYADRESSDAT
	adressType adressTbl[];
#else
	adressType adressTbl[5] = {
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
		{"3first",
		 "3secound",
		 "3postNum",
		 "3adress",
		 "3adress2",
		 "3email",
		 "3tel1",
		 "32tel2",
		 25,
		 "3male"},
	};
#endif
	itemType const items[] = {
		{1, "��", 10, TYPE_STRING, offsetof(adressType, first)},
		{2, "��", 10, TYPE_STRING, offsetof(adressType, second)},
		{3, "�X�֔ԍ�", 10, TYPE_STRING, offsetof(adressType, postNum)},
		{4, "�Z��1", 15, TYPE_STRING, offsetof(adressType, address1)},
		{5, "�Z��2", 15, TYPE_STRING, offsetof(adressType, address2)},
		{6, "mail", 10, TYPE_STRING, offsetof(adressType, email)},
		{7, "TEL1", 10, TYPE_STRING, offsetof(adressType, tel1)},
		{8, "TEL2", 10, TYPE_STRING, offsetof(adressType, tel2)},
		{9, "AGE", 10, TYPE_INT, offsetof(adressType, age)},
		{10, "GENDER", 10, TYPE_STRING, offsetof(adressType, gender)},
		{
			-1,
		},
	};

	// menuType menus[] = {
	// 	{1,"�f�[�^��\��",10,offsetof(itemType, pos)},
	// 	{2,"�ǉ�",10,offsetof(itemType, pos)},
	// 	{3,"�폜",10,offsetof(itemType, pos)},
	// 	{4,"�ҏW",10,offsetof(itemType, pos)},
	// 	{5,"����",10,offsetof(itemType, pos)},
	// 	{6,"�\�[�g",10,offsetof(itemType, pos)},
	// 	{7,"�t�@�C���ۑ�",10,offsetof(itemType, pos)},
	// 	{8,"�t�@�C���ǂݍ���",10,offsetof(itemType, pos)},
	// 	{9,"�I��",10,offsetof(itemType, pos)},
	// };

	unsigned char fmt[32];
	int count = 3;
	int roopflag = 1;
	while (roopflag)
	{
		unsigned int cmd;
		if (count == 0)
		{
			printf("�Z���^�A�v���P�[�V����\n");
			printf("�f�[�^����(%d)", count);
			printf("�R�}���h����͂��Ă�������\n");
			printf("1�F�ǉ� 2:�t�@�C���Ǎ��@9�F�I��\n");

			scanf("%d", &cmd);

			switch (cmd)
			{
			case 1:
				count = AddFunction(adressTbl, items, count);
				break;
				// case 2:
				//	count = LoadFunction(adressTbl);
				//	break;
			case 9:
				roopflag = 0;
				break;
			default:
				break;
			}
		}
		else
		{
			printf("�Z���^�A�v���P�[�V����\n");
			printf("�f�[�^����(%d)", count);
			printf("�R�}���h����͂��Ă�������\n");
			printf("0:�f�[�^��\�� 1�F�ǉ� 2:�폜 3:�ҏW 4:���� 5:�\�[�g 6:�t�@�C���ۑ� 7: �t�@�C���ǂݍ��݁@9�F�I��\n");

			scanf("%d", &cmd);

			switch (cmd)
			{
			case 0: // �f�[�^��S���\��
				for (int i = 0; i < 16; i++)
				{
					if (items[i].pos < 0)
					{
						break;
					}
					sprintf_s(fmt, sizeof(fmt), "%%-%ds ", items[i].dispWith);
					printf(fmt, items[i].dispName);
				}
				printf("\n");
				for (int j = 0; j < count; j++)
				{
					ViewFunction(&adressTbl[j], items);
				}
				break;
			case 1: // �f�[�^��ǉ�
				count = AddFunction(adressTbl, items, count);
				break;
			case 2: // �f�[�^���폜
				count = DeleteFunction(adressTbl, items, count);
				break;
			case 3: // �f�[�^��ҏW
				EditFunction(adressTbl, items, count);
				break;
				// case 4: //�f�[�^������
				//	SearchFunction(adressTbl, count);
				//	break;
				// case 5: //�f�[�^���\�[�g
				//	SortFunction(adressTbl, count);
				//	break;
				// case 6: //�f�[�^���Z�[�u
				//	count = SaveFunction(adressTbl, count);
				//	break;
				// case 7: //�f�[�^�����[�h
				//	count = LoadFunction(adressTbl);
				//	break;
			case 9: // �V�X�e�����I��
				roopflag = 0;
				break;
			default:
				break;
			}
		}
	}
}