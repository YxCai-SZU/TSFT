#include <limits.h>

/*@
    requires (0 <= (A) <= 100 &&
        0 <= (B) <= 100 &&
        0 <= (C) <= 100 &&
        1 <= (K) <= (A) + (B) + (C));
    ensures \result >= -C;
    ensures \result <= A;
    ensures \result == ((K) > (A) ?
            ((K) > (A) + (B) ?
                ((K) > (A) + (B) + (C) ? (A) - (C) : (A) - ((K) - (A) - (B)))
                : (A))
            : (K));
*/
int func(int A, int B, int C, int K)
{
    int res;
    int remaining_k;

    res = 0;
    remaining_k = K;

    //@ assert remaining_k == K && res == 0;

    if (remaining_k > A)
    {
        res += A;
        remaining_k -= A;
        //@ assert res == A && remaining_k == K - A;
    }
    else
    {
        res += remaining_k;
        //@ assert res == K && K <= A;
        return res;
    }

    //@ assert res == A && remaining_k == K - A;

    if (remaining_k > B)
    {
        remaining_k -= B;
        //@ assert remaining_k == K - A - B;
    }
    else
    {
        remaining_k = 0;
        //@ assert remaining_k == 0;
    }

    //@ assert remaining_k == (K > A + B ? K - A - B : 0);

    if (remaining_k > C)
    {
        res -= C;
        //@ assert res == A - C;
    }
    else
    {
        res -= remaining_k;
        //@ assert res == A - remaining_k;
    }

    //@ assert res >= -C;
    //@ assert res <= A;

    return res;
}
