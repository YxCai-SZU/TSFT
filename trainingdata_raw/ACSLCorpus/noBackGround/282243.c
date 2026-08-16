#include <stddef.h>
#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 &&
        1 <= (x) <= 10000 &&
        \valid((l) + (0 .. (n)-1)) &&
        \forall integer k; 0 <= k < (n) ==> 1 <= (l)[k] <= 100);
    ensures 1 <= \result <= n + 1;
    assigns \nothing;
*/
size_t func(size_t n, size_t x, const size_t l[])
{
    size_t count = 1;
    size_t d = 0;
    size_t i = 0;

    /*@
        loop invariant (0 <= (i) <= (n) &&
        1 <= (n) <= 100 &&
        1 <= (x) <= 10000 &&
        1 <= (count) <= (i) + 1 &&
        0 <= (d) <= (x) + ((i) + 1) * 100 &&
        \forall integer k; 0 <= k < (i) ==> 1 <= (l)[k] <= 100);
        loop assigns i, d, count;
        loop variant n - i;
    */
    while (i < n)
    {
        size_t a = l[i];
        d = d + a;

        //@ assert d >= 0;
        if (d <= x)
        {
            count = count + 1;
        }

        i = i + 1;
    }

    //@ assert 1 <= count <= n + 1;
    return count;
}
