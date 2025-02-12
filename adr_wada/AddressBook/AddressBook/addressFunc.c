#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "addressProto.h"
#include "addressType.h"

bool showHeader = true;

// メニュー表示関数の実装
void DisplayMenu(menuType* menus, unsigned int count) {
    printf(u8"住所録アプリケーション\n");
    printf(u8"データ件数(%d)\n", count);
    printf(u8"コマンドを入力してください\n");
    for (int i = 0; menus[i].name != NULL; i++) {
        printf("%d: %s ", menus[i].id, menus[i].name);
    }
    printf("\n");
}

unsigned int HeaderFunction(itemType const* const itemTbl)
{
    unsigned char fmt[32] = { 0 };
    for (int i = 0; i < 16; i++)
    {
        if (itemTbl[i].pos < 0)
        {
            break;
        }
        else
        {
            sprintf_s(fmt, sizeof(fmt), "%%-%ds ", itemTbl[i].dispWith);
            printf(fmt, itemTbl[i].dispName);
        }
    }
    printf("\n");
    return 0;
}

unsigned int ViewFunction(addressType* addressTbl, itemType const* const itemTbl, unsigned int count)
{
    unsigned char fmt[32] = { 0 };
    unsigned char* charPtr;
    unsigned int* intPtr = 0;

    if (showHeader) {
        HeaderFunction(itemTbl);
    }

    for (unsigned int j = 0; j < count; j++) { // ここで全件ループ
        for (int wi = 0; wi < 16; wi++)
        {
            if (itemTbl[wi].pos < 0)
            {
                break;
            }
            else
            {
                if (itemTbl[wi].itype == TYPE_STRING)
                {
                    sprintf_s(fmt, sizeof(fmt), "%%-%ds ", itemTbl[wi].dispWith); // タイトル用の幅を決定してアイテムごとのフォーマットを作成
                    charPtr = ((unsigned char*)(&addressTbl[j]) + itemTbl[wi].offset); // 型キャストと文法を修正
                    printf(fmt, charPtr);
                }
                else if (itemTbl[wi].itype == TYPE_INT)
                {
                    sprintf_s(fmt, sizeof(fmt), "%%-%dd ", itemTbl[wi].dispWith); // タイトル用の幅を決定してアイテムごとのフォーマットを作成
                    intPtr = (unsigned int*)((unsigned char*)(&addressTbl[j]) + itemTbl[wi].offset); // 型キャストと文法を修正
                    printf(fmt, *intPtr);
                }
            }
        }
        printf("\n");
    }
    return count;
}

unsigned int AddFunction(addressType* addressTbl, itemType const* const itemTbl, unsigned int count)
{ // 住所録にデータを追加する関数
    int roopflag = 1;
    while (roopflag)
    {
        if (count >= 5) {
            printf(u8"これ以上追加できません。\n");
            return count;
        }
        unsigned char fmtsmp[255] = { 0 };
        unsigned char* charPtr;
        unsigned int intValue;
        unsigned int* intPtr = 0;
        for (int i = 0; i < 16; i++)
        {
            if (itemTbl[i].pos < 0)
            {
                break;
            }
            else
            {
                if (itemTbl[i].itype == TYPE_STRING)
                {
                    charPtr = ((unsigned char*)&addressTbl[count] + (unsigned long)itemTbl[i].offset);
                    printf(u8"%sを入力してください：", itemTbl[i].dispName);
                    scanf("%s", fmtsmp);
                    sprintf(charPtr, "%s", fmtsmp);
                }
                else if (itemTbl[i].itype == TYPE_INT)
                {
                    intPtr = (unsigned int*)((unsigned char*)&addressTbl[count] + itemTbl[i].offset);
                    if (strcmp(itemTbl[i].dispName, "ID") == 0) {
                        *intPtr = count + 1;
                    }
                    else {
                        printf(u8"%sを入力してください：", itemTbl[i].dispName);
                        scanf("%d", &intValue);
                        *intPtr = intValue;
                    }
                }
            }
        }
        printf(u8"データが追加されました。\n");
        count++;
        printf(u8"追加作業を続けますか？ 1:続行 0:終了\n");
        scanf("%d", &roopflag);
    }
    return count;
}

