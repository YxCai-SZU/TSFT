#include <limits.h>

/*@
    requires (400 <= (x) && (x) <= 1999);
    ensures \result == 8 <==> (400 <= (x) && (x) <= 599);
    ensures \result == 7 <==> (600 <= (x) && (x) <= 799);
    ensures \result == 6 <==> (800 <= (x) && (x) <= 999);
    ensures \result == 5 <==> (1000 <= (x) && (x) <= 1199);
    ensures \result == 4 <==> (1200 <= (x) && (x) <= 1399);
    ensures \result == 3 <==> (1400 <= (x) && (x) <= 1599);
    ensures \result == 2 <==> (1600 <= (x) && (x) <= 1799);
    ensures \result == 1 <==> (1800 <= (x) && (x) <= 1999);
    ensures \result == -1 <==> !(400 <= (x) && (x) <= 1999);
*/
int func(int x)
{
    int ans;
    
    if (400 <= x && x <= 599) {
        ans = 8;
        //@ assert ans == 8;
    } else if (600 <= x && x <= 799) {
        ans = 7;
        //@ assert ans == 7;
    } else if (800 <= x && x <= 999) {
        ans = 6;
        //@ assert ans == 6;
    } else if (1000 <= x && x <= 1199) {
        ans = 5;
        //@ assert ans == 5;
    } else if (1200 <= x && x <= 1399) {
        ans = 4;
        //@ assert ans == 4;
    } else if (1400 <= x && x <= 1599) {
        ans = 3;
        //@ assert ans == 3;
    } else if (1600 <= x && x <= 1799) {
        ans = 2;
        //@ assert ans == 2;
    } else if (1800 <= x && x <= 1999) {
        ans = 1;
        //@ assert ans == 1;
    } else {
        ans = -1;
        //@ assert ans == -1;
    }
    
    //@ assert (400 <= x && x <= 599 ==> ans == 8);
    //@ assert (600 <= x && x <= 799 ==> ans == 7);
    //@ assert (800 <= x && x <= 999 ==> ans == 6);
    //@ assert (1000 <= x && x <= 1199 ==> ans == 5);
    //@ assert (1200 <= x && x <= 1399 ==> ans == 4);
    //@ assert (1400 <= x && x <= 1599 ==> ans == 3);
    //@ assert (1600 <= x && x <= 1799 ==> ans == 2);
    //@ assert (1800 <= x && x <= 1999 ==> ans == 1);
    //@ assert (x < 400 || x > 1999 ==> ans == -1);
    
    return ans;
}
