#include <stddef.h>
#include <stdint.h>

/*@
    requires ((n) > 0 && (n) <= 20 &&
        \valid((h) + (0 .. (n)-1)) &&
        \forall size_t i; 0 <= i < (n) ==> 1 <= (h)[i] <= 100);
    ensures 0 <= \result <= n-1;
    assigns \nothing;
*/
int64_t func(size_t n, int64_t *h)
{
    int64_t max = 0;
    int64_t step = 0;
    size_t i = 1;

    /*@
        loop invariant 1 <= i <= n;
        loop invariant 0 <= max <= i-1;
        loop invariant 0 <= step <= i-1;
        loop invariant ((n) > 0 && (n) <= 20 &&
        \valid((h) + (0 .. (n)-1)) &&
        \forall size_t i; 0 <= i < (n) ==> 1 <= (h)[i] <= 100);
        loop assigns i, max, step;
        loop variant n - i;
    */
    while (i < n)
    {
        if (h[i - 1] >= h[i])
        {
            step = step + 1;
        }
        else
        {
            max = (max > step) ? max : step;
            step = 0;
        }

        i = i + 1;
    }

    max = (max > step) ? max : step;

    return max;
}
