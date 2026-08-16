#include <stdbool.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == r * 6;
    assigns \nothing;
*/
int func(int r)
{
    int pi;
    int result;
    
    pi = 3;
    
    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert pi == 3;
    //@ assert ((r) * 2 * (pi)) == r * 6;
    
    result = r * 2 * pi;
    return result;
}
