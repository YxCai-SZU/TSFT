#include <limits.h>

/*@
    predicate is_valid_input(integer a, integer b, integer c) =
        1 <= a && a <= 9 &&
        1 <= b && b <= 9 &&
        1 <= c && c <= 9;

    logic integer max_of_three(integer a, integer b, integer c) =
        (a > b && a > c) ? a :
        (b > c) ? b :
        c;

    logic integer compute_result(integer a, integer b, integer c) =
        max_of_three(a, b, c) * 10 +
        ((max_of_three(a, b, c) == a) ? (b + c) :
         (max_of_three(a, b, c) == b) ? (a + c) :
         (a + b));

    lemma result_properties:
        \forall integer a, b, c;
        is_valid_input(a, b, c) ==>
        (compute_result(a, b, c) == (a * 10 + b + c) ||
         compute_result(a, b, c) == (a + b * 10 + c) ||
         compute_result(a, b, c) == (a + b + c * 10));

    lemma result_ge_10:
        \forall integer a, b, c;
        is_valid_input(a, b, c) ==> compute_result(a, b, c) >= 10;
*/

/*@
    requires is_valid_input(a, b, c);
    ensures \result == (a * 10 + b + c) ||
            \result == (a + b * 10 + c) ||
            \result == (a + b + c * 10);
    ensures \result >= 10;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int max;
    int ans;

    //@ assert is_valid_input(a, b, c);

    if (a > b && a > c) {
        max = a;
    } else if (b > c) {
        max = b;
    } else {
        max = c;
    }

    //@ assert max == max_of_three(a, b, c);

    if (max == a) {
        ans = max * 10 + b + c;
    } else if (max == b) {
        ans = max * 10 + a + c;
    } else {
        ans = max * 10 + a + b;
    }

    //@ assert ans == compute_result(a, b, c);
    //@ assert ans == (a * 10 + b + c) || ans == (a + b * 10 + c) || ans == (a + b + c * 10);
    //@ assert ans >= 10;

    return ans;
}
