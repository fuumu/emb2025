#ifndef ADRESS_PROTTO
#define ADRESS_PROTTO
#include "adressType.h"

unsigned int ViewFunction(adressType* adressDat, itemType const* const itemDat);                       // �Z���^���̑S�Ẵf�[�^��\������֐�
unsigned int AddFunction(adressType* adressDat, itemType const* const itemDat, unsigned int count);    // �Z���^�Ƀf�[�^��ǉ�����֐�
unsigned int DeleteFunction(adressType* adressDat, itemType const* const itemDat, unsigned int count); // �Z���^�̃f�[�^���폜����֐�
unsigned int EditFunction(adressType* adressDat, itemType const* const itemDat, unsigned int count);   // �Z���^�̃f�[�^��ҏW����֐�
// void SearchFunction(adressType* adressTbl, unsigned int count); //�Z���^�̃f�[�^����������֐�
// void SortFunction(adressType* adressTbl, unsigned int count); //�Z���^�̃f�[�^���\�[�g����֐�
// int SaveFunction(adressType* adressTbl, unsigned int count); //�t�@�C���Ƀf�[�^��ۑ�����֐�
// int LoadFunction(adressType* adressTbl); //�t�@�C������f�[�^��ǂݍ��݊֐�

#endif // !ADRESS_PROTTO