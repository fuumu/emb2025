/*個別機能ソースファイル*/
#include "adressType.h"
#include "adressDef.h"
#include "adressProt.h"
/*データを全件表示*/
void displayAll(adressType* adressTbl, int count, itemType * items) {

    for (int wb = 0; wb < count;wb++) {//count → 
        print_a_record(&adressTbl[wb], items);
    }
}
/*追加(adressTbl[n + 1]に書き込みを追加)*/
void add(adressType* adressTbl, int count, itemType* itemDat) {
    printf("必要な情報を入力してください。\n");
    for (int wi = 0;wi < 16;wi++) {
        if (itemDat[wi].pos < 0) {
            break;
        }
        else {
            if (itemDat[wi].itype == TYPE_STRING) {
                printf("%sを入力してください: ", itemDat[wi].dispName);
                scanf_s("%s", (char*)((unsigned char*)&adressTbl[count] + itemDat[wi].offset),10);
            }
            else if (itemDat[wi].itype == TYPE_INT) {
                printf("%sを入力してください: ", itemDat[wi].dispName);
                scanf_s("%d", (int*)((unsigned char*)&adressTbl[count] + itemDat[wi].offset));
            }
        }
    }
}

/*削除*/
void del(adressType* adressTbl, int count){
    printf("削除対象のNo：");
    char Num[4];
    scanf_s("%s",Num, 4);

    printf("%sを削除します。",Num);
    int no;
    no = atoi(Num);
    for (int i = no; i < MAX_RECORDS; i++) {
        adressTbl[no] = adressTbl[no + 1];
    }

}
/*編集*/
void edit(adressType* adressTbl, int count, itemType* items) {
    int no, item;
    char buf[256];

    printf("編集対象のNo：");//編集する住所録の選択
    scanf("%d", &no);//noにint型で取得
    if (no < 0 || no >= count) {//登録済み住所録の最大数の範囲外の場合
        printf("無効な番号です。\n");
        return;
    }    printf("編集項目を選んでください:\n");
    for (int i = 0; items[i].pos != -1; i++) {
        printf("%d: %s\n", items[i].pos, items[i].dispName);//items配列のメンバpos(番号)と、dispName(日本語表記)でどの項目があるかループで順に表示
    }
    scanf("%d", &item); //編集項目を標準入力で取得
    int found = 0;
    for (int i = 0; items[i].pos != -1; i++) {//itemsの最後に-1を配置し、そこに到達するまでループを回す
        if (items[i].pos == item) {//取得した項目と一致した場合処理に入る。
            // 入力処理
            printf("%sを入力してください: ", items[i].dispName);//それぞれの項目名を表示
            scanf("%s", buf);//標準入力で変更内容を取得

            // 選択されたフィールドに値を設定
            unsigned char* targetField = (unsigned char*)adressTbl + items[i].offset;//targetField(ポインタ)にオフセットを使い対象のフィールドの先頭アドレスを代入
            strncpy((char*)targetField, buf, items[i].dispWith - 1);//strncpy関数で取得した入力を、第二引数のbufから、第一引数のtargetFieldにコピー。第三引数でオーバーフロー防止
            targetField[items[i].dispWith - 1] = '\0';

            found = 1;
            break;
        }
        if (!found) {
            printf("無効な項目です。\n");
        }
    }
}

void search(itemType* items){
    int no, item;
    char buf[256];
    printf("検索項目：");
        for (int i = 0; items[i].pos != -1; i++) {
        printf("%d: %s\n", items[i].pos, items[i].dispName);//items配列のメンバpos(番号)と、dispName(日本語表記)でどの項目があるかループで順に表示

    }
            scanf("%s", &item);
        printf("%sを検索します。",&item);
    for (int i = 0; items[i].pos != -1; i++) {//itemsの最後に-1を配置し、そこに到達するまでループを回す
        if (items[i].pos == item) {

        }
    }

}
//void search(adressType* adressTbl, int count, itemType* itemDat) {
//    printf("検索する %s を入力してください: ", itemDat[2].dispName); // "郵便番号" を表示
//    unsigned char searchKey[32];
//    scanf_s("%s", searchKey, sizeof(searchKey));
//
//    resetFlags(dspTbl, MAX_RECORDS);
//
//    for (int i = 0; i < MAX_RECORDS; i++) {
//        unsigned char* fieldPtr = (unsigned char*)&adressTbl[i] + itemDat[2].offset; // 郵便番号のフィールド
//        if (strcmp((char*)searchKey, (char*)fieldPtr) == 0) {
//            dspTbl[i] = 1;
//            printf("一致するデータが見つかりました:\n");
//
//            for (int wi = 0; wi < 10; wi++) {
//                if (itemDat[wi].pos < 0) {
//                    break;
//                }
//
//                if (itemDat[wi].itype == TYPE_STRING) {
//                    unsigned char* charPtr = (unsigned char*)&adressTbl[i] + itemDat[wi].offset;
//                    printf("%s: %s\n", itemDat[wi].dispName, charPtr);
//                }
//                else if (itemDat[wi].itype == TYPE_INT) {
//                    int* intPtr = (int*)((unsigned char*)&adressTbl[i] + itemDat[wi].offset);
//                    printf("%s: %d\n", itemDat[wi].dispName, *intPtr);
//                }
//            }
//        }
//        else {
//            dspTbl[i] = 0;
//        }
//    }
//}
/*検索条件をクリア*/
void resetFlags(int* dspTbl, int size) {
    for (int i = 0; i < size; i++) {
        dspTbl[i] = 0;
    }
}
/*ソート表示*/
void sort(adressType* adrTblPtr) {
    adressType stashaddress;
    for (int i = 0; i < MAX_RECORDS;i++) {
        for (int j = i + 1; j < MAX_RECORDS; j++) {
            if (strcmp(adrTblPtr[i].adress1, adrTblPtr[j].adress1) > 0) {
                stashaddress = adrTblPtr[i];
                adrTblPtr[j] = adrTblPtr[i];
                adrTblPtr[j] = stashaddress;
            }
        }
    }
}
int saveAdressData(adressType* adressTbl, int count)
{
    FILE* file;
    errno_t err;

    // ファイルをバイナリ書き込みモードで開く
    err = fopen_s(&file, "adressDat.bin", "wb");
    if (err != 0 || file == NULL)
    {
        perror("Error opening file");
        return -1;
    }

    // データを書き込む
    if (fwrite(adressTbl, sizeof(adressType), count, file) != count)
    {
        perror("Error writing file");
        fclose(file);
        return -1;
    }

    fclose(file);
    return 0;
}

int loadAdressData(adressType* adressTbl)
{
    FILE* file;
    errno_t err;
    int count = 0;

    // ファイルをバイナリ読み取りモードで開く
    err = fopen_s(&file, "adressDat.bin", "rb");
    if (err != 0 || file == NULL)
    {
        perror("Error opening file");
        return -1;
    }

    // データを読み込む
    while (fread(&adressTbl[count], sizeof(adressType), 1, file) == 1)
    {
        count++;
    }

    fclose(file);
    return count;
}
