#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires ((len) >= 3 &&
        \forall size_t i; 0 <= i < (len) ==> 0 <= (arr)[i] <= 100);
    ensures \result == (arr[0] < arr[1] && arr[1] < arr[2]);
*/
bool func(int *arr, size_t len)
{
    //@ assert len >= 3;
    
    if (arr[0] < arr[1] && arr[1] < arr[2])
    {
        //@ assert arr[0] < arr[1] && arr[1] < arr[2];
        return true;
    }
    else
    {
        //@ assert !(arr[0] < arr[1] && arr[1] < arr[2]);
        return false;
    }
}
