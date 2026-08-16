#include <stdbool.h>
#include <stddef.h>

/*@
    predicate is_increasing(int* arr, integer len) =
        len >= 3 ==> (arr[0] < arr[1] && arr[1] < arr[2]);
*/

/*@
    requires \valid_read(numbers + (0 .. 2));
    ensures \result == true ==> (numbers[0] < numbers[1] && numbers[1] < numbers[2]);
    ensures \result == false ==> !(numbers[0] < numbers[1] && numbers[1] < numbers[2]);
    assigns \nothing;
*/
bool func(int* numbers) {
    size_t index = 0;
    /*@
        loop invariant 0 <= index <= 2;
        loop invariant index > 0 ==> numbers[0] < numbers[1];
        loop invariant index > 1 ==> numbers[1] < numbers[2];
        loop assigns index;
        loop variant 2 - index;
    */
    while (index < 2) {
        int num = numbers[index];
        int next_num = numbers[index + 1];
        if (num >= next_num) {
            //@ assert !(numbers[0] < numbers[1] && numbers[1] < numbers[2]);
            return false;
        }
        index += 1;
    }
    //@ assert numbers[0] < numbers[1] && numbers[1] < numbers[2];
    return true;
}
