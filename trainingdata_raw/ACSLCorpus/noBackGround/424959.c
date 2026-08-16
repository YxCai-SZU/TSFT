#include <stdbool.h>
#include <stddef.h>

/*@
    requires length <= 0x7FFFFFFF;
    ensures \result == (length % 2 == 0);
    assigns \nothing;
*/
bool is_even(size_t length)
{
    bool result;
    
    //@ assert length <= 0x7FFFFFFF;
    
    //@ assert length % 2 == 0 || length % 2 == 1;
    
    result = (length % 2 == 0);
    
    //@ assert result == (length % 2 == 0);
    
    return result;
}
