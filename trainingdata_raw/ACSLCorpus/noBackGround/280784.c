#include <stdbool.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires len > 0;
    assigns \nothing;
    ensures \result <==> ((len) > 0 &&
        \forall integer i; 1 <= i < (len) ==> (arr)[i-1] <= (arr)[i]);
 */
bool is_sorted(const int *arr, int len)
{
    int i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant \forall integer j; 1 <= j < i ==> arr[j-1] <= arr[j];
        loop assigns i;
        loop variant len - i;
     */
    while (i < len)
    {
        //@ assert 1 <= i < len;
        if (arr[i-1] > arr[i])
        {
            return false;
        }
        i++;
    }
    return true;
}
