#include <stdbool.h>

/*@
    predicate bounds(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer sum_val(integer a, integer b) = a + b;

    lemma sum_bounds:
        \forall integer a, b; bounds(a, b) ==> 1 <= sum_val(a, b) <= 200;
*/

/*@
    requires bounds(a, b);
    ensures \result == (sum_val(a, b) % 2 == 0);
    assigns \nothing;
*/
bool func(int a, int b)
{
    // Variable declarations at top of scope
    int sum;
    bool is_even;
    int abs_sum;
    int temp_sum;

    //@ assert bounds(a, b);
    //@ assert 1 <= sum_val(a, b) <= 200;

    sum = a + b;
    is_even = false;
    abs_sum = sum;

    if (sum < 0) {
        abs_sum = -sum;
    }

    temp_sum = abs_sum;
    /*@
        loop invariant 0 <= temp_sum <= abs_sum;
        loop invariant temp_sum % 2 == abs_sum % 2;
        loop assigns temp_sum;
        loop variant temp_sum;
    */
    while (temp_sum >= 2) {
        temp_sum -= 2;
    }

    if (temp_sum == 0) {
        is_even = true;
    }

    return is_even;
}
