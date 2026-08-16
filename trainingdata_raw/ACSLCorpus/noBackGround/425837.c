#include <stddef.h>
#include <stdint.h>

/*@
    requires 2 <= k <= 1000000;
    requires 2 <= n <= 200000;
    requires \valid(a + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) - 1 ==> (a)[i] < (a)[i + 1]);
    requires (\forall integer i; 0 <= i < (n) ==> 0 <= (a)[i] && (a)[i] < (k));
    assigns \nothing;
    ensures 0 <= \result <= k;
*/
int32_t func(int32_t k, size_t n, int32_t *a)
{
    int32_t m = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= n - 1;
        loop invariant 0 <= m <= k;
        loop invariant (\forall integer i; 0 <= i < (n) - 1 ==> (a)[i] < (a)[i + 1]);
        loop invariant (\forall integer i; 0 <= i < (n) ==> 0 <= (a)[i] && (a)[i] < (k));
        loop assigns m, i;
        loop variant n - 1 - i;
    */
    while (i < n - 1)
    {
        int32_t next_a = a[i + 1];
        int32_t diff = next_a - a[i];
        int32_t candidate = k - diff;

        //@ assert 0 <= diff < k;
        //@ assert 0 <= candidate <= k;

        if (m < candidate)
        {
            m = m;
        }
        else
        {
            m = candidate;
        }

        //@ assert 0 <= m <= k;
        i += 1;
    }

    //@ assert 0 <= m <= k;
    return m;
}
