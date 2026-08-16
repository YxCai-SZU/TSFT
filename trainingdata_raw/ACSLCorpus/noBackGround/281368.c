#include <stddef.h>
#include <stdbool.h>

/*@ requires (1 <= (n) && (n) <= 100 &&
        1 <= (x) && (x) <= 10000 &&
        \valid((l) + (0 .. (n)-1)) &&
        \forall integer j; 0 <= j < (n) ==> 1 <= (l)[j] && (l)[j] <= 100);
    ensures 1 <= \result && \result <= n + 1;
    assigns \nothing;
*/
size_t func(size_t n, size_t x, const size_t *l)
{
    size_t d = 0;
    size_t count = 1;
    size_t i = 0;

    /*@ loop invariant (0 <= (i) && (i) <= (n) &&
        0 <= (d) && (d) <= (x) &&
        1 <= (count) && (count) <= (i) + 1 &&
        \forall integer k; 0 <= k < (i) ==> (d) >= (l)[k]);
        loop assigns i, d, count;
        loop variant n - i;
    */
    while (i < n && d + l[i] <= x)
    {
        //@ assert 0 <= i && i < n;
        d += l[i];
        count += 1;
        i += 1;
    }

    //@ assert 1 <= count && count <= n + 1;
    return count;
}
