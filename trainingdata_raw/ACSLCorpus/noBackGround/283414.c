#include <stddef.h>
#include <limits.h>

/*@ requires
        \valid_read(arr + (0 .. len-1)) &&
        (\forall integer i; 0 <= i < (len) ==> (INT_MIN <= ((arr)[i]) <= INT_MAX)) &&
        (INT_MIN <= (num) <= INT_MAX);
    ensures
        \result <= len;
    ensures
        0 <= \result;
    assigns \nothing;
*/
size_t count_occurrences(const int *arr, size_t len, int num)
{
    size_t count = 0;
    size_t i = 0;
    
    /*@ loop invariant
            0 <= i <= len;
        loop invariant
            count <= i;
        loop invariant
            (\forall integer i; 0 <= i < (len) ==> (INT_MIN <= ((arr)[i]) <= INT_MAX));
        loop invariant
            (INT_MIN <= (num) <= INT_MAX);
        loop invariant
            count <= len;
        loop assigns
            i, count;
    */
    while (i < len)
    {
        //@ assert 0 <= i < len ==> (INT_MIN <= (arr[i]) <= INT_MAX);
        if (arr[i] == num)
        {
            count++;
        }
        i++;
    }
    return count;
}
