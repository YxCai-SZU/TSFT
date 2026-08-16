#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires len > 0;
    assigns \nothing;
    ensures \result == 1 <==> (\forall integer i; 0 <= i < (len) ==> (arr)[i] <= (k));
    ensures \result == 0 <==> !(\forall integer i; 0 <= i < (len) ==> (arr)[i] <= (k));
 */
bool func(unsigned int *arr, size_t len, unsigned int k)
{
    size_t i = 0;
    //@ ghost unsigned int *old_arr = arr;
    //@ ghost size_t old_len = len;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] <= k;
        loop invariant len == old_len;
        loop invariant arr == old_arr;
        loop assigns i;
        loop variant len - i;
     */
    while (i < len)
    {
        if (arr[i] > k)
        {
            //@ assert !(\forall integer i; 0 <= i < (len) ==> (arr)[i] <= (k));
            return false;
        }
        i = i + 1;
    }
    //@ assert (\forall integer i; 0 <= i < (len) ==> (arr)[i] <= (k));
    return true;
}
