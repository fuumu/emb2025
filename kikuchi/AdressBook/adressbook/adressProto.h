#pragma once


#ifndef ADRESS_PROTO
#define ADRESS_PROTO




int saveDataDelete(adressType * adrTblPtr, int dataPos);

int searchAdressData(adressType* adrTblPtr,int * disp);



int sortAdressData(adressType* adrTblPtr);
void print1record(adressType* adressDat, itemType const * itemDat);


#endif
