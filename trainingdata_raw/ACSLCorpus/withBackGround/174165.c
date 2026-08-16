#include <stdbool.h>

/*@
    predicate is_odd_product(integer a, integer b, bool result) =
        result == ((a * b) % 2 != 0);
*/

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == ((a * b) % 2 != 0);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b)
{
    unsigned long long c;
    bool is_odd;

    //@ assert a <= 10000 && b <= 10000 && a * b <= 10000 * 10000;
    c = a * b;

    if (c % 2 == 1)
        is_odd = true;
    else
        is_odd = false;

    //@ assert is_odd == ((a * b) % 2 != 0);
    return is_odd;
}
