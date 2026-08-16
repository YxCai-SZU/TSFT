#include <limits.h>

/*@
    predicate is_valid_range(integer a, integer b) =
        0 <= a <= 100 && 0 <= b <= 100;

    logic integer total_sum(integer a, integer b) = a + b;

    lemma sum_bounds:
        \forall integer a, b;
        is_valid_range(a, b) ==> 0 <= total_sum(a, b) <= 200;

    lemma double_sum_bounds:
        \forall integer a, b;
        is_valid_range(a, b) ==> 0 <= total_sum(a, b) * 2 <= 400;
*/

/*@
    requires is_valid_range(a, b);
    ensures \result >= 0;
    ensures \result <= (a + b) * 2;
    assigns \nothing;
*/
int func(int a, int b) {
    int sum;
    int result;
    int is_even;
    int temp_sum;

    sum = a + b;
    result = 0;
    is_even = 1;
    temp_sum = sum;

    //@ assert 0 <= sum <= 200;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant (sum - temp_sum) % 2 == 0;
        loop invariant is_valid_range(a, b);
        loop assigns temp_sum;
        loop variant temp_sum;
    */
    while (temp_sum >= 2) {
        temp_sum = temp_sum - 2;
        //@ assert (sum - temp_sum) % 2 == 0;
    }

    if (temp_sum == 1) {
        is_even = 0;
    }

    if (is_even) {
        result = sum;
    } else {
        result = sum * 2;
    }

    //@ assert result >= 0;
    //@ assert result <= (a + b) * 2;
    return result;
}
