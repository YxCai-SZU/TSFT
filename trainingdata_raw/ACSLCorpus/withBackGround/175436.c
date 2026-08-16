#include <stdbool.h>

/*@ predicate is_valid_range(int *arr, integer len) =
    len == 3 &&
    \forall integer i; 0 <= i < len ==> 1 <= arr[i] <= 100;
*/

/*@ predicate condition1(int *arr) =
    arr[1] < arr[0] && arr[2] < arr[1];
*/

/*@ predicate condition2(int *arr) =
    arr[1] < arr[2] && arr[0] < arr[1];
*/

/*@ requires \valid_read(numbers + (0..2));
    requires is_valid_range(numbers, 3);
    ensures \result <==> (condition1(numbers) || condition2(numbers));
*/
bool func(int *numbers) {
    bool result;
    
    if (numbers[1] < numbers[0] && numbers[2] < numbers[1]) {
        //@ assert condition1(numbers);
        result = true;
    } else if (numbers[1] < numbers[2] && numbers[0] < numbers[1]) {
        //@ assert condition2(numbers);
        result = true;
    } else {
        //@ assert !condition1(numbers) && !condition2(numbers);
        result = false;
    }
    
    return result;
}
