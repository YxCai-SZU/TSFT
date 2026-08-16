#include <stdbool.h>

/*@
    predicate bounds(integer a, integer b) =
        1 <= a <= 10000 && 1 <= b <= 10000;

    logic integer safe_product(integer a, integer b) =
        a > 10000 ? 10000 * b : a * b;

    lemma product_bound:
        \forall integer a, b;
            bounds(a, b) ==> a * b <= 10000 * 10000;
*/

/*@
    requires bounds(a, b);
    ensures \result == ((a * b) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b)
{
    unsigned long long product_approx;
    unsigned long long approx_a;

    //@ assert a <= 10000 && b <= 10000;
    //@ assert a * b <= 10000 * 10000;

    if (a > 10000)
    {
        product_approx = a * b;
    }
    else
    {
        if (a > 10000)
        {
            approx_a = 10000;
        }
        else
        {
            approx_a = a;
        }
        product_approx = approx_a * b;
    }

    return product_approx % 2 == 0;
}
