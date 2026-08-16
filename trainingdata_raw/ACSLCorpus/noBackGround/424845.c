#include <stdbool.h>

/*@
    requires (1 <= (m) <= 23);
    ensures \result == (48 - (m));
    assigns \nothing;
*/
int func(int m)
{
    int result;

    //@ assert (1 <= (m) <= 23);
    result = 48 - m;
    //@ assert result == (48 - (m));
    
    return result;
}
