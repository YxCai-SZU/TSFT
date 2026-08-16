#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b, integer c) =
        0 <= a && a <= 1000000000 &&
        0 <= b && b <= 1000000000 &&
        0 <= c && c <= 1000000000;

    logic integer min_val(integer a, integer b, integer c) =
        (a + b + 1 < c) ? (a + b + 1) : c;

    logic integer ans_logic(integer a, integer b, integer c) =
        b + min_val(a, b, c);

    lemma ans_non_negative:
        \forall integer a, b, c;
        valid_input(a, b, c) ==> ans_logic(a, b, c) >= 0;

    lemma ans_upper_bound:
        \forall integer a, b, c;
        valid_input(a, b, c) ==> ans_logic(a, b, c) <= a + b + c;

    lemma case_implication:
        \forall integer a, b, c;
        valid_input(a, b, c) ==>
        (a + b + 1 >= c ==> ans_logic(a, b, c) == b + c);

    lemma case_implication2:
        \forall integer a, b, c;
        valid_input(a, b, c) ==>
        (a + b + 1 < c ==> ans_logic(a, b, c) == a + b + 1 + b);
*/

/*@
    requires valid_input(a, b, c);
    ensures \result >= 0;
    ensures \result <= a + b + c;
    ensures (a + b + 1 >= c ==> \result == b + c);
    ensures (a + b + 1 < c ==> \result == a + b + 1 + b);
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t min_val;
    int64_t ans;

    //@ assert valid_input(a, b, c);

    if (a + b + 1 < c) {
        min_val = a + b + 1;
        //@ assert min_val == a + b + 1;
    } else {
        min_val = c;
        //@ assert min_val == c;
    }

    //@ assert min_val == a + b + 1 || min_val == c;

    ans = b + min_val;

    //@ assert ans == b + c || ans == a + b + 1 + b;

    return ans;
}
