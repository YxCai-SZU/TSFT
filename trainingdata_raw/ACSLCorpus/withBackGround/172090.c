#include <stdint.h>

/*@ predicate valid_input(int32_t* arr, integer len) =
    len == 3 &&
    1 <= arr[0] && arr[0] <= 20 &&
    1 <= arr[1] && arr[1] <= 20 &&
    1 <= arr[2] && arr[2] <= 20;
*/

/*@ logic integer compute_result(integer a, integer b, integer c) =
    c * b - a;
*/

/*@ lemma multiplication_bounds:
    \forall integer a, b;
    1 <= a <= 20 && 1 <= b <= 20 ==>
    1 <= a * b <= 400;
*/

/*@ lemma subtraction_bounds:
    \forall integer a, b, c;
    1 <= a <= 20 && 1 <= b <= 20 && 1 <= c <= 20 ==>
    c * b - a >= 1 * 1 - 20;
*/

/*@
    requires \valid_read(input + (0..2));
    requires valid_input(input, 3);
    ensures \result == compute_result(input[0], input[1], input[2]);
    assigns \nothing;
*/
int32_t func(int32_t* input) {
    int32_t result;
    
    //@ assert 1 <= input[2] && input[2] <= 20;
    //@ assert 1 <= input[1] && input[1] <= 20;
    //@ assert 1 <= input[0] && input[0] <= 20;
    
    //@ assert 1 <= input[2] * input[1] <= 400;
    //@ assert input[2] * input[1] - input[0] >= 1 * 1 - 20;
    
    result = input[2] * input[1] - input[0];
    
    //@ assert result == compute_result(input[0], input[1], input[2]);
    return result;
}
