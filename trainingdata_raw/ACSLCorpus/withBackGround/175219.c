#include <stdbool.h>

/*@
    predicate valid_vector(int *v, integer len) =
        len == 2 &&
        1 <= v[0] <= 100 &&
        0 <= v[1] <= 4111;

    logic integer vector_sum(int *v) = v[0] * 100 + v[1];

    lemma sum_bounds:
        \forall int *v; valid_vector(v, 2) ==> 100 <= vector_sum(v) <= 14111;
*/

/*@
    requires \valid(v + (0..1));
    requires valid_vector(v, 2);
    ensures \result == (vector_sum(v) % 500 == 0);
    assigns \nothing;
*/
bool func(int *v) {
    int sum;
    bool is_divisible = false;
    int temp_sum;

    sum = v[0] * 100 + v[1];
    temp_sum = sum;

    /*@
        loop invariant 100 <= sum <= 14111;
        loop invariant 0 <= temp_sum <= sum;
        loop invariant temp_sum % 500 == sum % 500;
        loop invariant valid_vector(v, 2);
        loop assigns temp_sum;
        loop variant temp_sum;
    */
    while (temp_sum >= 500) {
        //@ assert temp_sum >= 500;
        temp_sum -= 500;
    }

    if (temp_sum == 0) {
        is_divisible = true;
    }

    //@ assert is_divisible == (vector_sum(v) % 500 == 0);
    return is_divisible;
}
