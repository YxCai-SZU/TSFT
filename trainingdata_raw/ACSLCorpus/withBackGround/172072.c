#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10;

    logic integer product(integer a, integer b, integer c) = a * b * c;

    lemma product_range:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==>
            1 <= product(a, b, c) <= 1000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == (a * b * c >= 100);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    int abc;
    bool result;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert 1 <= a * b <= 100;
    //@ assert 1 <= a * b * c <= 1000;

    abc = a * b * c;
    result = abc >= 100;

    return result;
}
