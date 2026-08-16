#include <stddef.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= p <= 100;
    ensures \result == (a * 3 + p) / 2;
    assigns \nothing;
*/
size_t func(size_t a, size_t p)
{
    size_t k;
    size_t pies = 0;
    size_t temp_k;

    k = a * 3 + p;

    //@ assert k == a * 3 + p;
    //@ assert 0 <= k <= 400;

    temp_k = k;

    /*@
        loop invariant 0 <= temp_k <= k;
        loop invariant 0 <= pies <= k / 2;
        loop invariant temp_k == k - 2 * pies;
        loop assigns pies, temp_k;
        loop variant temp_k;
    */
    while (temp_k >= 2)
    {
        //@ assert temp_k >= 2;
        temp_k = temp_k - 2;
        pies = pies + 1;
    }

    //@ assert pies == (a * 3 + p) / 2;
    return pies;
}
