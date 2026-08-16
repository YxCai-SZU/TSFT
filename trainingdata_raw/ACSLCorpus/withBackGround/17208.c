#include <stdbool.h>

/*@
    predicate valid_index_range(integer i, integer len) =
        0 <= i < len;

    predicate valid_value(integer v) =
        1 <= v <= 13;

    predicate array_valid(int *arr, integer len) =
        len >= 3 &&
        \forall integer i; 0 <= i < len ==> valid_value(arr[i]);

    logic integer element_at(int *arr, integer i) = arr[i];

    logic integer sum_first_three(int *arr) =
        element_at(arr, 0) + element_at(arr, 1) + element_at(arr, 2);

    lemma sum_bounds:
        \forall int *arr, integer len;
        array_valid(arr, len) ==> 3 <= sum_first_three(arr) <= 39;
*/

/*@
    requires \valid_read(numbers + (0 .. 2));
    requires array_valid(numbers, len);
    ensures \result == (sum_first_three(numbers) >= 22);
*/
bool func(int *numbers, int len) {
    long long a = 0;
    int index = 0;

    /*@
        loop invariant 0 <= index <= 3;
        loop invariant a >= 0;
        loop invariant a <= index * 13;
        loop invariant index == 0 ==> a == 0;
        loop invariant index == 1 ==> a == element_at(numbers, 0);
        loop invariant index == 2 ==> a == element_at(numbers, 0) + element_at(numbers, 1);
        loop invariant index == 3 ==> a == sum_first_three(numbers);
        loop invariant \forall integer i; 0 <= i < index ==> valid_value(element_at(numbers, i));
        loop invariant array_valid(numbers, len);
        loop assigns a, index;
        loop variant 3 - index;
    */
    while (index < 3 && index < len) {
        //@ assert valid_index_range(index, len);
        a += numbers[index];
        index++;
    }
    
    //@ assert a == sum_first_three(numbers);
    return a >= 22;
}
