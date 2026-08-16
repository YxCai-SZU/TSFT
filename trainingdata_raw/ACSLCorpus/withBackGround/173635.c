#include <stdbool.h>
#include <stddef.h>

/*@
    predicate is_sorted_slice(unsigned int *arr, integer len) =
        len >= 3 ==> arr[0] < arr[1] && arr[1] < arr[2];
 */

/*@
    requires \valid_read(v + (0 .. 2));
    requires len >= 3;
    ensures \result == (v[0] < v[1] && v[1] < v[2]);
    assigns \nothing;
 */
bool func(unsigned int *v, size_t len)
{
    bool result;

    //@ assert len >= 3;
    if (len < 3)
    {
        result = false;
        return result;
    }
    if (v[0] < v[1] && v[1] < v[2])
    {
        result = true;
        return result;
    }
    result = false;
    //@ assert result == false;
    return result;
}
