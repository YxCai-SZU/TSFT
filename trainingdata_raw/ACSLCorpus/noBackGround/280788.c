#include <stdint.h>

/*@
    requires 1 <= a <= 1000000000;
    ensures ((a) % 2 == 0) ==> \result == ((a) / 2);
    ensures ((a) % 2 == 1) ==> \result == (((a) - 1) / 2 + 1);
*/
uint32_t func(uint32_t a)
{
    uint32_t ans;

    //@ assert 1 <= a <= 1000000000;

    if (a % 2 == 0)
    {
        ans = a / 2;
        //@ assert ans == ((a) / 2);
    }
    else
    {
        //@ assert a - 1 >= 0;
        //@ assert (a - 1) / 2 <= 2147483647;
        //@ assert (a - 1) / 2 + 1 <= 2147483648;
        ans = (a - 1) / 2 + 1;
        //@ assert ans == (((a) - 1) / 2 + 1);
    }

    return ans;
}
