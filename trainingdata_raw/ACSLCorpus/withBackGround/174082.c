#include <limits.h>

/*@
    predicate in_range(integer v) = -1000000000 <= v <= 1000000000;
    predicate ordered(integer a, integer b) = a <= b;
    predicate is_product(integer a, integer b, integer p) = p == a * b;
    predicate is_result(integer a, integer b, integer c, integer d, integer r) =
        is_product(b, d, r) || is_product(b, c, r) || is_product(a, d, r) || is_product(a, c, r);
*/

/*@
    requires in_range(A) && in_range(B) && in_range(C) && in_range(D);
    requires ordered(A, B) && ordered(C, D);
    ensures is_result(A, B, C, D, \result);
*/
long long func(long long A, long long B, long long C, long long D)
{
    long long max_val;
    long long temp_max_val;

    //@ assert -1000000000000000000 <= A * C <= 1000000000000000000;
    max_val = A * C;

    //@ assert -1000000000000000000 <= B * C <= 1000000000000000000;
    temp_max_val = B * C;
    if (temp_max_val > max_val) {
        max_val = temp_max_val;
    }

    //@ assert -1000000000000000000 <= B * D <= 1000000000000000000;
    temp_max_val = B * D;
    if (temp_max_val > max_val) {
        max_val = temp_max_val;
    }

    //@ assert -1000000000000000000 <= A * D <= 1000000000000000000;
    temp_max_val = A * D;
    if (temp_max_val > max_val) {
        max_val = temp_max_val;
    }

    //@ assert is_result(A, B, C, D, max_val);
    return max_val;
}
