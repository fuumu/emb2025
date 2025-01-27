#ifndef ADRESSMAIN
#define ADRESSMAIN

#include "adressProt.h"
#include "adressType.h"
#include "adressDef.h"


char Item1[50];  // ソート関係
char Item2[50];  // 検索条件
char cmd[10];


/*アドレス帳アプリmain関数 */
// メインメニュー関数
void menu1(adressType *adressTblptr, int *dspTbl , itemType *items) {
    printf("住所録アプリケーション\n"); //--TITLE--
    printf("データ件数: (%d)\n", datacount);
    printf("ソート関係: (%s)\n", Item1);
    printf("検索条件: (%s)\n", Item2);

    displayAll(adressTblptr, datacount, items); // データ一覧を表示する関数

    // メニュー表示とコマンド入力待機
    while (1) {
        printf("コマンドを入力してください（0:全件リスト表示,1: 新規作成,2:削除,3:編集,4:検索,5:検索リセット,6:ソート,7:ファイルにセーブ, 8: ファイルロード, 9: 終了）: ");
        scanf_s("%c", cmd,(unsigned)8); 
        int comm = 0;
        comm = atoi(cmd);
        if (comm == 9) { // '9'で終了
            printf("終了します。\n");
            break;
        }

        switchFn(adressTblptr, comm, dspTbl, datacount, items);
    }
}

int switchFn(adressType * adressTblptr,int comm, int* dspTbl,int datacount, itemType *items) {

    switch (comm) {
    case 0:
        displayAll(adressTblptr, datacount,items);//全件表示
        break;
    case 1:
        add(adressTblptr, datacount, items);
        break;
    case 2:
        del(adressTblptr, datacount);
        break;
    case 3:
        edit(adressTblptr, datacount, items);
        break;
    case 4:
        /*search(adressTblptr, datacount, items);*/
        break;
    case 5:
        resetFlags(dspTbl, MAX_RECORDS);
        break;
    case 6:
        sort(adressTblptr);
        break;
    case 7:
        saveAdressData(adressTblptr, datacount);
        break;
    case 8:
        loadAdressData(adressTblptr);
        break;
    default:
        break;

    }
    return 1;
}

int main() {
    adressType adressTbl[MAX_RECORDS] = {
        {"first",
         "secound",
         "postNum",
         "adress1",
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
    int dspTbl[MAX_RECORDS];
    itemType items[] = {
    { 1, "姓", 10, TYPE_STRING, 0x0L },
    { 2, "名", 10, TYPE_STRING, (unsigned long)(adressTbl[0].secound - adressTbl[0].first) },
    { 3, "郵便番号", 10, TYPE_STRING, (unsigned long)(adressTbl[0].postNum - adressTbl[0].first) },
    { 4, "住所1", 15, TYPE_STRING, (unsigned long)(adressTbl[0].adress1 - adressTbl[0].first) },
    { 5, "住所2", 15, TYPE_STRING, (unsigned long)(adressTbl[0].adress2 - adressTbl[0].first) },
    { 6, "mail", 10, TYPE_STRING, (unsigned long)(adressTbl[0].email - adressTbl[0].first) },
    { 7, "TEL1", 10, TYPE_STRING, (unsigned long)(adressTbl[0].tel1 - adressTbl[0].first) },
    { 8, "TEL2", 10, TYPE_STRING, (unsigned long)(adressTbl[0].tel2 - adressTbl[0].first) },
    { 9, "AGE", 10, TYPE_INT, (&adressTbl[0].age - &adressTbl[0].first) },
    { 10, "GENDER", 10, TYPE_STRING, (unsigned long)(adressTbl[0].gender - adressTbl[0].first) },
    {-1,},
    };

    menu1(adressTbl, dspTbl, items);

    return 0;
}

#endif ADRESSMAIN