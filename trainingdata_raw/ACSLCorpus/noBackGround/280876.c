#include <limits.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (r) <= 4111);
    ensures \result == ((n) >= 10 ? (r) : (r) + 100 * (10 - (n)));
    assigns \nothing;
*/
int func(int n, int r)
{
    int result;
    
    //@ assert (1 <= (n) <= 100 && 0 <= (r) <= 4111);
    
    if (n >= 10)
    {
        result = r;
    }
    else
    {
        //@ assert n >= 1 && n <= 100;
        result = r + 100 * (10 - n);
    }
    
    return result;
}
