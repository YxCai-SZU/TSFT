#include <stdint.h>

/*@
    requires ((A) + (B) + (C) >= 1);
    requires ((A) <= 100 && (B) <= 100 && (C) <= 100);
    requires ((K) <= (A) + (B) + (C));
    ensures \result >= 0;
    ensures \result <= K;
    assigns \nothing;
*/
uint32_t func(uint32_t A, uint32_t B, uint32_t C, uint32_t K)
{
    uint32_t res;
    uint32_t min_val;
    uint32_t k;

    res = 0;
    //@ assert res == 0;

    if (A < B)
    {
        if (A < C)
        {
            min_val = A;
        }
        else
        {
            min_val = C;
        }
    }
    else
    {
        if (B < C)
        {
            min_val = B;
        }
        else
        {
            min_val = C;
        }
    }

    k = K;

    if (min_val < k)
    {
        //@ assert min_val < k;
        res = res + min_val;
        //@ assert res == min_val;
        k = k - min_val;
        //@ assert k == K - min_val;
        res = res + (k / 2);
        //@ assert res == min_val + ((K - min_val) / 2);
    }
    else
    {
        //@ assert min_val >= k;
        res = res + k;
        //@ assert res == k;
    }

    //@ assert res >= 0 && res <= K;
    return res;
}
