#include "Vector.h"

TVector::TVector() {
    this->Data = NULL;
    this->Size = 0;
}

int TVector::Length() {
    return this->Size;
}

void TVector::Add(const TKV& kv) {
    if (this->Size == 0) {
        this->Size++;
        this->Data = (TKV*) malloc(sizeof(TKV) * this->Size);
        this->Data[0].Value = kv.Value;

        for (int i = 0; i < sizeof(this->Data[0].Key); ++i) {
            this->Data[0].Key[i] = kv.Key[i];    
        }
        return;    
    }
   this->Data = (TKV*) realloc(this->Data,sizeof(TKV) * (this->Size+1));

    this->Data[this->Size].Value = kv.Value;
    for (int i = 0; i < sizeof(this->Data[this->Size].Key); ++i) {
        this->Data[this->Size].Key[i] = kv.Key[i];    
    }
    this->Size++;
}


TKV TVector::Get(int index) {
   

    return this->Data[index];
}

void TVector::Set(const TKV& elem, int index) {
    if (index >= this->Size) {
        return;
    }

  for (int i = 0; i < sizeof(this->Data[index].Key); ++i) {
        this->Data[index].Key[i] = elem.Key[i];    
    }
    this->Data[index].Value = elem.Value;
}

void TVector::setSize(int size) {
    this->Data = (TKV*) malloc(sizeof(TKV)*size);
    this->Size = size;
}
void TVector::Free()
{
    free(this->Data);
}