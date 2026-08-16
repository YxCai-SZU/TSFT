#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_count(integer c) = 0 <= c < 0x80000000;
    
    logic integer vector_length{L}(int *arr, integer len) = len;
*/

/*@
    requires valid_count(count);
    ensures \result == (len == count);
    assigns \nothing;
*/
bool contains_exact_count(int *arr, size_t len, size_t count)
{
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant valid_count(count);
        loop assigns i;
        loop variant len - i;
    */
    while (i < len)
    {
        i++;
    }
    
    //@ assert i == len;
    
    if (i != count)
    {
        return false;
    }
    return true;
}
