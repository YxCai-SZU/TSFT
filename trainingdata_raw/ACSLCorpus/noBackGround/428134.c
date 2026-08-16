#include <stdint.h>

/*@
    requires \true;
    ensures ((\result) == ((((x) >> 31) & 1) ^ ((x) & 1)));
    assigns \nothing;
 */
int32_t func(int32_t x)
{
    int32_t result;
    //@ assert \true;
    result = ((x >> 31) & 1) ^ (x & 1);
    //@ assert ((result) == ((((x) >> 31) & 1) ^ ((x) & 1)));
    return result;
}
