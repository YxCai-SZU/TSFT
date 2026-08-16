#include <stdbool.h>
#include <stddef.h>

/*@
    requires 0 <= len < 0x80000000;
    requires \valid_read(arr + (0 .. len - 1));
    ensures \result == true <==> (\forall integer i; 0 <= i < (len) - 1 ==> (arr)[i] <= (arr)[i + 1]);
    assigns \nothing;
*/
bool is_sorted(const int *arr, size_t len)
{
    // Variable declarations at top of scope
    size_t i = 0;
    bool result = true;

    if (len <= 1)
    {
        return true;
    }

    /*@
        loop invariant 0 <= i <= len - 1;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] <= arr[j + 1];
        loop invariant result == true <==> (\forall integer j; 0 <= j < i ==> arr[j] <= arr[j + 1]);
        loop assigns i, result;
        loop variant len - i;
    */
    while (i < len - 1)
    {
        //@ assert i < len - 1;
        
        if (arr[i] > arr[i + 1])
        {
            result = false;
            break;
        }
        i = i + 1;
    }

    //@ assert result == true <==> (\forall integer i; 0 <= i < (len) - 1 ==> (arr)[i] <= (arr)[i + 1]);
    return result;
}
