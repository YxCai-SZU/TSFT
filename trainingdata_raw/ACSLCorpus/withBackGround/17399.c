#include <stdbool.h>

/*@
    predicate is_valid_range(integer a, integer b, integer c) =
        1 <= a && a <= 10000 &&
        1 <= b && b <= 10000 &&
        1 <= c && c <= 10000;

    logic integer safe_product(integer a, integer b) = a * b;

    lemma product_bound: \forall integer a, b;
        is_valid_range(a, b, 1) ==> safe_product(a, b) <= 100000000;
*/

/*@
    requires is_valid_range(a, b, c);
    ensures \result == (safe_product(a, b) >= c);
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c)
{
    //@ assert a <= 10000;
    //@ assert b <= 10000;
    //@ assert c <= 10000;
    //@ assert safe_product(a, b) <= 100000000;
    
    if (a * b >= c) {
        //@ assert safe_product(a, b) >= c;
        return true;
    } else {
        //@ assert !(safe_product(a, b) >= c);
        return false;
    }
}
