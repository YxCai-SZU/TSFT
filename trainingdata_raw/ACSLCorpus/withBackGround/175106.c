#include <stdbool.h>

/*@
    predicate is_even(integer x) = x % 2 == 0;
    logic integer product(integer a, integer b) = a * b;
    lemma product_in_range:
        \forall integer a, b;
            1 <= a <= 10000 && 1 <= b <= 10000 ==>
            1 <= product(a, b) <= 10000 * 10000;
*/

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == (product(a, b) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    //@ assert 1 <= a && a <= 10000;
    //@ assert 1 <= b && b <= 10000;
    //@ assert product(a, b) <= 10000 * 10000;
    
    return (a * b) % 2 == 0;
}
