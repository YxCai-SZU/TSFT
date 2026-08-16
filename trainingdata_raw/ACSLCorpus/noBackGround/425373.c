#include <limits.h>

/*@
    requires ((a) >= 1 && (a) <= 100 && (b) >= 1 && (b) <= 100);
    ensures \result == ((a) * (b) - (a) - (b) + 1);
    assigns \nothing;
*/
int func(int a, int b)
{
    int ans;
    
    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 100;
    //@ assert a * b >= 1 && a * b <= 10000;
    
    ans = a * b - a - b + 1;
    
    //@ assert ans >= -198 && ans <= 10000;
    //@ assert ans == ((a) * (b) - (a) - (b) + 1);
    
    return ans;
}
