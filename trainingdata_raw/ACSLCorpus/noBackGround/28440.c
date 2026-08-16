#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 12) && (1 <= (b) && (b) <= 31);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> ((a) <= 12 && (b) >= 13);
    ensures \result == 0 ==> ((a) >= 13 || (b) <= 12);
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    int32_t result;

    if (a <= 12 && b >= 13)
    {
        //@ assert ((a) <= 12 && (b) >= 13);
        result = 1;
    }
    else
    {
        //@ assert ((a) >= 13 || (b) <= 12);
        result = 0;
    }

    return result;
}
