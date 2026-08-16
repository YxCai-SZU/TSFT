#include <stdbool.h>

/*@ predicate valid_input(int *arr, integer len) =
    len == 3 &&
    \forall integer i; 0 <= i < len ==> 1 <= arr[i] <= 13;
*/

/*@ logic integer get_element(int *arr, integer idx) = arr[idx]; */

/*@ lemma sum_relation:
    \forall int *arr;
    valid_input(arr, 3) ==>
    get_element(arr, 1) + get_element(arr, 2) >= get_element(arr, 0) ==>
    true;
*/

/*@
    requires \valid_read(input + (0..2));
    requires valid_input(input, 3);
    assigns \nothing;
    ensures \result == (input[1] + input[2] >= input[0]);
*/
bool func(int *input) {
    bool ans = false;
    int a = input[0];
    int b = input[1];
    int c = input[2];
    
    //@ assert valid_input(input, 3);
    //@ assert a == get_element(input, 0);
    //@ assert b == get_element(input, 1);
    //@ assert c == get_element(input, 2);
    
    if (b + c >= a) {
        ans = true;
    }
    
    //@ assert ans == (b + c >= a);
    return ans;
}
