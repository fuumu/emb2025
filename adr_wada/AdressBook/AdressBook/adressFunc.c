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
				sprintf_s(fmt, sizeof(fmt), "%%-%ds ", itemDat[wi].dispWith); // タイトル用の幅を決定してアイテムごとのフォーマットを作成

				charPtr = ((unsigned char*)adressDat + itemDat[wi].offset); // 型キャストと文法を修正
				printf(fmt, charPtr);
			}
			else if (itemDat[wi].itype == TYPE_INT)
			{
				sprintf_s(fmt, sizeof(fmt), "%%-%dd ", itemDat[wi].dispWith); // タイトル用の幅を決定してアイテムごとのフォーマットを作成

				intPtr = (unsigned int*)((unsigned char*)adressDat + itemDat[wi].offset); // 型キャストと文法を修正
				printf(fmt, *intPtr);
			}
		}
	}
	printf("\n");
	return 0;
}

unsigned int AddFunction(adressType* adressDat, itemType const* const itemDat, unsigned int count)
{ // 住所録にデータを追加する関数
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
					printf("%sを入力してください：", itemDat[i].dispName);
					scanf("%s", fmtsmp);
					sprintf(charPtr, "%s", fmtsmp);
				}
				else if (itemDat[i].itype == TYPE_INT)
				{
					intPtr = (unsigned int*)((unsigned char*)&adressDat[count] + itemDat[i].offset);
					if (strcmp(itemDat[i].dispName, "ID") == 0) {
						*intPtr = count + 1;
					} else {
						printf("%sを入力してください：", itemDat[i].dispName);

						scanf("%d", &intValue);
						*intPtr = intValue;
					}
				}
			}
		}
		printf("データが追加されました。\n");
		count++;
		printf("追加作業を続けますか？ 1:続行 0:終了\n");
		scanf("%d", &roopflag);
	}
	return count;
}

unsigned int DeleteFunction(adressType* adressDat, itemType const* const itemDat, unsigned int count)
{ // 住所録のデータを削除する関数
	int roopflag = 1;
	int target;
	int input;
	unsigned char fmt[32] = { 0 };
	unsigned char* charPtr;
	unsigned int* intPtr = 0;
	bool deside;
	while (roopflag)
	{
		printf("削除したいデータの番号を入力してください：");
		scanf("%d", &target); // 削除したいデータ番号を入力させる

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
					sprintf_s(fmt, sizeof(fmt), "%%-%ds ", itemDat[wi].dispWith); // タイトル用の幅を決定してアイテムごとのフォーマットを作成

					charPtr = ((unsigned char*)&adressDat[target] + itemDat[wi].offset); // 型キャストと文法を修正
					printf(fmt, charPtr);
				}
				else if (itemDat[wi].itype == TYPE_INT)
				{
					sprintf_s(fmt, sizeof(fmt), "%%-%dd ", itemDat[wi].dispWith); // タイトル用の幅を決定してアイテムごとのフォーマットを作成

					intPtr = (unsigned int*)((unsigned char*)&adressDat[target] + itemDat[wi].offset); // 型キャストと文法を修正
					printf(fmt, *intPtr);
				}
			}
		}
		printf("このデータを削除しますか？ 1:はい 0:いいえ\n");
		scanf("%d", &input);
		deside = (input != 0);
		if (deside)
		{
			adressDat[target] = adressDat[target + 1];
			count--;
			printf("削除が完了しました。\n");
			printf("削除作業を続けますか？ 1:続行 0:終了\n");
			scanf("%d", &roopflag);
		}
	}
	return count;
}

unsigned int EditFunction(adressType* adressDat, itemType const* const itemDat, unsigned int count)
{ // 住所録のデータを編集する関数
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
		printf("編集したいデータの番号を入力してください：");
		scanf("%d", &target); // 編集したいデータ番号を入力させる

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
					sprintf_s(fmt, sizeof(fmt), "%%-%ds ", itemDat[wi].dispWith); // タイトル用の幅を決定してアイテムごとのフォーマットを作成

					charPtr = ((unsigned char*)&adressDat[target] + itemDat[wi].offset); // 型キャストと文法を修正
					printf(fmt, charPtr);
				}
				else if (itemDat[wi].itype == TYPE_INT)
				{
					sprintf_s(fmt, sizeof(fmt), "%%-%dd ", itemDat[wi].dispWith); // タイトル用の幅を決定してアイテムごとのフォーマットを作成

					intPtr = (unsigned int*)((unsigned char*)&adressDat[target] + itemDat[wi].offset); // 型キャストと文法を修正
					printf(fmt, *intPtr);
				}
			}
		}
		printf("\n編集したい項目を入力してください\n"); // 編集したい項目番号を入力させる
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
		title -= 1; // itemDatの添え字に合うようにする itemDat[0].pos　= 1 ->title "姓", itemDat[title].dispName->"名"となりズレてしまうので
		if (itemDat[target].itype == TYPE_STRING)
		{
			charPtr = ((unsigned char*)&adressDat[target] + (unsigned long)itemDat[title].offset);
			printf("%sを入力してください：", itemDat[title].dispName);
			scanf("%s", fmtsmp);
			sprintf(charPtr, "%s", fmtsmp);
		}
		else if (itemDat[target].itype == TYPE_INT)
		{
			intPtr = (unsigned int*)((unsigned char*)&adressDat[target] + itemDat[title].offset);
			printf("%sを入力してください：", itemDat[title].dispName);

			scanf("%d", &intValue);
			*intPtr = intValue;
		}

		printf("\n");

		if (title != 0)
		{
			printf("データが更新されました。\n");
			printf("編集を続けますか？ 1:続行 0:終了\n");
			scanf("%d", &roopflag);
		}
	}
	return 0;
}