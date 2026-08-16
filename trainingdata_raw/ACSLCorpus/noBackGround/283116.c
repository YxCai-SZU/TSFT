#include <stdint.h>

/*@
    requires (1 <= (A) && (A) <= 1000 &&
        1 <= (B) && (B) <= 1000 &&
        (A) + (B) <= (X) && (X) <= 10000);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> X - A >= B;
    ensures \result == 0 ==> X - A < B;
    assigns \nothing;
*/
uint32_t func(uint64_t X, uint64_t A, uint64_t B)
{
    uint32_t res;

    //@ assert X >= A + B;
    //@ assert X - A <= 10000;

    if (X - A >= B)
    {
        res = 1;
    }
    else
    {
        res = 0;
    }

    //@ assert res == 1 ==> X - A >= B;
    //@ assert res == 0 ==> X - A < B;

    return res;
}
