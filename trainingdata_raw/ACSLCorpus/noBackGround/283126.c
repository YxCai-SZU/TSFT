#include <stdint.h>

/*@
    requires (1 <= (A) && (A) <= 1000000000 &&
        1 <= (B) && (B) <= 1000000000 &&
        1 <= (C) && (C) <= 1000000000 &&
        1 <= (A) + (B) + (C) && (A) + (B) + (C) <= 1000000000 &&
        (K) <= (A) + (B) + (C));
    ensures \result >= -(int)C;
    ensures \result <= (int)A;
    assigns \nothing;
*/
int32_t func(uint32_t A, uint32_t B, uint32_t C, uint32_t K)
{
    int32_t res = 0;
    uint32_t k = K;

    // First block: handle A
    if (k >= A)
    {
        //@ assert k >= A;
        res += (int32_t)A;
        k -= A;
    }
    else
    {
        //@ assert k < A;
        res += (int32_t)k;
        k = 0;
    }

    // Second block: handle B
    if (k >= B)
    {
        //@ assert k >= B;
        k -= B;
    }
    else
    {
        //@ assert k < B;
        k = 0;
    }

    // Third block: handle C
    if (k >= C)
    {
        //@ assert k >= C;
        res -= (int32_t)C;
        k -= C;
    }
    else
    {
        //@ assert k < C;
        res -= (int32_t)k;
        k = 0;
    }

    //@ assert res >= -(int)C;
    return res;
}
