#include <stdint.h>

/*@ requires ((a) >= 0 && (a) <= 123 &&
        (b) >= 0 && (b) <= 123 &&
        (c) >= 0 && (c) <= 123 &&
        (d) >= 0 && (d) <= 123 &&
        (e) >= 0 && (e) <= 123);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    uint32_t v[5];
    int32_t count;
    uint32_t i;

    v[0] = a;
    v[1] = b;
    v[2] = c;
    v[3] = d;
    v[4] = e;

    count = 0;
    i = 0;

    /*@ loop invariant 0 <= i <= 5;
        loop invariant count >= 0;
        loop invariant count <= i;
        loop invariant \forall integer k; 0 <= k < 5 ==> (v[k] == a || v[k] == b || v[k] == c || v[k] == d || v[k] == e);
        loop assigns i, count;
        loop variant 5 - i;
    */
    while (i < 5)
    {
        //@ assert \forall integer k; 0 <= k < 5 ==> (v[k] == a || v[k] == b || v[k] == c || v[k] == d || v[k] == e);
        if (v[i] == 5)
        {
            count += 1;
        }
        i += 1;
    }

    if (count >= 3)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
