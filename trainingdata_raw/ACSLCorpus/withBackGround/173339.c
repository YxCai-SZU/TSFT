#include <stdint.h>

/*@
    predicate is_valid_params(integer a, integer b, integer c) =
        1 <= a && a <= 1000000000 &&
        1 <= b && b <= 1000000000 &&
        1 <= c && c <= 1000000000;

    logic integer sum_ab(integer a, integer b) = a + b;
    logic integer sum_bc(integer b, integer c) = b + c;
    logic integer sum_ca(integer c, integer a) = c + a;

    predicate is_degenerate(integer a, integer b, integer c) =
        sum_ab(a,b) == c || sum_bc(b,c) == a || sum_ca(c,a) == b;

    predicate is_triangle(integer a, integer b, integer c) =
        sum_ab(a,b) > c && sum_bc(b,c) > a && sum_ca(c,a) > b;

    lemma no_overflow_ab:
        \forall integer a,b;
        is_valid_params(a,b,1) ==> sum_ab(a,b) <= 18446744073709551615;

    lemma no_overflow_bc:
        \forall integer b,c;
        is_valid_params(1,b,c) ==> sum_bc(b,c) <= 18446744073709551615;

    lemma no_overflow_ca:
        \forall integer a,c;
        is_valid_params(a,1,c) ==> sum_ca(c,a) <= 18446744073709551615;
*/

/*@
    requires is_valid_params(a,b,c);
    ensures \result == 1 || \result == 2 || \result == 0;
    ensures \result == 1 ==> is_degenerate(a,b,c);
    ensures \result == 2 ==> (is_triangle(a,b,c) && !is_degenerate(a,b,c));
    ensures \result == 0 ==> (!is_triangle(a,b,c) && !is_degenerate(a,b,c));
*/
int32_t func(uint64_t a, uint64_t b, uint64_t c) {
    // Variable declarations at scope top
    uint64_t sum_ab;
    uint64_t sum_bc;
    uint64_t sum_ca;
    int32_t result;

    //@ assert a + b <= 18446744073709551615;
    sum_ab = a + b;
    //@ assert b + c <= 18446744073709551615;
    sum_bc = b + c;
    //@ assert c + a <= 18446744073709551615;
    sum_ca = c + a;

    if (sum_ab == c || sum_bc == a || sum_ca == b) {
        result = 1;
    } else if (sum_ab > c && sum_bc > a && sum_ca > b) {
        result = 2;
    } else {
        result = 0;
    }

    return result;
}
