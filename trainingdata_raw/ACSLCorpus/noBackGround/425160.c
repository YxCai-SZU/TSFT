#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result == ((b) >= (a) ? (b) - (a) : 0);
    assigns \nothing;
*/
int func(int a, int b)
{
    int ans;
    
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    if (b >= a) {
        ans = b - a;
    } else {
        ans = 0;
    }
    
    //@ assert ans >= 0;
    //@ assert ans == ((b) >= (a) ? (b) - (a) : 0);
    
    return ans;
}
