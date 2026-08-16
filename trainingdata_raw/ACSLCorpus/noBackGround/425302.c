#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 1000000000) && (0 <= (b) && (b) <= 1000000000) && (0 <= (c) && (c) <= 1000000000);
    requires 1 <= k && k <= 1000000000;
    requires ((a) + (b) + (c) >= (k));
    ensures \result >= -c;
    ensures \result <= a;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k)
{
    int32_t a_local = a;
    int32_t k_local = k;
    int32_t c_local;

    // take all of A
    //@ assert ((a_local) >= 0);
    if (k_local >= a_local)
    {
        //@ assert k_local >= a_local;
        k_local -= a_local;
    }
    else
    {
        //@ assert k_local < a_local;
        a_local = k_local;
        k_local = 0;
    }

    // take all of B
    //@ assert ((b) >= 0);
    if (k_local >= b)
    {
        //@ assert k_local >= b;
        k_local -= b;
    }
    else
    {
        //@ assert k_local < b;
        k_local = 0;
    }

    // take all of C
    //@ assert ((c) >= 0);
    if (k_local >= c)
    {
        //@ assert k_local >= c;
        c_local = -c;
    }
    else
    {
        //@ assert k_local < c;
        c_local = -k_local;
    }

    // Since we have taken all of A and B, the result is A - C
    //@ assert ((a_local) >= 0);
    int32_t res = a_local + c_local;

    //@ assert a_local >= 0;
    //@ assert k_local == 0 || k_local >= 0;

    return res;
}
