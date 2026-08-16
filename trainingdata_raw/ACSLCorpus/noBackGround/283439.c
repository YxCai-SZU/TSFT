/*@
    requires 400 <= X && X <= 1999;
    ensures (400 <= X && X <= 599 ==> \result == 8) &&
            (600 <= X && X <= 799 ==> \result == 7) &&
            (800 <= X && X <= 999 ==> \result == 6) &&
            (1000 <= X && X <= 1199 ==> \result == 5) &&
            (1200 <= X && X <= 1399 ==> \result == 4) &&
            (1400 <= X && X <= 1599 ==> \result == 3) &&
            (1600 <= X && X <= 1799 ==> \result == 2) &&
            (1800 <= X && X <= 1999 ==> \result == 1);
*/
int func(int X)
{
    int ans;

    if (400 <= X && X <= 599) {
        ans = 8;
        //@ assert ans == 8;
    } else if (600 <= X && X <= 799) {
        ans = 7;
        //@ assert ans == 7;
    } else if (800 <= X && X <= 999) {
        ans = 6;
        //@ assert ans == 6;
    } else if (1000 <= X && X <= 1199) {
        ans = 5;
        //@ assert ans == 5;
    } else if (1200 <= X && X <= 1399) {
        ans = 4;
        //@ assert ans == 4;
    } else if (1400 <= X && X <= 1599) {
        ans = 3;
        //@ assert ans == 3;
    } else if (1600 <= X && X <= 1799) {
        ans = 2;
        //@ assert ans == 2;
    } else if (1800 <= X && X <= 1999) {
        ans = 1;
        //@ assert ans == 1;
    } else {
        ans = 0;
    }

    return ans;
}
