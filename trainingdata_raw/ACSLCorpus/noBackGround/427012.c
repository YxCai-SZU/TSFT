#include <limits.h>

/*@
    requires 400 <= x < 2000;
    ensures (400 <= x < 600 ==> \result == 8) &&
            (600 <= x < 800 ==> \result == 7) &&
            (800 <= x < 1000 ==> \result == 6) &&
            (1000 <= x < 1200 ==> \result == 5) &&
            (1200 <= x < 1400 ==> \result == 4) &&
            (1400 <= x < 1600 ==> \result == 3) &&
            (1600 <= x < 1800 ==> \result == 2) &&
            (1800 <= x < 2000 ==> \result == 1);
    assigns \nothing;
*/
int func(int x)
{
    int ans;
    
    //@ assert 400 <= x < 2000;
    
    if (400 <= x && x < 600) {
        ans = 8;
        //@ assert ans == 8;
    } else if (600 <= x && x < 800) {
        ans = 7;
        //@ assert ans == 7;
    } else if (800 <= x && x < 1000) {
        ans = 6;
        //@ assert ans == 6;
    } else if (1000 <= x && x < 1200) {
        ans = 5;
        //@ assert ans == 5;
    } else if (1200 <= x && x < 1400) {
        ans = 4;
        //@ assert ans == 4;
    } else if (1400 <= x && x < 1600) {
        ans = 3;
        //@ assert ans == 3;
    } else if (1600 <= x && x < 1800) {
        ans = 2;
        //@ assert ans == 2;
    } else if (1800 <= x && x < 2000) {
        ans = 1;
        //@ assert ans == 1;
    } else {
        ans = 0;
    }
    
    //@ assert (400 <= x < 600 ==> ans == 8) && (600 <= x < 800 ==> ans == 7) && (800 <= x < 1000 ==> ans == 6) && (1000 <= x < 1200 ==> ans == 5) && (1200 <= x < 1400 ==> ans == 4) && (1400 <= x < 1600 ==> ans == 3) && (1600 <= x < 1800 ==> ans == 2) && (1800 <= x < 2000 ==> ans == 1);
    
    return ans;
}
