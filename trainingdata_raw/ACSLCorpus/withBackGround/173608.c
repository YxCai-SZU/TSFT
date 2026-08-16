#include <stdbool.h>
#include <stdint.h>

/*@
    predicate valid_array(int32_t *arr, integer len) =
        len == 5 &&
        \forall integer i; 0 <= i < len ==> arr[i] == i * 2;
*/

/*@
    requires \valid(a + (0 .. 4));
    requires valid_array(a, 5);
    ensures \result == true;
*/
bool func(int32_t *a)
{
    //@ assert valid_array(a, 5);
    return true;
}
