#include <stdint.h>

/*@
    requires (0 <= (x) && (x) <= 9 && 0 <= (a) && (a) <= 9);
    ensures (x < a ==> \result == 0) && (x >= a ==> \result == 10);
    assigns \nothing;
*/
uint32_t input_tuple(uint64_t x, uint64_t a)
{
    // Variable declarations at top of scope
    uint32_t res;

    if (x < a)
    {
        //@ assert x < a;
        res = 0;
    }
    else
    {
        //@ assert x >= a;
        res = 10;
    }

    return res;
}

int main()
{
    return 0;
}
