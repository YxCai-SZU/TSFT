#include <stdbool.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100);
    ensures (a == b && a != c) ==> \result == c;
    ensures (a == c && a != b) ==> \result == b;
    ensures (b == c && a != b) ==> \result == a;
    assigns \nothing;
*/
int func(int a, int b, int c) {
    //@ assert (-100 <= (a) <= 100);
    //@ assert (-100 <= (b) <= 100);
    //@ assert (-100 <= (c) <= 100);
    
    if (a == b) {
        //@ assert a == b;
        return c;
    } else if (a == c) {
        //@ assert a == c;
        return b;
    } else if (b == c) {
        //@ assert b == c;
        return a;
    }
    
    //@ assert -100 <= a <= 100;
    //@ assert -100 <= b <= 100;
    //@ assert -100 <= c <= 100;
    
    return 0;
}
