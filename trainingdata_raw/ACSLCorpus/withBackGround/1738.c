#include <stdbool.h>
#include <stddef.h>

/*@
    predicate strictly_decreasing{L}(int *arr, integer len) =
        \forall integer i; 0 <= i < len - 1 ==> arr[i] > arr[i + 1];
 */

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires len < 0x80000000;
    assigns \nothing;
    ensures \result == 1 <==> strictly_decreasing(arr, len);
 */
bool is_strictly_decreasing(int *arr, size_t len)
{
    size_t i = 0;
    
    if (len == 0)
    {
        //@ assert strictly_decreasing(arr, 0);
        return true;
    }

    /*@
        loop invariant 0 <= i <= len-1;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] > arr[j + 1];
        loop assigns i;
        loop variant len-1 - i;
     */
    while (i < len - 1)
    {
        if (arr[i] <= arr[i + 1])
        {
            //@ assert !strictly_decreasing(arr, len);
            return false;
        }
        i++;
    }
    
    //@ assert strictly_decreasing(arr, len);
    return true;
}
