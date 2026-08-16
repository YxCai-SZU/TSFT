#include <stdint.h>

/*@
    requires a < 0x100000000;
    ensures \result == a;
    assigns \nothing;
*/
uint32_t truncate_u64(uint64_t a)
{
    //@ assert a < 0x100000000;
    return (uint32_t)a;
}

/*@
    requires a == b;
    ensures \result == 1;
    assigns \nothing;
*/
int compare_bitwise_and_3(uint64_t a, uint64_t b)
{
    //@ assert (a & 3) == (b & 3);
    return ((a & 3) == (b & 3)) ? 1 : 0;
}

/*@
    requires a == b;
    ensures \result == 1;
    assigns \nothing;
*/
int compare_bitwise_and_mask(uint64_t a, uint64_t b)
{
    //@ assert (a & 0xFFFFFFFF) == (b & 0xFFFFFFFF);
    return ((a & 0xFFFFFFFF) == (b & 0xFFFFFFFF)) ? 1 : 0;
}

int main()
{
    uint64_t a;
    uint64_t b;
    uint32_t result;
    
    a = 0x123456789ABCDEF0;
    b = 0x123456789ABCDEF0;
    
    //@ assert a == b;
    compare_bitwise_and_3(a, b);
    compare_bitwise_and_mask(a, b);
    
    a = 0x00000000FFFFFFFF;
    //@ assert a < 0x100000000;
    result = truncate_u64(a);
    
    return 0;
}
