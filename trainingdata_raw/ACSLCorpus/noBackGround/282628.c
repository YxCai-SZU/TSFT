#include <stddef.h>
#include <stdint.h>

/*@
    requires 2 <= n <= 100000;
    requires \valid(a + (0 .. n-1));
    requires \forall size_t i; 0 <= i < n ==> 1 <= a[i] && a[i] <= n;
    assigns \nothing;
    ensures -1 <= \result <= (int32_t)n;
*/
int32_t func(size_t n, int32_t *a)
{
    size_t state = 0;
    size_t count = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant state >= 0 && state <= i;
        loop invariant ((n) >= 2 && (n) <= 100000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall size_t i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= (n));
        loop assigns i, state, count;
        loop variant n - i;
    */
    while (i < n)
    {
        if (state == 1)
        {
            state = 0;
            count++;
        }
        else
        {
            state = 1;
        }
        i++;
    }

    if (count <= n / 2)
    {
        //@ assert count <= n/2;
        return (int32_t)count;
    }
    else
    {
        //@ assert (n - count) <= n/2;
        return (int32_t)(n - count);
    }
}
