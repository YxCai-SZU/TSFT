#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 3 && 1 <= b <= 3;

    logic integer safe_product(integer a, integer b) =
        a * b;

    lemma product_bound: \forall integer a, b;
        valid_range(a, b) ==> safe_product(a, b) <= 9;
*/

/*@
    requires valid_range(a, b);
    ensures \result == (a * b % 2 != 0);
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b)
{
    // Variable declarations at top of scope
    bool result;
    unsigned long product;
    unsigned long remainder;

    //@ assert 1 <= a <= 3;
    //@ assert 1 <= b <= 3;
    //@ assert a * b <= 9;

    product = a * b;
    remainder = product % 2;

    if (remainder == 0)
    {
        result = false;
    }
    else
    {
        result = true;
    }

    //@ assert result == (a * b % 2 != 0);
    return result;
}
