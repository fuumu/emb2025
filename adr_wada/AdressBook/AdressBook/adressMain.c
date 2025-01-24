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
		{1, "姓", 10, TYPE_STRING, offsetof(adressType, first)},
		{2, "名", 10, TYPE_STRING, offsetof(adressType, second)},
		{3, "郵便番号", 10, TYPE_STRING, offsetof(adressType, postNum)},
		{4, "住所1", 15, TYPE_STRING, offsetof(adressType, address1)},
		{5, "住所2", 15, TYPE_STRING, offsetof(adressType, address2)},
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
	// 	{1,"データを表示",10,offsetof(itemType, pos)},
	// 	{2,"追加",10,offsetof(itemType, pos)},
	// 	{3,"削除",10,offsetof(itemType, pos)},
	// 	{4,"編集",10,offsetof(itemType, pos)},
	// 	{5,"検索",10,offsetof(itemType, pos)},
	// 	{6,"ソート",10,offsetof(itemType, pos)},
	// 	{7,"ファイル保存",10,offsetof(itemType, pos)},
	// 	{8,"ファイル読み込み",10,offsetof(itemType, pos)},
	// 	{9,"終了",10,offsetof(itemType, pos)},
	// };

	unsigned char fmt[32];
	int count = 3;
	int roopflag = 1;
	while (roopflag)
	{
		unsigned int cmd;
		if (count == 0)
		{
			printf("住所録アプリケーション\n");
			printf("データ件数(%d)", count);
			printf("コマンドを入力してください\n");
			printf("1：追加 2:ファイル読込　9：終了\n");

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
			printf("住所録アプリケーション\n");
			printf("データ件数(%d)", count);
			printf("コマンドを入力してください\n");
			printf("0:データを表示 1：追加 2:削除 3:編集 4:検索 5:ソート 6:ファイル保存 7: ファイル読み込み　9：終了\n");

			scanf("%d", &cmd);

			switch (cmd)
			{
			case 0: // データを全件表示
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
			case 1: // データを追加
				count = AddFunction(adressTbl, items, count);
				break;
			case 2: // データを削除
				count = DeleteFunction(adressTbl, items, count);
				break;
			case 3: // データを編集
				EditFunction(adressTbl, items, count);
				break;
				// case 4: //データを検索
				//	SearchFunction(adressTbl, count);
				//	break;
				// case 5: //データをソート
				//	SortFunction(adressTbl, count);
				//	break;
				// case 6: //データをセーブ
				//	count = SaveFunction(adressTbl, count);
				//	break;
				// case 7: //データをロード
				//	count = LoadFunction(adressTbl);
				//	break;
			case 9: // システムを終了
				roopflag = 0;
				break;
			default:
				break;
			}
		}
	}
}