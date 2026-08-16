#include <limits.h>

/*@
    requires 2 <= a <= 100;
    requires 2 <= b <= 100;
    ensures \result == a * b - (a + b - 1);
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at top of scope
    int ans;

    //@ assert 2 <= a;
    //@ assert a <= 100;
    //@ assert 2 <= b;
    //@ assert b <= 100;
    
    //@ assert a * b <= 100 * 100;
    //@ assert a + b - 1 <= 100 + 100 - 1;
    
    ans = a * b - (a + b - 1);
    
    //@ assert ans == a * b - (a + b - 1);
    //@ assert ans <= 100 * 100 - (100 + 100 - 1);
    
    return ans;
}
