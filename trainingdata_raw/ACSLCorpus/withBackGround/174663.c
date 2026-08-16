#include <stdbool.h>
/*@
    predicate valid_range(int* arr, integer len) =
        \forall integer i; 0 <= i < len ==> 1 <= arr[i] && arr[i] <= 5;

    predicate exists_zero(int* arr, integer len) =
        \exists integer i; 0 <= i < len && arr[i] == 0;

    predicate zero_at_index(int* arr, integer len, integer idx) =
        0 <= idx < len && arr[idx] == 0;

    predicate no_zero_before(int* arr, integer idx) =
        \forall integer i; 0 <= i < idx ==> arr[i] != 0;

    lemma loop_invariant_maintains:
        \forall int* arr, integer len, integer i, integer idx;
        valid_range(arr, len) && exists_zero(arr, len) && 0 <= i <= len &&
        1 <= idx <= 5 && idx <= i &&
        (idx > 0 ==> zero_at_index(arr, len, idx-1)) &&
        (idx > 0 ==> no_zero_before(arr, idx-1)) ==>
        (i < len ==> (arr[i] == 0 ==> idx == 0) && (arr[i] != 0 ==> idx+1 <= i+1));
*/

/*@
    requires \valid(numbers+(0..4));
    requires valid_range(numbers, 5);
    requires exists_zero(numbers, 5);
    ensures 1 <= \result <= 5;
    ensures \result == 0 ==> \forall integer i; 0 <= i < 5 ==> numbers[i] != 0;
    ensures \result > 0 ==> numbers[\result-1] == 0;
*/
int func(int* numbers) {
    int index = 1;
    int i = 0;
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant 1 <= index <= 5;
        loop invariant valid_range(numbers, 5);
        loop invariant exists_zero(numbers, 5);
        loop invariant index <= i;
        loop invariant index > 0 ==> zero_at_index(numbers, 5, index-1);
        loop invariant index > 0 ==> no_zero_before(numbers, index-1);
        loop assigns i, index;
        loop variant 5-i;
    */
    while (i < 5) {
        int number = numbers[i];
        if (number == 0) {
            index = 0;
            break;
        }
        //@ assert number != 0;
        index += 1;
        i += 1;
    }
    //@ assert 1 <= index <= 5 || index == 0;
    return index;
}

int main() {
    return 0;
}
