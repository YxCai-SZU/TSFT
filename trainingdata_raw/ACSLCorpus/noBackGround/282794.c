#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    assigns \nothing;
    ensures \result == true ==> (\exists integer i; 0 <= i < len && arr[i] == target);
    ensures \result == false ==> (\forall integer i; 0 <= i < len ==> arr[i] != target);
 */
bool search(int *arr, size_t len, int target)
{
    size_t i = 0;
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] != target;
        loop assigns i;
        loop variant len - i;
     */
    while (i < len)
    {
        if (arr[i] == target)
        {
            //@ assert 0 <= i < len;
            //@ assert arr[i] == target;
            return true;
        }
        i++;
    }
    return false;
}
