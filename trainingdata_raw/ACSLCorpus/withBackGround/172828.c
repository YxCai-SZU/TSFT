#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_number(integer x) = 1 <= x && x <= 13;
    
    predicate valid_array(int* arr, integer len) =
        len == 3 &&
        \forall integer i; 0 <= i < len ==> valid_number(arr[i]);
*/

/*@
    requires \valid_read(numbers + (0 .. 2));
    requires valid_array(numbers, 3);
    ensures \result == (numbers[0] + numbers[1] + numbers[2] >= 22);
*/
bool func(const int* numbers) {
    int sum = 0;
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index <= 3;
        loop invariant sum >= 0;
        loop invariant sum <= index * 13;
        loop invariant \forall integer i; 0 <= i < index ==> valid_number(numbers[i]);
        loop invariant valid_array(numbers, 3);
        loop invariant index == 0 ==> sum == 0;
        loop invariant index == 1 ==> sum == numbers[0];
        loop invariant index == 2 ==> sum == numbers[0] + numbers[1];
        loop invariant index == 3 ==> sum == numbers[0] + numbers[1] + numbers[2];
        loop assigns sum, index;
        loop variant 3 - index;
    */
    while (index < 3) {
        //@ assert 0 <= index < 3;
        sum += numbers[index];
        index += 1;
    }
    
    //@ assert sum == numbers[0] + numbers[1] + numbers[2];
    return sum >= 22;
}
