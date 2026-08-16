#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_range(int* arr, integer len) =
        len == 3 &&
        \forall integer i; 0 <= i < len ==> 1 <= arr[i] && arr[i] <= 100;

    logic integer element_at{L}(int* arr, integer i) = arr[i];
*/

/*@
    requires \valid(numbers + (0 .. 2));
    requires valid_range(numbers, 3);
    assigns \nothing;
    ensures 1 <= \result <= 3;
*/
unsigned int func(int* numbers) {
    unsigned int count = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant count <= (unsigned int)i;
        loop invariant \forall integer j; 0 <= j < i ==> 1 <= numbers[j] && numbers[j] <= 100;
        loop invariant valid_range(numbers, 3);
        loop invariant count <= 3;
        loop assigns i, count;
        loop variant 3 - i;
    */
    while (i < 3) {
        int a = numbers[i];
        //@ assert a == element_at(numbers, i);
        if (a == numbers[i]) {
            count += 1;
        }
        i += 1;
    }
    
    if (count == 3) {
        //@ assert count == 3;
        return 1;
    } else if (count == 2) {
        //@ assert count == 2;
        return 2;
    } else {
        //@ assert count <= 1;
        return 3;
    }
}
