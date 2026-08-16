#include <stdint.h>

/*@
    requires y < 32;
    ensures \result == (1ULL << y);
    assigns \nothing;
*/
uint32_t left_shift_u32(uint32_t y) {
    uint32_t result;
    
    //@ assert y < 32;
    result = 1U << y;
    
    //@ assert result == (1ULL << y);
    return result;
}

/*@
    requires \true;
    ensures \true;
    assigns \nothing;
*/
void verify_de_morgan() {
    uint32_t a;
    uint32_t b;
    
    a = 0xAAAAAAAA;
    b = 0x55555555;
    
    //@ assert (~(a & b)) == (~a | ~b);
}

/*@
    requires \true;
    ensures \true;
    assigns \nothing;
*/
void verify_de_morgan_or() {
    uint32_t a;
    uint32_t b;
    
    a = 0xAAAAAAAA;
    b = 0x55555555;
    
    //@ assert (~(a | b)) == (~a & ~b);
}

/*@
    assigns \nothing;
*/
int main() {
    uint32_t y = 5;
    uint32_t result;
    
    //@ assert y < 32;
    result = left_shift_u32(y);
    
    //@ assert result == (1ULL << y);
    verify_de_morgan();
    verify_de_morgan_or();
    
    return 0;
}
