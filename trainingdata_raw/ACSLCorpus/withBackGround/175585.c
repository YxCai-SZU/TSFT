#include <stdbool.h>
#include <stddef.h>

/*@
    predicate all_even_divisible_by_3_or_5{L}(size_t *arr, integer len) =
        \forall integer i; 0 <= i < len ==> 
            (arr[i] % 2 == 0 ==> (arr[i] % 3 == 0 || arr[i] % 5 == 0));
    
    predicate exists_even_not_divisible{L}(size_t *arr, integer len) =
        \exists integer i; 0 <= i < len && 
            arr[i] % 2 == 0 && arr[i] % 3 != 0 && arr[i] % 5 != 0;
*/

/*@
    requires 2 <= n;
    requires n == len;
    requires \valid_read(arr + (0 .. len-1));
    assigns \nothing;
    ensures \result == true ==> all_even_divisible_by_3_or_5(arr, len);
    ensures \result == false ==> exists_even_not_divisible(arr, len);
*/
bool func(size_t n, size_t *arr, size_t len)
{
    size_t i = 0;
    size_t m = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant m == 0 ==> all_even_divisible_by_3_or_5(arr, i);
        loop invariant m > 0 ==> exists_even_not_divisible(arr, i);
        loop invariant 0 <= m;
        loop invariant m <= i;
        loop assigns i, m;
        loop variant len - i;
    */
    while (i < len)
    {
        size_t a = arr[i];
        if (a % 2 == 0)
        {
            if (a % 3 != 0 && a % 5 != 0)
            {
                m += 1;
            }
        }
        i += 1;
        //@ assert m <= i;
    }
    return m == 0;
}
