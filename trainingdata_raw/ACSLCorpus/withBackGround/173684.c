#include <limits.h>

/*@
    predicate in_range(integer v) = -1000000000 <= v <= 1000000000;

    logic integer max_of_four(integer ac, integer ad, integer bc, integer bd) =
        (ad > ac ? ad : ac) > (bc > bd ? bc : bd) ?
        (ad > ac ? ad : ac) : (bc > bd ? bc : bd);

    lemma product_in_range:
        \forall integer x, y;
            in_range(x) && in_range(y) ==> -1000000000000000000 <= x * y <= 1000000000000000000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    requires a <= b && c <= d;
    ensures \result == b * d || \result == a * d || \result == b * c || \result == a * c;
    assigns \nothing;
*/
long long func(long long a, long long b, long long c, long long d) {
    long long max_val;
    long long temp_val;

    //@ assert -1000000000000000000 <= a * c <= 1000000000000000000;
    max_val = a * c;

    //@ assert -1000000000000000000 <= a * d <= 1000000000000000000;
    temp_val = a * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    //@ assert -1000000000000000000 <= b * c <= 1000000000000000000;
    temp_val = b * c;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    //@ assert -1000000000000000000 <= b * d <= 1000000000000000000;
    temp_val = b * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    return max_val;
}
