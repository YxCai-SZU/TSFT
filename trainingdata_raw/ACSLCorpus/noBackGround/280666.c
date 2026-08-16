#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result <= a - 1;
    ensures \result == a - b || \result == 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int ans;
    
    //@ assert a > 0 && b > 0;
    //@ assert a >= b || a - b < 0;
    //@ assert a - b >= 0 || a - b < 0;
    
    ans = a - b;
    if (ans > 0) {
        return ans;
    } else {
        return 0;
    }
}
