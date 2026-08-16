#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> ((((a)) % 3 == 0) ||
        (((b)) % 3 == 0) ||
        (((a) + (b)) % 3 == 0));
    ensures \result == 1 ==> !((((a)) % 3 == 0) ||
        (((b)) % 3 == 0) ||
        (((a) + (b)) % 3 == 0));
*/
int32_t func(uint32_t a, uint32_t b)
{
    int32_t state;
    state = 0;

    if (a % 3 == 0)
    {
        state = 1;
    }
    if (b % 3 == 0)
    {
        state = 1;
    }
    if ((a + b) % 3 == 0)
    {
        state = 1;
    }

    if (state == 0)
    {
        //@ assert !((((a)) % 3 == 0) ||         (((b)) % 3 == 0) ||         (((a) + (b)) % 3 == 0));
        return 1;
    }
    else
    {
        //@ assert ((((a)) % 3 == 0) ||         (((b)) % 3 == 0) ||         (((a) + (b)) % 3 == 0));
        return 0;
    }
}
