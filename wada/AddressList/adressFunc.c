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
				sprintf_s(fmt, sizeof(fmt), "%%-%ds ", itemDat[wi].dispWith);        // タイトル用の幅を決定してアイテムごとのフォーマットを作成

				charPtr = ((unsigned char*)adressDat + itemDat[wi].offset);         // 型キャストと文法を修正
				printf(fmt, charPtr);
			}
			else if (itemDat[wi].itype == TYPE_INT) {
				sprintf_s(fmt, sizeof(fmt), "%%-%dd ", itemDat[wi].dispWith);        // タイトル用の幅を決定してアイテムごとのフォーマットを作成

				intPtr = (unsigned int*)((unsigned char*)adressDat + itemDat[wi].offset);         // 型キャストと文法を修正
				printf(fmt, *intPtr);
			}
		}

	}
	printf("\n");
	return 0;
}

unsigned int AddFunction(adressType* adressDat, itemType const* const itemDat, unsigned int count) { //住所録にデータを追加する関数
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
					printf("%sを入力してください：", itemDat[i].dispName);
					scanf("%s", fmtsmp);
					sprintf(charPtr, "%s", fmtsmp);
				}
				else if (itemDat[i].itype == TYPE_INT) {
					intPtr = (unsigned int*)((unsigned char*)&adressDat[count] + itemDat[i].offset);
					printf("%sを入力してください：", itemDat[i].dispName);

					scanf("%d", &intValue);
					*intPtr = intValue;
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

unsigned int DeleteFunction(adressType* adressDat, itemType const* const itemDat, unsigned int count) { //住所録のデータを削除する関数
	int roopflag = 1;
	int target;
	int input;
	unsigned char  fmt[32] = { 0 };
	unsigned char* charPtr;
	unsigned int* intPtr = 0;
	bool deside;
	while (roopflag) {
		printf("削除したいデータの番号を入力してください：");
		scanf("%d", &target); //削除したいデータ番号を入力させる

		for (int wi = 0;wi < 16;wi++) {
			if (itemDat[wi].pos < 0) {
				break;
			}
			else
			{
				if (itemDat[wi].itype == TYPE_STRING) {
					sprintf_s(fmt, sizeof(fmt), "%%-%ds ", itemDat[wi].dispWith);        // タイトル用の幅を決定してアイテムごとのフォーマットを作成

					charPtr = ((unsigned char*)&adressDat[target] + itemDat[wi].offset);         // 型キャストと文法を修正
					printf(fmt, charPtr);
				}
				else if (itemDat[wi].itype == TYPE_INT) {
					sprintf_s(fmt, sizeof(fmt), "%%-%dd ", itemDat[wi].dispWith);        // タイトル用の幅を決定してアイテムごとのフォーマットを作成

					intPtr = (unsigned int*)((unsigned char*)&adressDat[target] + itemDat[wi].offset);         // 型キャストと文法を修正
					printf(fmt, *intPtr);
				}
			}
		}
		printf("このデータを削除しますか？ 1:はい 0:いいえ\n");
		scanf("%d", &input);
		deside = (input != 0);
		if (deside) {
			adressDat[target] = adressDat[target + 1];
			count--;
			printf("削除が完了しました。\n");
			printf("削除作業を続けますか？ 1:続行 0:終了\n");
			scanf("%d", &roopflag);
		}
	}
	return count;
}

unsigned int EditFunction(adressType* adressDat, itemType const* const itemDat, unsigned int count) { //住所録のデータを編集する関数
	int roopflag = 1;
	while (roopflag) {
		int target;
		int title;
		unsigned char  fmt[32] = { 0 };
		unsigned char  fmtsmp[255] = { 0 };
		unsigned char* charPtr;
		unsigned int* intPtr = 0;
		unsigned int intValue;
		printf("編集したいデータの番号を入力してください：");
		scanf("%d", &target); //編集したいデータ番号を入力させる

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
					sprintf_s(fmt, sizeof(fmt), "%%-%ds ", itemDat[wi].dispWith );        // タイトル用の幅を決定してアイテムごとのフォーマットを作成

					charPtr = ((unsigned char*)&adressDat[target] + itemDat[wi].offset);         // 型キャストと文法を修正
					printf(fmt, charPtr);
				}
				else if (itemDat[wi].itype == TYPE_INT) {
					sprintf_s(fmt, sizeof(fmt), "%%-%dd ", itemDat[wi].dispWith);        // タイトル用の幅を決定してアイテムごとのフォーマットを作成

					intPtr = (unsigned int*)((unsigned char*)&adressDat[target] + itemDat[wi].offset);         // 型キャストと文法を修正
					printf(fmt, *intPtr);
				}
			}
		}
		printf("\n編集したい項目を入力してください\n"); //編集したい項目番号を入力させる
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
		title -= 1; // itemDatの添え字に合うようにする itemDat[0].pos　= 1 ->title "姓", itemDat[title].dispName->"名"となりズレてしまうので 
		if (itemDat[target].itype == TYPE_STRING) {
			charPtr = ((unsigned char*)&adressDat[target] + (unsigned long)itemDat[title].offset);
			printf("%sを入力してください：", itemDat[title].dispName);
			scanf("%s", fmtsmp);
			sprintf(charPtr, "%s", fmtsmp);
		}
		else if (itemDat[target].itype == TYPE_INT) {
			intPtr = (unsigned int*)((unsigned char*)&adressDat[target] + itemDat[title].offset);
			printf("%sを入力してください：", itemDat[title].dispName);

			scanf("%d", &intValue);
			*intPtr = intValue;
		}

		printf("\n");



		if (title != 0) {
			printf("データが更新されました。\n");
			printf("編集を続けますか？ 1:続行 0:終了\n");
			scanf("%d", &roopflag);
		}
	}
	return 0;
}

