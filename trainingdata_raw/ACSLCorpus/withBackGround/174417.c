#include <limits.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer compute_upper_bound(integer a, integer b) =
        a * 3 + b;

    lemma upper_bound_non_negative:
        \forall integer a, b; valid_range(a, b) ==> compute_upper_bound(a, b) >= 0;
*/

/*@
    requires valid_range(a, b);
    ensures \result >= 0;
    ensures \result <= compute_upper_bound(a, b);
*/
int func(int a, int b) {
    int result;
    int half_result;
    int temp_result;

    // Declare all variables at the top
    int loop_temp_result;
    int loop_half_result;
    int second_loop_temp;

    result = a * 3 + b;
    
    // Implement division by 2 without using the division operator
    half_result = 0;
    temp_result = result;
    loop_temp_result = temp_result;
    loop_half_result = half_result;

    /*@
        loop invariant 0 <= loop_half_result;
        loop invariant loop_half_result <= compute_upper_bound(a, b) / 2;
        loop invariant 0 <= loop_temp_result;
        loop invariant loop_temp_result <= compute_upper_bound(a, b);
        loop invariant loop_temp_result + 2 * loop_half_result == compute_upper_bound(a, b);
        loop invariant valid_range(a, b);
        loop assigns loop_temp_result, loop_half_result;
    */
    while (loop_temp_result >= 2) {
        //@ assert loop_temp_result >= 2;
        loop_temp_result -= 2;
        loop_half_result += 1;
    }
    temp_result = loop_temp_result;
    half_result = loop_half_result;
    result = half_result;
    
    // Implement modulus by 2 without using the modulus operator
    second_loop_temp = result;
    
    /*@
        loop invariant 0 <= second_loop_temp;
        loop invariant second_loop_temp <= compute_upper_bound(a, b);
        loop invariant second_loop_temp <= result;
        loop invariant result <= compute_upper_bound(a, b);
        loop invariant valid_range(a, b);
        loop assigns second_loop_temp;
    */
    while (second_loop_temp >= 2) {
        //@ assert second_loop_temp >= 2;
        second_loop_temp -= 2;
    }
    temp_result = second_loop_temp;
    
    if (temp_result == 1) {
        result = 0;
    } else {
        result = 1;
    }
    
    //@ assert result >= 0;
    return result;
}
