#include <iostream>
const int KEY_SIZE = 32;
const int ALPHABET_SIZE = 16;
const int FIRST_LETTER = 'a'-10;
const int FIRST_NUMBER = '0';
struct TKV
{
    char Key[33];
    unsigned long long Value;
};
class TVector {
    private:
    TKV* Data;
    int Size;
    int Length;

public:
    TVector() {
        this->Data = NULL;
        this->Size = 0;
        this->Length = 0;

    }

    int GetLength() {
        return this->Length;
    }

    void Add(const TKV& kv) {
        if (this->Size == this->Length) {
            if (this->Size==0) {
                this->Size+=10;
                this->Data = (TKV*) malloc(sizeof(TKV) * this->Size);
            } else {
                this->Size*=2;
                this->Data = (TKV*) realloc(this->Data,sizeof(TKV) * this->Size);
            }   
        }
        this->Data[this->Length].Value = kv.Value;
        for (int i = 0; i < sizeof(this->Data[this->Length].Key); ++i) {
            this->Data[this->Length].Key[i] = kv.Key[i];    
        }
        this->Length++;
    }
    TKV Get(int index) {
        return this->Data[index];
    }
    void Set(const TKV& elem, int index) {
        if (index >= this->Length) {
            return;
        }
        for (int i = 0; i < sizeof(this->Data[index].Key); ++i) {
            this->Data[index].Key[i] = elem.Key[i];    
        }
        this->Data[index].Value = elem.Value;
    }
    void setSize(int size) {
        this->Data = (TKV*) malloc(sizeof(TKV)*size);
        this->Size = size;
        this->Length = this->Size;
    }
    void Free() {
        free(this->Data);
    }
};
TVector elems;
TVector output;

void CountingSort(  int discharge){
    long long tmp[ALPHABET_SIZE];
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        tmp[i] = 0;
    }
    for( int i = 0; i < elems.GetLength(); ++i ) {
        if (isalpha(elems.Get(i).Key[discharge])) {
            tmp[elems.Get(i).Key[discharge]-FIRST_LETTER]++;
        } else {
            tmp[elems.Get(i).Key[discharge]-FIRST_NUMBER]++;
        }
    }
    for( int i = 1; i < sizeof(tmp)/sizeof(*tmp); ++i ) {
        tmp[i] += tmp[i-1];
    }
    for( int i = elems.GetLength()-1; i >= 0; --i ) {
        if (isalpha(elems.Get(i).Key[discharge])) {
            output.Set(elems.Get(i),tmp[elems.Get(i).Key[discharge]-FIRST_LETTER] - 1);
            tmp[elems.Get(i).Key[discharge]-FIRST_LETTER]--;
        } else {
            output.Set(elems.Get(i),tmp[elems.Get(i).Key[discharge]-FIRST_NUMBER] - 1);
            tmp[elems.Get(i).Key[discharge]-FIRST_NUMBER]--;
        }
    }
}

int main() {
    TKV kvElem;
    while (scanf("%32s \t %llu",kvElem.Key,&kvElem.Value)!=EOF) {
        elems.Add(kvElem);
    }
    output.setSize(elems.GetLength());
    for (int i = KEY_SIZE-1; i >=0; --i ) {
        CountingSort(i);
        for (int i = 0; i<elems.GetLength(); ++i) {
             elems.Set(output.Get(i),i);
        }
    }
    for( int i  = 0; i < elems.GetLength(); ++i  ) {
        printf("%32s \t %llu\n",elems.Get(i).Key,elems.Get(i).Value);
    }
    elems.Free();
    output.Free();
    return 0;
}