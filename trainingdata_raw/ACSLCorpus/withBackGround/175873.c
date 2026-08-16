#include <stdbool.h>

/*@ predicate is_valid_array(int *arr, integer len) =
    len == 3 &&
    \forall integer i; 0 <= i < len ==> (arr[i] == 1 || arr[i] == 2 || arr[i] == 3) &&
    arr[0] < arr[1] && arr[1] < arr[2];
*/

/*@ logic integer diff(integer a, integer b) = a - b; */

/*@ lemma arithmetic_property:
    \forall int *arr; \forall integer len;
    is_valid_array(arr, len) ==>
    (arr[2] - arr[1] == arr[1] - arr[0]) ==>
    diff(arr[2], arr[1]) == diff(arr[1], arr[0]);
*/

/*@
    requires \valid_read(numbers + (0..2));
    requires is_valid_array(numbers, 3);
    ensures \result == (numbers[2] - numbers[1] == numbers[1] - numbers[0]);
*/
bool func(int *numbers) {
    bool is_arithmetic = false;
    
    //@ assert numbers[0] < numbers[1] && numbers[1] < numbers[2];
    
    if (numbers[2] - numbers[1] == numbers[1] - numbers[0]) {
        is_arithmetic = true;
    }
    
    //@ assert is_arithmetic == (numbers[2] - numbers[1] == numbers[1] - numbers[0]);
    
    return is_arithmetic;
}
