#include <stdbool.h>

/*@
    predicate in_range(integer v) = 1 <= v <= 9;

    logic integer to_unsigned(integer v) = v < 0 ? v + 4 : v;

    logic integer calculate_sum(integer b, integer c) = 
        to_unsigned(b) * 10 + to_unsigned(c);

    lemma unsigned_preservation:
        \forall integer b, c;
            in_range(b) && in_range(c) ==>
            calculate_sum(b, c) == (b * 10 + c);
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures \result == (((b * 10 + c) % 4) < 1);
*/
bool func(int a, int b, int c) {
    unsigned long long a_u, b_u, c_u, sum_u, result_u;
    long long result;

    // Variable declarations at top
    a_u = (a < 0) ? (a + 4) : a;
    b_u = (b < 0) ? (b + 4) : b;
    c_u = (c < 0) ? (c + 4) : c;

    sum_u = b_u * 10 + c_u;

    //@ assert sum_u == calculate_sum(b, c);
    //@ assert sum_u == (b * 10 + c);

    result_u = sum_u % 4;
    result = (long long)result_u;

    //@ assert result_u == ((b * 10 + c) % 4);

    return result < 1;
}
