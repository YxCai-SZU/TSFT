#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_array(unsigned long long *arr, integer len) =
        len == 5 &&
        \forall integer i; 0 <= i < len ==> arr[i] <= 123;

    predicate result_condition(unsigned long long *arr, unsigned long long k) =
        arr[4] >= k;
*/

/*@
    requires \valid(a + (0 .. 4));
    requires valid_array(a, 5);
    requires k <= 123;
    ensures \result == (a[4] >= k);
    assigns \nothing;
*/
bool func(unsigned long long *a, unsigned long long k)
{
    bool result;
    
    //@ assert valid_array(a, 5);
    //@ assert a[4] <= 123;
    result = a[4] >= k;
    
    return result;
}
