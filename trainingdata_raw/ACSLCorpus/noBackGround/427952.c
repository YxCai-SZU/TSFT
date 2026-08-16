#include <stdint.h>

/*@
    requires \true;
    assigns \nothing;
    ensures \result == (a ^ b);
    ensures ((\result) == ((a) ^ (b)));
 */
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t result;
    //@ assert (a ^ b) == (a ^ b);
    result = a ^ b;
    //@ assert result == (a ^ b);
    return result;
}

int main(void)
{
    return 0;
}
