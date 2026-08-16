#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(size_t n)
{
    int result;
    
    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert ((((n) + 1) / 2) * 100 / (n)) >= 0;
    
    result = ((n + 1) / 2) * 100 / n;
    
    //@ assert result >= 0;
    
    return result;
}
