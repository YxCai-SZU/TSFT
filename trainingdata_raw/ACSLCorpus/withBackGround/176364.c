#include <stdbool.h>

/*@
    predicate is_even(integer x) = x % 2 == 0;
    logic integer product(integer a, integer b) = a * b;
    lemma product_in_range:
        \forall integer a, b;
        1 <= a <= 10000 && 1 <= b <= 10000 ==> 
        product(a, b) <= 10000 * 10000;
*/

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == (product(a, b) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b)
{
    // Variable declarations at scope top
    unsigned long long product;
    bool result;

    //@ assert a <= 10000;
    product = a * b;
    //@ assert product <= 10000 * 10000;
    result = (product % 2 == 0);
    return result;
}
