#include <limits.h>

/*@
    predicate in_range(integer v) = 1 <= v <= 100;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bound:
        \forall integer x, y;
            in_range(x) && in_range(y) ==> product(x, y) <= 10000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures \result == product(a, c) ||
            \result == product(a, d) ||
            \result == product(b, d) ||
            \result == product(c, a) ||
            \result == product(c, b) ||
            \result == product(d, a) ||
            \result == product(d, b);
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    // Variable declarations at top of scope
    long max_val;
    long temp_val;

    // Precondition assertions
    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    //@ assert in_range(d);

    // Multiplication bounds verification
    //@ assert product(a, c) <= 10000;
    //@ assert product(a, d) <= 10000;
    //@ assert product(b, d) <= 10000;
    //@ assert product(c, a) <= 10000;
    //@ assert product(c, b) <= 10000;
    //@ assert product(d, a) <= 10000;
    //@ assert product(d, b) <= 10000;

    max_val = a * c;

    temp_val = a * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    temp_val = b * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    temp_val = c * a;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    temp_val = c * b;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    temp_val = d * a;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    temp_val = d * b;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    // Postcondition verification
    //@ assert max_val == product(a, c) || max_val == product(a, d) || max_val == product(b, d) || max_val == product(c, a) || max_val == product(c, b) || max_val == product(d, a) || max_val == product(d, b);
    return max_val;
}
