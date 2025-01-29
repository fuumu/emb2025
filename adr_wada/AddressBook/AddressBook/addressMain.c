#include <stdio.h>
#include <stddef.h>

#include "addressType.h"
#include "addressProto.h"

int main(void)
{
#define DMYADDRESSDAT
#ifndef DMYADDRESSDAT
    addressType addressTbl[];
#else
    addressType addressTbl[5] = {
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
         "32tel2",
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
        {2, "姓", 10, TYPE_STRING, offsetof(addressType, first)},
        {3, "名", 10, TYPE_STRING, offsetof(addressType, second)},
        {4, "郵便番号", 10, TYPE_STRING, offsetof(addressType, postNum)},
        {5, "住所1", 15, TYPE_STRING, offsetof(addressType, address1)},
        {6, "住所2", 15, TYPE_STRING, offsetof(addressType, address2)},
        {7, "mail", 10, TYPE_STRING, offsetof(addressType, email)},
        {8, "TEL1", 10, TYPE_STRING, offsetof(addressType, tel1)},
        {9, "TEL2", 10, TYPE_STRING, offsetof(addressType, tel2)},
        {10, "AGE", 5, TYPE_INT, offsetof(addressType, age)},
        {11, "GENDER", 10, TYPE_STRING, offsetof(addressType, gender)},
        {
            -1,
        },
    };

    // menuType menus[] = {
    //  {1,"データを表示",10,offsetof(itemType, pos)},
    //  {2,"追加",10,offsetof(itemType, pos)},
    //  {3,"削除",10,offsetof(itemType, pos)},
    //  {4,"編集",10,offsetof(itemType, pos)},
    //  {5,"検索",10,offsetof(itemType, pos)},
    //  {6,"ソート",10,offsetof(itemType, pos)},
    //  {7,"ファイル保存",10,offsetof(itemType, pos)},
    //  {8,"ファイル読み込み",10,offsetof(itemType, pos)},
    //  {9,"終了",10,offsetof(itemType, pos)},
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
                count = AddFunction(addressTbl, items, count);
                break;
                // case 2:
                //  count = LoadFunction(addressTbl);
                //  break;
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
                    ViewFunction(&addressTbl[j], items);
                }
                break;
            case 1: // データを追加
                count = AddFunction(addressTbl, items, count);
                break;
            case 2: // データを削除
                count = DeleteFunction(addressTbl, items, count);
                break;
            case 3: // データを編集
                EditFunction(addressTbl, items, count);
                break;
                // case 4: //データを検索
                //  SearchFunction(addressTbl, count);
                //  break;
                // case 5: //データをソート
                //  SortFunction(addressTbl, count);
                //  break;
                // case 6: //データをセーブ
                //  count = SaveFunction(addressTbl, count);
                //  break;
                // case 7: //データをロード
                //  count = LoadFunction(addressTbl);
                //  break;
            case 9: // システムを終了
                roopflag = 0;
                break;
            default:
                break;
            }
        }
    }

    // ここに他の処理を追加

    return 0;
}