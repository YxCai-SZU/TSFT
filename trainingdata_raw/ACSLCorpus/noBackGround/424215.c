#include <limits.h>

/*@
    requires (400 <= (x) && (x) < 2000);
    ensures (0 <= (\result) && (\result) <= 100);
    assigns \nothing;
*/
int func(int x)
{
    int ans;
    //@ assert (400 <= (x) && (x) < 2000);
    
    if (x < 600) {
        ans = 8;
    } else if (x < 800) {
        ans = 7;
    } else if (x < 1000) {
        ans = 6;
    } else if (x < 1200) {
        ans = 5;
    } else if (x < 1400) {
        ans = 4;
    } else if (x < 1600) {
        ans = 3;
    } else if (x < 1800) {
        ans = 2;
    } else if (x < 2000) {
        ans = 1;
    } else {
        ans = -1;
    }
    
    //@ assert (0 <= (ans) && (ans) <= 100);
    return ans;
}
