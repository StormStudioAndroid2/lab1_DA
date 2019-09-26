#include "KV.cpp"
#include <stddef.h>
#include <stdlib.h> 
class TVector {
    private:
    TKV* Data;
    int Size;

public:
    TVector();
    int Length();
    void Add(const TKV& kv);
    TKV Get(int index);
    void Set(const TKV& elem,int index);
    void setSize(int size);
    void Free();
};