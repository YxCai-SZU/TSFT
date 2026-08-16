#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((len) >= 0);
    ensures \result == (len == count);
    assigns \nothing;
*/
bool contains_exact_count(int *arr, size_t len, size_t count)
{
    bool result;
    
    //@ assert ((len) >= 0);
    
    if (len == count)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    
    return result;
}