//printf("%-10s%-10s%-6s%-8s%-12s%-15s%-20s%-12s%-12s\n",
//	"姓", "名", "年齢", "性別", "郵便番号", "都道府県", "町名・番地", "電話(自宅)", "電話(会社)");
//printf("%-10s%-10s%-6d%-8s%-12s%-15s%-20s%-12s%-12s\n",
//	adressTbl[targetpage].first,    // 姓
//	adressTbl[targetpage].second,   // 名
//	adressTbl[targetpage].age,      // 年齢
//	adressTbl[targetpage].gender,   // 性別
//	adressTbl[targetpage].postNum,  // 郵便番号
//	adressTbl[targetpage].address1, // 都道府県
//	adressTbl[targetpage].address2, // 町名・番地
//	adressTbl[targetpage].tel1,     // 電話(自宅)
//	adressTbl[targetpage].tel2);    // 電話(会社)

		//printf("1:姓 2:名 3:年齢 4:性別 5:郵便番号 6:都道府県 7:町名・番地 8:電話（自宅） 9:電話（会社）\n");
		//scanf("%d", &targettitle);
		//switch (targettitle) {
		//case 1:
		//	printf("新しい姓を入力してください: ");
		//	scanf("%s", adressTbl[targetpage].first);
		//	break;
		//case 2:
		//	printf("新しい名を入力してください: ");
		//	scanf("%s", adressTbl[targetpage].second);
		//	break;
		//case 3:
		//	printf("新しい年齢を入力してください: ");
		//	scanf("%u", &adressTbl[targetpage].age);
		//	break;
		//case 4:
		//	printf("新しい性別を入力してください: ");
		//	scanf("%s", adressTbl[targetpage].gender);
		//	break;
		//case 5:
		//	printf("新しい郵便番号を入力してください: ");
		//	scanf("%s", adressTbl[targetpage].postNum);
		//	break;
		//case 6:
		//	printf("新しい都道府県を入力してください: ");
		//	scanf(" %s", adressTbl[targetpage].address1);
		//	break;
		//case 7:
		//	printf("新しい町名・番地を入力してください: ");
		//	scanf(" %s", adressTbl[targetpage].address2);
		//	break;
		//case 8:
		//	printf("新しい電話番号（自宅）を入力してください: ");
		//	scanf("%s", adressTbl[targetpage].tel1);
		//	break;
		//case 9:
		//	printf("新しい電話番号（会社）を入力してください: ");
		//	scanf("%s", adressTbl[targetpage].tel2);
		//	break;
		//case 0:
		//	roopflag = 0; // ループ終了
		//	break;
		//default:
		//	printf("無効な選択です。再入力してください。\n");
		//}

