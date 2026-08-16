#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    logic integer max_of_three(integer a, integer b, integer c) =
        (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);

    lemma max_property:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==>
            max_of_three(a, b, c) >= a &&
            max_of_three(a, b, c) >= b &&
            max_of_three(a, b, c) >= c &&
            1 <= max_of_three(a, b, c) <= 9;

    lemma result_property:
        \forall integer m;
            1 <= m <= 9 ==>
            \let r = m * 10 + m + m;
            r >= 10 && r <= 999 &&
            r >= m &&
            (r % 10) == (r - (r / 10) * 10) &&
            (r % 10) >= 0;
*/

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result >= 10;
    ensures \result <= 999;
    ensures \result >= a || \result >= b || \result >= c;
    ensures (\result % 10) == (\result - (\result / 10) * 10) && (\result % 10) >= 0;
*/
int func(int a, int b, int c) {
    int max;
    int result;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);

    if (a > b) {
        if (a > c) {
            max = a;
        } else {
            max = c;
        }
    } else {
        if (b > c) {
            max = b;
        } else {
            max = c;
        }
    }

    //@ assert max == max_of_three(a, b, c);
    //@ assert 1 <= max <= 9;
    //@ assert max >= a && max >= b && max >= c;

    result = max * 10 + max + max;

    //@ assert result >= 10 && result <= 999;
    //@ assert result >= max;
    //@ assert result >= a || result >= b || result >= c;
    //@ assert (result % 10) == (result - (result / 10) * 10) && (result % 10) >= 0;

    return result;
}
