#include <limits.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    ensures \result >= 1 && \result <= 3;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans = 0;
    
    //@ assert (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    
    if (a == b && b == c) {
        ans = 3;
    } else if (a != b && b != c && c != a) {
        ans = 1;
    } else {
        ans = 2;
    }
    
    //@ assert ans == 1 || ans == 2 || ans == 3;
    //@ assert ans >= 1 && ans <= 3;
    
    return ans;
}