unsigned int DeleteFunction(addressType* addressTbl, itemType const* const itemTbl, unsigned int count)
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
        printf(u8"削除したいデータの番号を入力してください：");
        scanf("%d", &target); // 削除したいデータ番号を入力させる

        HeaderFunction(itemTbl);

        for (int wi = 0; wi < 16; wi++)
        {
            if (itemTbl[wi].pos < 0)
            {
                break;
            }
            else
            {
                if (itemTbl[wi].itype == TYPE_STRING)
                {
                    sprintf_s(fmt, sizeof(fmt), "%%-%ds ", itemTbl[wi].dispWith); // タイトル用の幅を決定してアイテムごとのフォーマットを作成
                    charPtr = ((unsigned char*)&addressTbl[target] + itemTbl[wi].offset); // 型キャストと文法を修正
                    printf(fmt, charPtr);
                }
                else if (itemTbl[wi].itype == TYPE_INT)
                {
                    sprintf_s(fmt, sizeof(fmt), "%%-%dd ", itemTbl[wi].dispWith); // タイトル用の幅を決定してアイテムごとのフォーマットを作成
                    intPtr = (unsigned int*)((unsigned char*)&addressTbl[target] + itemTbl[wi].offset); // 型キャストと文法を修正
                    printf(fmt, *intPtr);
                }
            }
        }
        printf(u8"このデータを削除しますか？ 1:はい 0:いいえ\n");
        scanf("%d", &input);
        deside = (input != 0);
        if (deside)
        {
            addressTbl[target] = addressTbl[target + 1];
            count--;
            printf(u8"削除が完了しました。\n");
            printf(u8"削除作業を続けますか？ 1:続行 0:終了\n");
            scanf("%d", &roopflag);
        }
    }
    return count;
}

unsigned int EditFunction(addressType* addressTbl, itemType const* const itemTbl, unsigned int count)
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
        printf(u8"編集したいデータの番号を入力してください：");
        scanf("%d", &target); // 編集したいデータ番号を入力させる

        HeaderFunction(itemTbl);

        for (int wi = 0; wi < 16; wi++)
        {
            if (itemTbl[wi].pos < 0)
            {
                break;
            }
            else
            {
                if (itemTbl[wi].itype == TYPE_STRING)
                {
                    sprintf_s(fmt, sizeof(fmt), "%%-%ds ", itemTbl[wi].dispWith); // タイトル用の幅を決定してアイテムごとのフォーマットを作成
                    charPtr = ((unsigned char*)&addressTbl[target] + itemTbl[wi].offset); // 型キャストと文法を修正
                    printf(fmt, charPtr);
                }
                else if (itemTbl[wi].itype == TYPE_INT)
                {
                    sprintf_s(fmt, sizeof(fmt), "%%-%dd ", itemTbl[wi].dispWith); // タイトル用の幅を決定してアイテムごとのフォーマットを作成
                    intPtr = (unsigned int*)((unsigned char*)&addressTbl[target] + itemTbl[wi].offset); // 型キャストと文法を修正
                    printf(fmt, *intPtr);
                }
            }
        }
        printf(u8"\n編集したい項目を入力してください\n"); // 編集したい項目番号を入力させる
        for (int wj = 0; wj < 16; wj++)
        {
            if (itemTbl[wj].pos < 0)
            {
                break;
            }
            else
            {
                printf("%d:%s ", itemTbl[wj].pos, itemTbl[wj].dispName);
            }
        }
        printf("\n");
        scanf("%d", &title);
        title -= 1; // itemTblの添え字に合うようにする itemTbl[0].pos　= 1 ->title "姓", itemTbl[title].dispName->"名"となりズレてしまうので
        if (itemTbl[target].itype == TYPE_STRING)
        {
            charPtr = ((unsigned char*)&addressTbl[target] + (unsigned long)itemTbl[title].offset);
            printf(u8"%sを入力してください：", itemTbl[title].dispName);
            scanf("%s", fmtsmp);
            sprintf(charPtr, "%s", fmtsmp);
        }
        else if (itemTbl[target].itype == TYPE_INT)
        {
            intPtr = (unsigned int*)((unsigned char*)&addressTbl[target] + itemTbl[title].offset);
            printf(u8"%sを入力してください：", itemTbl[title].dispName);
            scanf("%d", &intValue);
            *intPtr = intValue;
        }

        printf("\n");

        if (title != 0)
        {
            printf(u8"データが更新されました。\n");
            printf(u8"編集を続けますか？ 1:続行 0:終了\n");
            scanf("%d", &roopflag);
        }
    }
    return count;
}

