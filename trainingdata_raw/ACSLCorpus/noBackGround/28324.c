#include <stdint.h>

/*@
    requires 1 <= l <= r <= 100;
    requires 1 <= d <= 100;
    ensures \result >= 0;
    ensures \result <= r - l + 1;
    assigns \nothing;
*/
int64_t func(int64_t l, int64_t r, int64_t d)
{
    int64_t count;
    int64_t current;
    int64_t j;
    int is_multiple;

    count = 0;
    current = l;

    /*@
        loop invariant l <= current <= r + 1;
        loop invariant 0 <= count <= current - l;
        loop invariant 1 <= l <= 100;
        loop invariant 1 <= d <= 100;
        loop assigns count, current, j, is_multiple;
        loop variant r - current + 1;
    */
    while (current <= r)
    {
        j = 0;
        is_multiple = 0;

        /*@
            loop invariant 0 <= j <= d;
            loop invariant 1 <= d <= 100;
            loop invariant is_multiple == 0 || is_multiple == 1;
            loop assigns j, is_multiple;
            loop variant d - j;
        */
        while (j < d)
        {
            //@ assert j >= 0 && j <= d;
            if (current == j)
            {
                is_multiple = 1;
                break;
            }
            j += 1;
        }

        //@ assert is_multiple == 0 || is_multiple == 1;
        if (is_multiple)
        {
            count += 1;
        }
        //@ assert count >= 0;
        current += 1;
    }

    //@ assert count >= 0;
    //@ assert count <= r - l + 1;
    return count;
}
