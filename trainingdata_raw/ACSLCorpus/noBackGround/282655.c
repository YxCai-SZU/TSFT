#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100);
    ensures \result == 1;
    assigns \nothing;
*/
int func(int x)
{
    int result = 1;
    
    //@ assert result == 1;
    
    return result;
}
