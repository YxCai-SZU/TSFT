#include <stdbool.h>

/*@
    requires n >= -2147483648 && n <= 2147483647;
    assigns \nothing;
    ensures \result == ((n & 1) == 0);
*/
bool is_even(int n)
{
    bool result;
    
    //@ assert (n & 1) == (n & 1);
    
    result = (n & 1) == 0;
    return result;
}
