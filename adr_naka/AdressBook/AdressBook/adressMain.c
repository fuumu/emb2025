#ifndef ADRESSMAIN
#define ADRESSMAIN

#include "adressProt.h"
#include "adressType.h"
#include "adressDef.h"


char Item1[50];  // �\�[�g�֌W
char Item2[50];  // ��������
char cmd[10];


/*�A�h���X���A�v��main�֐� */
// ���C�����j���[�֐�
void menu1(adressType *adressTblptr, int *dspTbl , itemType *items) {
    printf("�Z���^�A�v���P�[�V����\n"); //--TITLE--
    printf("�f�[�^����: (%d)\n", datacount);
    printf("�\�[�g�֌W: (%s)\n", Item1);
    printf("��������: (%s)\n", Item2);

    displayAll(adressTblptr, datacount, items); // �f�[�^�ꗗ��\������֐�

    // ���j���[�\���ƃR�}���h���͑ҋ@
    while (1) {
        printf("�R�}���h����͂��Ă��������i0:�S�����X�g�\��,1: �V�K�쐬,2:�폜,3:�ҏW,4:����,5:�������Z�b�g,6:�\�[�g,7:�t�@�C���ɃZ�[�u, 8: �t�@�C�����[�h, 9: �I���j: ");
        scanf_s("%c", cmd,(unsigned)8); 
        int comm = 0;
        comm = atoi(cmd);
        if (comm == 9) { // '9'�ŏI��
            printf("�I�����܂��B\n");
            break;
        }

        switchFn(adressTblptr, comm, dspTbl, datacount, items);
    }
}

int switchFn(adressType * adressTblptr,int comm, int* dspTbl,int datacount, itemType *items) {

    switch (comm) {
    case 0:
        displayAll(adressTblptr, datacount,items);//�S���\��
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
    { 1, "��", 10, TYPE_STRING, 0x0L },
    { 2, "��", 10, TYPE_STRING, (unsigned long)(adressTbl[0].secound - adressTbl[0].first) },
    { 3, "�X�֔ԍ�", 10, TYPE_STRING, (unsigned long)(adressTbl[0].postNum - adressTbl[0].first) },
    { 4, "�Z��1", 15, TYPE_STRING, (unsigned long)(adressTbl[0].adress1 - adressTbl[0].first) },
    { 5, "�Z��2", 15, TYPE_STRING, (unsigned long)(adressTbl[0].adress2 - adressTbl[0].first) },
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