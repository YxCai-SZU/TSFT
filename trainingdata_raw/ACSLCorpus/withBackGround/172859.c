#include <stdbool.h>

/*@ predicate valid_range(int *arr, integer len) =
      len == 3 &&
      \forall integer i; 0 <= i < len ==> 1 <= arr[i] && arr[i] <= 13;
*/

/*@ logic integer diff_at(int *arr, integer i) =
      arr[i+1] - arr[i];
*/

/*@ lemma diff_equality:
      \forall int *arr;
        valid_range(arr, 3) ==>
        (diff_at(arr, 0) == diff_at(arr, 1)) ==>
        (arr[1] - arr[0] == arr[2] - arr[1]);
*/

/*@ requires \valid_read(numbers + (0..2));
    requires valid_range(numbers, 3);
    assigns \nothing;
    ensures \result == (numbers[1] - numbers[0] == numbers[2] - numbers[1]);
*/
bool func(int *numbers) {
    int a;
    int b;
    int c;
    int diff1;
    int diff2;
    bool result;

    a = numbers[0];
    b = numbers[1];
    c = numbers[2];

    //@ assert a >= 1 && a <= 13;
    diff1 = b - a;
    diff2 = c - b;

    //@ assert diff1 == diff2 ==> (numbers[1] - numbers[0] == numbers[2] - numbers[1]);
    result = (diff1 == diff2);
    return result;
}
