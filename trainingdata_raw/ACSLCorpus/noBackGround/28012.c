#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100);
    ensures \result == ((x) * (x));
    assigns \nothing;
*/
int func(int x)
{
    int result;
    
    //@ assert (1 <= (x) <= 100);
    //@ assert ((x) * (x)) <= 10000;
    
    result = x * x;
    
    //@ assert result == ((x) * (x));
    return result;
}