//void SearchFunction(adressType * adressTbl, unsigned int count) { //住所録のデータを検索する関数
//	int roopflag = 1;
//	while (roopflag) {
//		int choice;
//		unsigned char target[largeValue];
//		printf("検索項目を選択してください:\n");
//		printf("1. 姓\n");
//		printf("2. 名\n");
//		printf("3. 年齢\n");
//		printf("4. 性別\n");
//		printf("5. 郵便番号\n");
//		printf("6. 住所1\n");
//		printf("7. 住所2\n");
//		printf("8. メールアドレス\n");
//		printf("9. 電話番号（自宅）\n");
//		printf("10. 電話番号（会社）\n");
//		printf("選択: ");
//		scanf("%d", &choice);
//		printf("検索文字列を入力してください: ");
//		scanf("%s", &target);
//		printf("%-10s%-10s%-6s%-8s%-12s%-15s%-20s%-12s%-12s\n",
//			"姓", "名", "年齢", "性別", "郵便番号", "都道府県", "町名・番地", "電話(自宅)", "電話(会社)");
//		for (unsigned int i = 0; i < count; i++) {
//			if (adressTbl[i].age == 0) {
//				// 空データの検出（仮）
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
//				printf("無効な選択肢です。再度選択してください。\n");
//				continue;
//			}
//			if (found) {
//				printf("%-10s%-10s%-6d%-8s%-12s%-15s%-20s%-12s%-12s\n",
//					adressTbl[i].first,    // 姓
//					adressTbl[i].second,   // 名
//					adressTbl[i].age,      // 年齢
//					adressTbl[i].gender,   // 性別
//					adressTbl[i].postNum,  // 郵便番号
//					adressTbl[i].address1, // 都道府県
//					adressTbl[i].address2, // 町名・番地
//					adressTbl[i].tel1,     // 電話(自宅)
//					adressTbl[i].tel2);    // 電話(会社)
//			}
//		}
//		printf("検索を続けますか？ 1:続行 0:終了\n");
//		scanf("%d", &roopflag);
//	}
//}

//void SortFunction(adressType * adressTbl, unsigned int count) {
//	int roopflag = 1;
//	while (roopflag) {
//		// 昇順か降順か指定
//		//int choice;
//		//printf("検索項目を選択してください:\n");
//		//printf("1. 姓\n");
//		//printf("2. 名\n");
//		//printf("3. 年齢\n");
//		//printf("4. 性別\n");
//		//printf("5. 郵便番号\n");
//		//printf("6. 住所1\n");
//		//printf("7. 住所2\n");
//		//printf("8. メールアドレス\n");
//		//printf("9. 電話番号（自宅）\n");
//		//printf("10. 電話番号（会社）\n");
//		//printf("選択: ");
//		//scanf("%d", &choice);
//		for (unsigned int wi = 0; wi < count; wi++) {
//			for (unsigned int wj = wi + 1;wj < count;wj++) {
//				//adressTbl[wi].adress1
//				//.adress1　の値で昇順にソート
//				if (strcmp(adressTbl[wi].address1, adressTbl[wj].address1) > 0) {
//					adressType tmpdata = adressTbl[wi];
//					adressTbl[wi] = adressTbl[wj];
//					adressTbl[wj] = tmpdata;
//				}
//			}
//		}
//		printf("ソートが完了しました。\n");
//		printf("ソートを続けますか？ 1:続行 0:終了\n");
//		scanf("%d", &roopflag);
//	}
//}

		//printf("名字を入力してください:");
		//scanf("%s", adressTbl[count].first);

		//printf("名前を入力してください:");
		//scanf("%s", adressTbl[count].second);

		//printf("年齢を入力してください:");
		//scanf("%d", &adressTbl[count].age);

		//printf("性別を入力してください:");
		//scanf("%s", adressTbl[count].gender);

		//printf("郵便番号を入力してください:");
		//scanf("%s", adressTbl[count].postNum);

		//printf("住所（県）を入力してください:");
		//scanf(" %s", adressTbl[count].address1);

		//printf("住所（町・番地を入力してください:");
		//scanf(" %s", adressTbl[count].address2);

		//printf("メールアドレス入力してください:");
		//scanf("%s", adressTbl[count].email);

		//printf("電話番号（自宅）を入力してください:");
		//scanf("%s", adressTbl[count].tel1);

		//printf("電話番号（会社）を入力してください:");
		//scanf("%s", adressTbl[count].tel2);
