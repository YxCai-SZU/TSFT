#include <stddef.h>

/*@
    requires (2 <= (n) && (n) <= 100000);
    ensures \result >= 1;
    ensures \result <= n;
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t l;
    size_t g;
    size_t i;

    //@ assert (2 <= (n) && (n) <= 100000);

    l = 1;
    g = 0;
    i = 2;

    /*@
        loop invariant 2 <= i <= n + 1;
        loop invariant l >= 1;
        loop invariant g >= 0;
        loop invariant l + g <= i;
        loop invariant i > 2 ==> g >= 1;
        loop assigns l, g, i;
        loop variant n - i + 1;
    */
    while (i <= n)
    {
        //@ assert l >= 1;

        if (2 * (i / 2) == i)
        {
            if (g == 0 || l > i / 2)
            {
                l = i / 2;
                g = i / 2 + (i % 2);
            }
        }
        i += 1;
    }

    //@ assert g >= 1;
    return g;
}
