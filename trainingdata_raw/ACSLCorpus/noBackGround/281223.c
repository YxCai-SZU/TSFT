#include <limits.h>

/*@
    requires (1 <= (a) <= 3 && 1 <= (b) <= 3);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert (1 <= (a) <= 3 && 1 <= (b) <= 3);
    
    int ans = a * b;
    
    //@ assert ans == ((a) * (b));
    return ans;
}
