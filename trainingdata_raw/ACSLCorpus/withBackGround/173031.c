#include <stdbool.h>
#include <stddef.h>

/*@ predicate sorted(int *arr, integer len) =
      \forall integer i; 0 <= i < len - 1 ==> arr[i] <= arr[i + 1];
*/

/*@
  requires \valid_read(arr + (0 .. len-1));
  requires len <= 0x100000000;
  assigns \nothing;
  ensures \result <==> sorted(arr, len);
*/
bool is_sorted(const int *arr, size_t len)
{
    size_t idx = 0;
    
    if (len < 2)
    {
        //@ assert sorted(arr, len);
        return true;
    }
    
    /*@
      loop invariant 0 <= idx <= len - 1;
      loop invariant \forall integer i; 0 <= i < idx ==> arr[i] <= arr[i + 1];
      loop assigns idx;
      loop variant len - idx;
    */
    while (idx < len - 1)
    {
        //@ assert 0 <= idx < len - 1;
        if (arr[idx] > arr[idx + 1])
        {
            //@ assert !sorted(arr, len);
            return false;
        }
        idx = idx + 1;
    }
    
    //@ assert sorted(arr, len);
    return true;
}
