#include <stdbool.h>

/*@
    predicate valid_numbers(int *arr, integer len) =
        len >= 3 &&
        \forall integer i; 0 <= i < len ==> 1 <= arr[i] <= 13;
*/

/*@
    logic integer is_arithmetic_sequence(int *arr) =
        (arr[1] - arr[0] == arr[2] - arr[1]) ? 1 : 0;
*/

/*@
    lemma loop_invariant_maintains_validity:
        \forall int *arr, integer len, int n0;
        valid_numbers(arr, len) && 0 <= n0 <= 13 ==>
        valid_numbers(arr, len);
*/

/*@
    requires \valid(numbers + (0 .. 2));
    requires valid_numbers(numbers, 3);
    ensures \result == (is_arithmetic_sequence(numbers) == 1);
    assigns \nothing;
*/
bool func(int *numbers) {
    int n0;
    int n1;
    int n2;
    
    n0 = numbers[0];
    n1 = numbers[1];
    n2 = numbers[2];
    
    if (n1 - n0 == n2 - n1) {
        //@ assert is_arithmetic_sequence(numbers) == 1;
        return true;
    } else {
        /*@
            loop invariant 0 <= n0 <= 13;
            loop invariant valid_numbers(numbers, 3);
            loop assigns n0;
            loop variant 13 - n0;
        */
        while (n0 < 13) {
            n0 = n0 + 1;
            if (n0 == 13) {
                break;
            }
        }
        //@ assert n0 == 13;
        //@ assert is_arithmetic_sequence(numbers) == 0;
        return false;
    }
}
