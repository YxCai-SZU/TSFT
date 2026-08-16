#include <stdbool.h>
#include <stddef.h>

/*@ predicate has_zero_at(integer idx, int* arr, integer len) =
    idx >= 0 && idx < len && arr[idx] == 0;
*/

/*@ predicate has_zero_in_first_five(int* arr) =
    has_zero_at(0, arr, 5) ||
    has_zero_at(1, arr, 5) ||
    has_zero_at(2, arr, 5) ||
    has_zero_at(3, arr, 5) ||
    has_zero_at(4, arr, 5);
*/

/*@ predicate no_zero_before(integer idx, int* arr) =
    \forall integer k; 0 <= k < idx ==> arr[k] != 0;
*/

/*@ lemma zero_exists_in_range:
    \forall int* arr; has_zero_in_first_five(arr) && no_zero_before(5, arr) ==> false;
*/

/*@
    requires \valid_read(arr + (0..4));
    requires has_zero_in_first_five(arr);
    ensures 1 <= \result <= 5;
    ensures \result == 1 ==> has_zero_at(0, arr, 5);
    ensures \result == 2 ==> has_zero_at(1, arr, 5);
    ensures \result == 3 ==> has_zero_at(2, arr, 5);
    ensures \result == 4 ==> has_zero_at(3, arr, 5);
    ensures \result == 5 ==> has_zero_at(4, arr, 5);
*/
int func(int* arr) {
    size_t index;
    index = 0;

    /*@
        loop invariant 0 <= index <= 5;
        loop invariant has_zero_in_first_five(arr);
        loop invariant no_zero_before(index, arr);
        loop assigns index;
        loop variant 5 - index;
    */
    while (index < 5) {
        //@ assert index >= 0 && index < 5;
        if (arr[index] == 0) {
            //@ assert has_zero_at(index, arr, 5);
            return (int)(index + 1);
        }
        //@ assert arr[index] != 0;
        index++;
    }
    //@ assert no_zero_before(5, arr);
    return -1;
}
