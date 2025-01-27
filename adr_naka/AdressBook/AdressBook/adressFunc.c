/*�ʋ@�\�\�[�X�t�@�C��*/
#include "adressType.h"
#include "adressDef.h"
#include "adressProt.h"
/*�f�[�^��S���\��*/
void displayAll(adressType* adressTbl, int count, itemType * items) {

    for (int wb = 0; wb < count;wb++) {//count �� 
        print_a_record(&adressTbl[wb], items);
    }
}
/*�ǉ�(adressTbl[n + 1]�ɏ������݂�ǉ�)*/
void add(adressType* adressTbl, int count, itemType* itemDat) {
    printf("�K�v�ȏ�����͂��Ă��������B\n");
    for (int wi = 0;wi < 16;wi++) {
        if (itemDat[wi].pos < 0) {
            break;
        }
        else {
            if (itemDat[wi].itype == TYPE_STRING) {
                printf("%s����͂��Ă�������: ", itemDat[wi].dispName);
                scanf_s("%s", (char*)((unsigned char*)&adressTbl[count] + itemDat[wi].offset),10);
            }
            else if (itemDat[wi].itype == TYPE_INT) {
                printf("%s����͂��Ă�������: ", itemDat[wi].dispName);
                scanf_s("%d", (int*)((unsigned char*)&adressTbl[count] + itemDat[wi].offset));
            }
        }
    }
}

/*�폜*/
void del(adressType* adressTbl, int count){
    printf("�폜�Ώۂ�No�F");
    char Num[4];
    scanf_s("%s",Num, 4);

    printf("%s���폜���܂��B",Num);
    int no;
    no = atoi(Num);
    for (int i = no; i < MAX_RECORDS; i++) {
        adressTbl[no] = adressTbl[no + 1];
    }

}
/*�ҏW*/
void edit(adressType* adressTbl, int count, itemType* items) {
    int no, item;
    char buf[256];

    printf("�ҏW�Ώۂ�No�F");//�ҏW����Z���^�̑I��
    scanf("%d", &no);//no��int�^�Ŏ擾
    if (no < 0 || no >= count) {//�o�^�ςݏZ���^�̍ő吔�͈̔͊O�̏ꍇ
        printf("�����Ȕԍ��ł��B\n");
        return;
    }    printf("�ҏW���ڂ�I��ł�������:\n");
    for (int i = 0; items[i].pos != -1; i++) {
        printf("%d: %s\n", items[i].pos, items[i].dispName);//items�z��̃����opos(�ԍ�)�ƁAdispName(���{��\�L)�łǂ̍��ڂ����邩���[�v�ŏ��ɕ\��
    }
    scanf("%d", &item); //�ҏW���ڂ�W�����͂Ŏ擾
    int found = 0;
    for (int i = 0; items[i].pos != -1; i++) {//items�̍Ō��-1��z�u���A�����ɓ��B����܂Ń��[�v����
        if (items[i].pos == item) {//�擾�������ڂƈ�v�����ꍇ�����ɓ���B
            // ���͏���
            printf("%s����͂��Ă�������: ", items[i].dispName);//���ꂼ��̍��ږ���\��
            scanf("%s", buf);//�W�����͂ŕύX���e���擾

            // �I�����ꂽ�t�B�[���h�ɒl��ݒ�
            unsigned char* targetField = (unsigned char*)adressTbl + items[i].offset;//targetField(�|�C���^)�ɃI�t�Z�b�g���g���Ώۂ̃t�B�[���h�̐擪�A�h���X����
            strncpy((char*)targetField, buf, items[i].dispWith - 1);//strncpy�֐��Ŏ擾�������͂��A��������buf����A��������targetField�ɃR�s�[�B��O�����ŃI�[�o�[�t���[�h�~
            targetField[items[i].dispWith - 1] = '\0';

            found = 1;
            break;
        }
        if (!found) {
            printf("�����ȍ��ڂł��B\n");
        }
    }
}

void search(itemType* items){
    int no, item;
    char buf[256];
    printf("�������ځF");
        for (int i = 0; items[i].pos != -1; i++) {
        printf("%d: %s\n", items[i].pos, items[i].dispName);//items�z��̃����opos(�ԍ�)�ƁAdispName(���{��\�L)�łǂ̍��ڂ����邩���[�v�ŏ��ɕ\��

    }
            scanf("%s", &item);
        printf("%s���������܂��B",&item);
    for (int i = 0; items[i].pos != -1; i++) {//items�̍Ō��-1��z�u���A�����ɓ��B����܂Ń��[�v����
        if (items[i].pos == item) {

        }
    }

}
//void search(adressType* adressTbl, int count, itemType* itemDat) {
//    printf("�������� %s ����͂��Ă�������: ", itemDat[2].dispName); // "�X�֔ԍ�" ��\��
//    unsigned char searchKey[32];
//    scanf_s("%s", searchKey, sizeof(searchKey));
//
//    resetFlags(dspTbl, MAX_RECORDS);
//
//    for (int i = 0; i < MAX_RECORDS; i++) {
//        unsigned char* fieldPtr = (unsigned char*)&adressTbl[i] + itemDat[2].offset; // �X�֔ԍ��̃t�B�[���h
//        if (strcmp((char*)searchKey, (char*)fieldPtr) == 0) {
//            dspTbl[i] = 1;
//            printf("��v����f�[�^��������܂���:\n");
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
/*�����������N���A*/
void resetFlags(int* dspTbl, int size) {
    for (int i = 0; i < size; i++) {
        dspTbl[i] = 0;
    }
}
/*�\�[�g�\��*/
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

    // �t�@�C�����o�C�i���������݃��[�h�ŊJ��
    err = fopen_s(&file, "adressDat.bin", "wb");
    if (err != 0 || file == NULL)
    {
        perror("Error opening file");
        return -1;
    }

    // �f�[�^����������
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

    // �t�@�C�����o�C�i���ǂݎ�胂�[�h�ŊJ��
    err = fopen_s(&file, "adressDat.bin", "rb");
    if (err != 0 || file == NULL)
    {
        perror("Error opening file");
        return -1;
    }

    // �f�[�^��ǂݍ���
    while (fread(&adressTbl[count], sizeof(adressType), 1, file) == 1)
    {
        count++;
    }

    fclose(file);
    return count;
}
