#include <stdbool.h>

/*@
    predicate valid_index(integer i, integer len) = 0 <= i < len;
    predicate in_range(integer v) = 1 <= v <= 100;

    predicate valid_vec(int *arr, integer len) =
        len == 3 &&
        \forall integer i; 0 <= i < len ==> in_range(arr[i]);

    lemma sum_check:
        \forall int *arr;
        valid_vec(arr, 3) ==>
        (arr[0] + arr[1] == arr[2] ||
         arr[1] + arr[2] == arr[0] ||
         arr[2] + arr[0] == arr[1]) ==>
        \true;
*/

/*@
    requires \valid(numbers + (0..2));
    requires valid_vec(numbers, 3);
    ensures \result == (numbers[0] + numbers[1] == numbers[2] ||
                       numbers[1] + numbers[2] == numbers[0] ||
                       numbers[2] + numbers[0] == numbers[1]);
*/
bool func(int *numbers) {
    bool ans = false;
    int sum1;
    int sum2;
    int sum3;

    //@ assert valid_vec(numbers, 3);
    //@ assert valid_index(0, 3);
    //@ assert valid_index(1, 3);
    sum1 = numbers[0] + numbers[1];

    //@ assert valid_index(1, 3);
    //@ assert valid_index(2, 3);
    sum2 = numbers[1] + numbers[2];

    //@ assert valid_index(2, 3);
    //@ assert valid_index(0, 3);
    sum3 = numbers[2] + numbers[0];

    if (sum1 == numbers[2] || sum2 == numbers[0] || sum3 == numbers[1]) {
        ans = true;
    }

    //@ assert ans == (sum1 == numbers[2] || sum2 == numbers[0] || sum3 == numbers[1]);
    return ans;
}
