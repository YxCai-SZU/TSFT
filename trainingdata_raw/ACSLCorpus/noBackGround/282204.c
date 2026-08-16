#include <limits.h>

/*@
    requires (-10 <= (a) <= 10) && (-10 <= (b) <= 10);
    ensures \result == a * b;
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at top of scope
    int ans;
    
    //@ assert -100 <= a * b <= 100;
    
    ans = a * b;
    return ans;
}
