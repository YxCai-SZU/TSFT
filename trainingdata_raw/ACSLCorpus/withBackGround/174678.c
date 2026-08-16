#include <stdbool.h>

/*@
    predicate valid_numbers(int* arr, integer len) =
        len == 3 &&
        1 <= arr[0] <= 100 &&
        1 <= arr[1] <= 100 &&
        1 <= arr[2] <= 200;

    logic integer count_ge(int* arr, integer idx) =
        (idx <= 0) ? 0 :
        (arr[idx-1] >= arr[2] ? 1 : 0) + count_ge(arr, idx-1);

    lemma count_bounds:
        \forall int* arr, integer idx;
        valid_numbers(arr, 3) && 0 <= idx <= 2 ==>
        0 <= count_ge(arr, idx) <= idx;
*/

/*@
    requires 
        \valid_read(numbers + (0..2)) &&
        valid_numbers(numbers, 3);
    ensures 
        \result >= 0 && \result <= 3;
*/
int func(int* numbers)
{
    int cnt = 0;
    int index = 0;

    /*@
        loop invariant 
            0 <= index <= 2 &&
            cnt >= 0 &&
            cnt <= index &&
            valid_numbers(numbers, 3);
        loop invariant 
            cnt == count_ge(numbers, index);
        loop assigns 
            cnt, index;
        loop variant 
            2 - index;
    @*/
    while (index < 2)
    {
        //@ assert index >= 0 && index < 2;
        if (numbers[index] >= numbers[2])
        {
            cnt += 1;
        }
        index += 1;
    }
    return cnt;
}
