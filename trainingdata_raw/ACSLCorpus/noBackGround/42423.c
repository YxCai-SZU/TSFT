#include <limits.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    ensures ((\result) >= 0 && ((\result) == (a) * (b) || (\result) == (c)));
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans;
    
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert (1 <= (c) && (c) <= 100);
    //@ assert ((a) * (b) <= 100 * 100);
    
    if (a * b > c) {
        ans = a * b;
    } else {
        ans = c;
    }
    
    //@ assert ((ans) >= 0 && ((ans) == (a) * (b) || (ans) == (c)));
    return ans;
}
