#include <stdio.h>
#include <stddef.h>
#include <Windows.h>

#include "addressType.h"
#include "addressProto.h"

int main(void)
{
	SetConsoleOutputCP(CP_UTF8);
#define DMYaddressTbl
#ifndef DMYaddressTbl
	addressType addressTbl[];
#else
	addressType addressTbl[10] = {
		{1,
		 "first",
		 "second",
		 "postNum",
		 "address",
		 "address2",
		 "email",
		 "tel1",
		 "tel2",
		 25,
		 "male"},
		{2,
		 "2first",
		 "2second",
		 "2postNum",
		 "2address",
		 "2address2",
		 "2email",
		 "2tel1",
		 "2tel2",
		 25,
		 "2male"},
		{3,
		 "3first",
		 "3second",
		 "3postNum",
		 "3address",
		 "3address2",
		 "3email",
		 "3tel1",
		 "3tel2",
		 25,
		 "3male"},
		{4,
		 "4first",
		 "4second",
		 "4postNum",
		 "4address",
		 "4address2",
		 "4email",
		 "4tel1",
		 "4tel2",
		 25,
		 "4male"},
		{5,
		 "5first",
		 "5second",
		 "5postNum",
		 "5address",
		 "5address2",
		 "5email",
		 "5tel1",
		 "5tel2",
		 25,
		 "5male"}
	};
#endif
	itemType const items[] = {
		{1, "ID", 5, TYPE_INT, offsetof(addressType, id)},
		{2, u8"姓", 10, TYPE_STRING, offsetof(addressType, first)},
		{3, u8"名", 10, TYPE_STRING, offsetof(addressType, second)},
		{4, u8"郵便番号", 10, TYPE_STRING, offsetof(addressType, postNum)},
		{5, u8"住所1", 15, TYPE_STRING, offsetof(addressType, address1)},
		{6, u8"住所2", 15, TYPE_STRING, offsetof(addressType, address2)},
		{7, "mail", 10, TYPE_STRING, offsetof(addressType, email)},
		{8, "TEL1", 10, TYPE_STRING, offsetof(addressType, tel1)},
		{9, "TEL2", 10, TYPE_STRING, offsetof(addressType, tel2)},
		{10, "AGE", 5, TYPE_INT, offsetof(addressType, age)},
		{11, "GENDER", 10, TYPE_STRING, offsetof(addressType, gender)},
		{
			-1,
		},
	};

	menuType menus[] = {
		{0,0 , u8"データを表示", ViewFunction},
		{1,1 , u8"追加", AddFunction},
		{2,0 , u8"削除", DeleteFunction},
		{3,0 , u8"編集", EditFunction},
		{4,0 , u8"検索", SearchFunction},
		{5,0 , u8"ソート", SortFunction},
		{6,0 , u8"ファイル保存", SaveFunction},
		{7,1 , u8"ファイル読み込み", LoadFunction},
		{9,1 , u8"終了", NULL},
		{ -1,0 , NULL, NULL } // 終端を示す
	};

	int count = 5;
	int roopflag = 1;
	while (roopflag)
	{
		unsigned int cmd;
		if (count == 0)
		{
			printf(u8"住所録アプリケーション\n");
			printf(u8"データ件数(%d)", count);
			printf(u8"コマンドを入力してください\n");
			printf(u8"1：追加 2:ファイル読込　9：終了\n");

			scanf("%d", &cmd);

			switch (cmd)
			{
			case 1:
				count = AddFunction(addressTbl, items, count);
				break;
			case 2:
				count = LoadFunction(addressTbl, items, count);
				break;
			case 9:
				roopflag = 0;
				break;
			default:
				break;
			}
		}
		else
		{
			DisplayMenu(menus, count);

			scanf("%d", &cmd);

			if (cmd == 9) {
				roopflag = 0;
			}
			else {
				for (int i = 0; i < sizeof(menus) / sizeof(menuType); i++) {
					if (menus[i].id == cmd) {
						if (menus[i].func != NULL) {
							count = menus[i].func(addressTbl, items, count);
						}
						break;
					}
				}
			}
		}
	}

	return 0;
}