unsigned int SearchFunction(addressType* addressTbl, itemType const* const itemTbl, unsigned int count)
{
    int roopflag = 1;
    while (roopflag)
    {
        int fieldIndex = -1;
        char searchString[256];

        // 検索するフィールドを選択
        printf(u8"検索するフィールドを選択してください:\n");
        for (int i = 0; i < 16; i++) {
            if (itemTbl[i].pos < 0) {
                break;
            }
            printf("%d: %s\n", itemTbl[i].pos, itemTbl[i].dispName);
        }
        scanf("%d", &fieldIndex);
        fieldIndex -= 1; // itemTblのインデックスに合わせる

        if (fieldIndex < 0 || fieldIndex >= 16 || itemTbl[fieldIndex].pos < 0) {
            printf(u8"無効なフィールド選択です。\n");
            return count;
        }

        // 検索文字列を入力
        printf(u8"%sを入力してください：", itemTbl[fieldIndex].dispName);
        scanf("%s", searchString);

        // 検索して一致するデータを表示
        printf(u8"検索結果:\n");
        HeaderFunction(itemTbl);
        showHeader = false; // ヘッダーを表示しないように設定
        for (unsigned int i = 0; i < count; i++) {
            unsigned char* charPtr = ((unsigned char*)&addressTbl[i] + itemTbl[fieldIndex].offset);
            if (itemTbl[fieldIndex].itype == TYPE_STRING) {
                if (strstr((char*)charPtr, searchString) != NULL) {
                    ViewFunction(&addressTbl[i], itemTbl, 1);
                }
            }
            else if (itemTbl[fieldIndex].itype == TYPE_INT) {
                unsigned int* intPtr = (unsigned int*)charPtr;
                if (*intPtr == atoi(searchString)) {
                    ViewFunction(&addressTbl[i], itemTbl, 1);
                }
            }
        }

        printf(u8"検索を続けますか？ 1:続行 0:終了\n");
        scanf("%d", &roopflag);
    }
    showHeader = true; // ヘッダーを表示しないように設定
    return count;
}

unsigned int SortFunction(addressType* addressTbl, itemType const* const itemTbl, unsigned int count) {
    int fieldIndex = -1;

    // ソートするフィールドを選択
    printf(u8"ソートするフィールドを選択してください:\n");
    for (int i = 0; i < 16; i++) {
        if (itemTbl[i].pos < 0) {
            break;
        }
        printf("%d: %s\n", itemTbl[i].pos, itemTbl[i].dispName);
    }
    scanf("%d", &fieldIndex);
    fieldIndex -= 1; // itemTblのインデックスに合わせる

    if (fieldIndex < 0 || fieldIndex >= 16 || itemTbl[fieldIndex].pos < 0) {
        printf(u8"無効なフィールド選択です。\n");
        return count;
    }

    // バブルソートを使用してソートを実行
    for (unsigned int i = 0; i < count - 1; i++) {
        for (unsigned int j = 0; j < count - i - 1; j++) {
            unsigned char* charPtr1 = ((unsigned char*)&addressTbl[j] + itemTbl[fieldIndex].offset);
            unsigned char* charPtr2 = ((unsigned char*)&addressTbl[j + 1] + itemTbl[fieldIndex].offset);
            int swap = 0;

            if (itemTbl[fieldIndex].itype == TYPE_STRING) {
                if (strcmp((char*)charPtr1, (char*)charPtr2) > 0) {
                    swap = 1;
                }
            }
            else if (itemTbl[fieldIndex].itype == TYPE_INT) {
                unsigned int* intPtr1 = (unsigned int*)charPtr1;
                unsigned int* intPtr2 = (unsigned int*)charPtr2;
                if (*intPtr1 > *intPtr2) {
                    swap = 1;
                }
            }

            if (swap) {
                addressType temp = addressTbl[j];
                addressTbl[j] = addressTbl[j + 1];
                addressTbl[j + 1] = temp;
            }
        }
    }

    printf(u8"ソートが完了しました。\n");
    return count;
}

