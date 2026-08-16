/*@
    predicate valid_range(integer a, integer b) =
        1 <= a && a <= 3 && 1 <= b && b <= 3;

    logic integer product(integer a, integer b) = a * b;

    lemma product_range: \forall integer a, b;
        valid_range(a, b) ==> 1 <= product(a, b) && product(a, b) <= 9;
*/

#include <stdbool.h>

/*@
    requires valid_range(a, b);
    ensures \result == (a * b * 2 <= 10);
*/
bool func(unsigned long long a, unsigned long long b)
{
    // Variable declarations
    unsigned long long x;

    //@ assert 1 <= a && a <= 3;
    //@ assert 1 <= b && b <= 3;
    //@ assert 1 <= a * b && a * b <= 9;

    x = a * b;
    return x * 2 <= 10;
}
