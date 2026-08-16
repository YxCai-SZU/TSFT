#include <limits.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result == ((a) - (b) * 2) || \result == 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int ans;
    
    //@ assert b * 2 <= 200;
    //@ assert INT_MIN <= a - b * 2 <= INT_MAX;
    
    ans = a - b * 2;
    
    if (ans > 0) {
        //@ assert ans == ((a) - (b) * 2);
        return ans;
    } else {
        //@ assert ans == ((a) - (b) * 2);
        return 0;
    }
}
