#include <stddef.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (((a) + (b) + 1) / 2);
    assigns \nothing;
*/
size_t func(size_t a, size_t b)
{
    size_t c;
    size_t ans;
    size_t temp_c;
    size_t count;

    c = a + b;
    ans = 0;
    temp_c = c;
    count = 0;

    /*@
        loop invariant 0 <= temp_c <= c;
        loop invariant count == (c - temp_c) / 2;
        loop invariant temp_c + 2 * count == c;
        loop assigns temp_c, count;
        loop variant temp_c;
    */
    while (temp_c >= 2)
    {
        //@ assert temp_c >= 2;
        temp_c -= 2;
        count += 1;
    }

    ans = count;

    if (temp_c == 1)
    {
        //@ assert temp_c == 1;
        ans += 1;
    }

    //@ assert ans == (((a) + (b) + 1) / 2);
    return ans;
}
