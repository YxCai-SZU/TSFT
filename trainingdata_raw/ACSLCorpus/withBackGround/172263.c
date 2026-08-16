/*@
    predicate valid_params(integer d, integer t, integer s) =
        1 <= d <= 10000 &&
        1 <= t <= 10000 &&
        1 <= s <= 10000;

    logic integer product(integer t, integer s) = t * s;

    lemma product_bound:
        \forall integer t, s;
        valid_params(1, t, s) ==> product(t, s) <= 10000 * 10000;
*/

#include <stdbool.h>

/*@
    requires valid_params(d, t, s);
    ensures \result == (product(t, s) >= d);
    assigns \nothing;
*/
bool func(unsigned long d, unsigned long t, unsigned long s)
{
    // Variable declarations at scope top
    unsigned long i;

    //@ assert valid_params(d, t, s);
    //@ assert product(t, s) <= 10000 * 10000;

    i = 0;
    /*@
        loop invariant 0 <= i <= 10;
        loop invariant valid_params(d, t, s);
        loop assigns i;
        loop variant 10 - i;
    */
    while (i < 10)
    {
        i = i + 1;
    }

    return t * s >= d;
}

int main()
{
    return 0;
}
