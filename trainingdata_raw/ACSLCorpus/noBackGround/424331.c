#include <stdint.h>

/*@
    requires (1 <= (l) <= (r) <= 100);
    requires (1 <= (d) <= 100);
    ensures \result >= 0;
    ensures \result <= r - l + 1;
*/
int64_t func(int64_t l, int64_t r, int64_t d)
{
    int64_t count = 0;
    int64_t i = l;

    /*@
        loop invariant 1 <= l <= r <= 100;
        loop invariant 1 <= d <= 100;
        loop invariant l <= i <= r + 1;
        loop invariant count >= 0;
        loop invariant count <= (i - l);
        loop invariant i - l <= r - l + 1;
        loop assigns count, i;
        loop variant r - i + 1;
    */
    while (i <= r)
    {
        int64_t j = 0;
        int is_multiple = 0;

        /*@
            loop invariant 1 <= l <= r <= 100;
            loop invariant 1 <= d <= 100;
            loop invariant 0 <= j <= d;
            loop assigns j, is_multiple;
            loop variant d - j;
        */
        while (j < d)
        {
            if (i == j)
            {
                is_multiple = 1;
                break;
            }
            j += 1;
        }

        if (is_multiple)
        {
            count += 1;
        }
        i += 1;
    }

    //@ assert count <= r - l + 1;
    return count;
}
