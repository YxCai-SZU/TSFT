#include <limits.h>

/*@
    requires 400 <= x <= 1999;
    ensures \result == ((x) <= 599 ? 8 :
        (x) <= 799 ? 7 :
        (x) <= 999 ? 6 :
        (x) <= 1199 ? 5 :
        (x) <= 1399 ? 4 :
        (x) <= 1599 ? 3 :
        (x) <= 1799 ? 2 :
        (x) <= 1999 ? 1 : -1);
    ensures (x <= 599 ==> \result == 8);
    ensures (600 <= x <= 799 ==> \result == 7);
    ensures (800 <= x <= 999 ==> \result == 6);
    ensures (1000 <= x <= 1199 ==> \result == 5);
    ensures (1200 <= x <= 1399 ==> \result == 4);
    ensures (1400 <= x <= 1599 ==> \result == 3);
    ensures (1600 <= x <= 1799 ==> \result == 2);
    ensures (1800 <= x <= 1999 ==> \result == 1);
*/
long func(long x)
{
    long result;
    
    if (x <= 599) {
        result = 8;
        //@ assert result == 8;
    } else if (x <= 799) {
        result = 7;
        //@ assert result == 7;
    } else if (x <= 999) {
        result = 6;
        //@ assert result == 6;
    } else if (x <= 1199) {
        result = 5;
        //@ assert result == 5;
    } else if (x <= 1399) {
        result = 4;
        //@ assert result == 4;
    } else if (x <= 1599) {
        result = 3;
        //@ assert result == 3;
    } else if (x <= 1799) {
        result = 2;
        //@ assert result == 2;
    } else if (x <= 1999) {
        result = 1;
        //@ assert result == 1;
    } else {
        result = -1;
        //@ assert result == -1;
    }
    
    //@ assert (x <= 599 ==> result == 8) || (600 <= x <= 799 ==> result == 7) || (800 <= x <= 999 ==> result == 6) || (1000 <= x <= 1199 ==> result == 5) || (1200 <= x <= 1399 ==> result == 4) || (1400 <= x <= 1599 ==> result == 3) || (1600 <= x <= 1799 ==> result == 2) || (1800 <= x <= 1999 ==> result == 1);
    
    return result;
}

int main(void)
{
    return 0;
}
