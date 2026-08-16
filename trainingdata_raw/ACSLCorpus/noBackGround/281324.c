#include <limits.h>

/*@
    requires (400 <= (x) && (x) < 2000);
    ensures ((\result) >= 1 && (\result) <= 8 &&
        ((\result) == 8 ==> (x) >= 2000) &&
        ((\result) == 7 ==> (x) >= 1800) &&
        ((\result) == 6 ==> (x) >= 1600) &&
        ((\result) == 5 ==> (x) >= 1400) &&
        ((\result) == 4 ==> (x) >= 1200) &&
        ((\result) == 3 ==> (x) >= 1000) &&
        ((\result) == 2 ==> (x) >= 800) &&
        ((\result) == 1 ==> (x) >= 400));
    assigns \nothing;
*/
int func(int x)
{
    int ans;
    
    //@ assert (400 <= (x) && (x) < 2000);
    
    if (x >= 2000) {
        ans = 8;
    } else if (x >= 1800) {
        ans = 7;
    } else if (x >= 1600) {
        ans = 6;
    } else if (x >= 1400) {
        ans = 5;
    } else if (x >= 1200) {
        ans = 4;
    } else if (x >= 1000) {
        ans = 3;
    } else if (x >= 800) {
        ans = 2;
    } else {
        ans = 1;
    }
    
    //@ assert ans >= 1 && ans <= 8;
    //@ assert (ans == 8 ==> x >= 2000);
    //@ assert (ans == 7 ==> x >= 1800);
    //@ assert (ans == 6 ==> x >= 1600);
    //@ assert (ans == 5 ==> x >= 1400);
    //@ assert (ans == 4 ==> x >= 1200);
    //@ assert (ans == 3 ==> x >= 1000);
    //@ assert (ans == 2 ==> x >= 800);
    //@ assert (ans == 1 ==> x >= 400);
    
    return ans;
}
