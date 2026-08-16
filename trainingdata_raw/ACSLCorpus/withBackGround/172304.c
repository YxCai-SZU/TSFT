#include <stdbool.h>

/*@
    predicate is_valid_range(integer a, integer b) =
        0 <= a <= 100 && 0 <= b <= 100;

    logic integer total_sum(integer a, integer b) = a + b;

    lemma result_bound:
        \forall integer a, b, r;
        is_valid_range(a, b) && r <= total_sum(a, b) ==> r <= 200;
*/

/*@
    requires is_valid_range(a, b);
    ensures \result <= total_sum(a, b);
    ensures (a == 0 && b == 0) ==> \result == 0;
*/
unsigned int func(unsigned int a, unsigned int b) {
    unsigned int sum;
    unsigned int result;
    bool is_greater;
    unsigned int temp_sum;

    if (a == 0 && b == 0) {
        //@ assert 0 == 0;
        return 0;
    }

    sum = a + b;
    result = 0;
    is_greater = false;
    temp_sum = sum;

    /*@
        loop invariant 0 <= temp_sum <= total_sum(a, b);
        loop invariant result <= (total_sum(a, b) - temp_sum) / 10;
        loop invariant sum == total_sum(a, b);
        loop invariant is_valid_range(a, b);
        loop assigns temp_sum, result;
        loop variant temp_sum;
    */
    while (temp_sum >= 10) {
        temp_sum -= 10;
        result += 1;
    }

    if (temp_sum >= 5) {
        is_greater = true;
    }

    if (is_greater) {
        result += 1;
    }

    //@ assert result <= total_sum(a, b);
    return result;
}
