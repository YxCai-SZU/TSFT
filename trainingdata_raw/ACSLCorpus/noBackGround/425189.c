#include <limits.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == a * b;
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    //@ assert 1 * 1 <= INT_MAX;
    //@ assert 100 * 100 <= INT_MAX;
    //@ assert a * b <= INT_MAX;
    
    return a * b;
}
