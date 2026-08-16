#include <stdbool.h>

/*@
    predicate in_range(integer a) = 1 <= a <= 10000;

    logic integer product(integer a, integer b) = a * b;

    lemma product_in_range:
        \forall integer a, b;
            in_range(a) && in_range(b) ==> product(a, b) <= 100000000;
*/

/*@
    requires in_range(a) && in_range(b);
    ensures \result == (product(a, b) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int c;
    bool ans;

    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert product(a, b) <= 100000000;

    c = a * b;

    //@ assert c == product(a, b);

    switch (c % 2) {
        case 0:
            ans = true;
            break;
        case 1:
            ans = false;
            break;
        default:
            ans = false;
            break;
    }

    //@ assert ans == (product(a, b) % 2 == 0);
    return ans;
}
