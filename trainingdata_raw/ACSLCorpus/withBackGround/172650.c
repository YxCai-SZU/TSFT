#include <stdint.h>

/*@
    predicate is_valid_params(integer a, integer b, integer c) =
        2 <= a <= 1000000000 &&
        2 <= b <= 1000000000 &&
        2 <= c <= 1000000000;

    logic integer max_of_three(integer a, integer b, integer c) =
        (a >= b && a >= c) ? a : ((b >= a && b >= c) ? b : c);

    lemma result_bounds:
        \forall integer a, b, c, result;
        is_valid_params(a, b, c) &&
        result == (max_of_three(a, b, c) == a ?
            (a - 1) + (b > 1 ? b - 1 : 0) + (c > 1 ? c - 1 : 0) :
            (max_of_three(a, b, c) == b ?
                (b - 1) + (a > 1 ? a - 1 : 0) + (c > 1 ? c - 1 : 0) :
                (c - 1) + (a > 1 ? a - 1 : 0) + (b > 1 ? b - 1 : 0))) ==>
        result >= 0 && result <= a + b + c;
*/

/*@
    requires is_valid_params(a, b, c);
    ensures \result >= 0;
    ensures \result <= a + b + c;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t max;
    int64_t result = 0;

    //@ assert is_valid_params(a, b, c);

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

    if (max == a) {
        result += a - 1;
        result += (b > 1) ? (b - 1) : 0;
        result += (c > 1) ? (c - 1) : 0;
    } else if (max == b) {
        result += b - 1;
        result += (a > 1) ? (a - 1) : 0;
        result += (c > 1) ? (c - 1) : 0;
    } else {
        result += c - 1;
        result += (a > 1) ? (a - 1) : 0;
        result += (b > 1) ? (b - 1) : 0;
    }

    //@ assert result >= 0;
    //@ assert result <= a + b + c;

    return result;
}
