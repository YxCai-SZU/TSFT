#include <stdbool.h>

/*@
    predicate is_non_empty{L}(int *arr, integer len) =
        len > 0;

    logic integer vec_index{L}(int *arr, integer idx) =
        arr[idx];

    lemma index_in_bounds{L}:
        \forall int *arr, integer len, integer i;
            is_non_empty(arr, len) && 0 <= i < len ==>
            vec_index(arr, i) == arr[i];
*/

/*@
    requires \valid(numbers + (0 .. len-1));
    requires is_non_empty(numbers, len);
    ensures \result >= numbers[0];
    ensures \result >= \old(numbers[0]);
*/
int find_max(int *numbers, int len)
{
    int max;
    int i;

    //@ assert is_non_empty(numbers, len);
    max = numbers[0];
    i = 1;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant max >= numbers[0];
        loop invariant max >= \at(numbers[0], Pre);
        loop assigns max, i;
        loop variant len - i;
    */
    while (i < len)
    {
        if (numbers[i] > max)
        {
            max = numbers[i];
        }
        i = i + 1;
    }

    //@ assert max >= numbers[0];
    return max;
}
