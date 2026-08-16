#include <stdbool.h>

/*@
    predicate is_valid_range(integer v) = 1 <= v <= 100;

    logic integer adder(integer x, integer y) = x + y;
    logic integer multiplier(integer x, integer y) = x * y;

    lemma adder_test:
        adder(10, 20) == 30 && adder(10, 60) == 70;

    lemma multiplier_test:
        multiplier(10, 20) == 200 && multiplier(10, 60) == 600;
*/

/*@
    requires is_valid_range(a) && is_valid_range(b) && is_valid_range(c) && is_valid_range(d);
    ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int min_ab;
    int min_cd;
    int result;

    //@ assert is_valid_range(a) && is_valid_range(b) && is_valid_range(c) && is_valid_range(d);

    if (a < b) {
        min_ab = a;
    } else {
        min_ab = b;
    }

    if (c < d) {
        min_cd = c;
    } else {
        min_cd = d;
    }

    //@ assert min_ab == a || min_ab == b;
    //@ assert min_cd == c || min_cd == d;

    result = min_ab + min_cd;

    //@ assert result == a + c || result == a + d || result == b + c || result == b + d;
    return result;
}
