#include <iostream>
#include <stdint.h>
#include <bitset> 
using namespace std;

void apply_offset(uint16_t* data, size_t len, uint16_t offset);
void show(const uint16_t* data, size_t len);
const uint16_t* find_max(const uint16_t* data, size_t len);
const int N = 5;

int main()
{
    uint16_t Array[N];
    uint16_t offset = 0b0000000000000010;
    for (int i = 0; i < N; i++) {
        Array[i] = 2 * i;
    }
    cout << "Initial data\n";
    show(Array, N);
    cout << "Max:" << *find_max(Array, N)<<endl;
    cout << "Offset\n";
    apply_offset(Array, N, offset);
    show(Array, N);
    cout << "Max:" << *find_max(Array, N) << endl;
    cout << "Changed\n";
    Array[4] = 0b0010000000000001;
    show(Array, N);
    cout <<"Max:"<< *find_max(Array, N) <<" Adress: "<< find_max(Array, N) << endl;
    cout << "Max:" << *find_max(Array, N)+7 << endl;
}

void apply_offset(uint16_t* data, size_t len, uint16_t offset) {
    if (data == nullptr) return;
    for (uint16_t* ptr=data; ptr<data+len; ++ptr)
        *ptr+= offset;
}
void show(const uint16_t*  data, size_t len) {
    if (data == nullptr) return;
    for (const uint16_t* ptr = data; ptr < data + len; ++ptr)
        cout <<"Binary: "<< bitset<16>(*ptr) <<"  "<<"Dec: "<<*ptr <<endl;
}

const uint16_t* find_max(const uint16_t* data, size_t len) {
    if (data == nullptr || len==0) return nullptr;
    const uint16_t* res= data;
    for (const uint16_t* ptr = data; ptr < data + len; ++ptr)
        if(*ptr > *res) res=ptr;
    return res;
}
