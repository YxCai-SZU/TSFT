/*@
    requires 400 <= n && n <= 1999;
    ensures \result == ((n) <= 599 ? 8 :
        (n) <= 799 ? 7 :
        (n) <= 999 ? 6 :
        (n) <= 1199 ? 5 :
        (n) <= 1399 ? 4 :
        (n) <= 1599 ? 3 :
        (n) <= 1799 ? 2 :
        (n) <= 1999 ? 1 : 8);
    ensures (n <= 599 ==> \result == 8);
    ensures (600 <= n && n <= 799 ==> \result == 7);
    ensures (800 <= n && n <= 999 ==> \result == 6);
    ensures (1000 <= n && n <= 1199 ==> \result == 5);
    ensures (1200 <= n && n <= 1399 ==> \result == 4);
    ensures (1400 <= n && n <= 1599 ==> \result == 3);
    ensures (1600 <= n && n <= 1799 ==> \result == 2);
    ensures (1800 <= n && n <= 1999 ==> \result == 1);
*/
int func(int n)
{
    int result;
    
    //@ assert (400 <= (n) && (n) <= 1999);
    
    if (n <= 599) {
        //@ assert n <= 599;
        result = 8;
    } else if (n <= 799) {
        //@ assert 600 <= n && n <= 799;
        result = 7;
    } else if (n <= 999) {
        //@ assert 800 <= n && n <= 999;
        result = 6;
    } else if (n <= 1199) {
        //@ assert 1000 <= n && n <= 1199;
        result = 5;
    } else if (n <= 1399) {
        //@ assert 1200 <= n && n <= 1399;
        result = 4;
    } else if (n <= 1599) {
        //@ assert 1400 <= n && n <= 1599;
        result = 3;
    } else if (n <= 1799) {
        //@ assert 1600 <= n && n <= 1799;
        result = 2;
    } else {
        //@ assert 1800 <= n && n <= 1999;
        result = 1;
    }
    
    return result;
}
