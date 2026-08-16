#include <stdbool.h>
/*@
    predicate valid_range(int* arr, integer len) =
        len == 5 &&
        \forall integer i; 0 <= i < len ==> arr[i] >= 1 && arr[i] <= 5;

    predicate contains_zero(int* arr, integer len) =
        \exists integer i; 0 <= i < len && arr[i] == 0;

    lemma zero_exists_in_range: \forall int* arr, integer len;
        valid_range(arr, len) && contains_zero(arr, len) ==>
        \exists integer i; 0 <= i < len && arr[i] == 0;
*/

/*@
    requires \valid(numbers + (0 .. 4));
    requires valid_range(numbers, 5);
    requires contains_zero(numbers, 5);
    ensures \result >= 1 && \result <= 5;
    ensures numbers[\result - 1] == 0;
*/
int func(int* numbers)
{
    int index = 0;
    /*@
        loop invariant 0 <= index <= 5;
        loop invariant contains_zero(numbers, 5);
        loop invariant \forall integer j; 0 <= j < index ==> numbers[j] != 0;
        loop invariant valid_range(numbers, 5);
        loop assigns index;
    */
    while (index < 5)
    {
        int i = numbers[index];
        if (i == 0)
        {
            //@ assert numbers[index] == 0;
            return index + 1;
        }
        //@ assert numbers[index] != 0;
        index += 1;
    }
    return -1;
}
