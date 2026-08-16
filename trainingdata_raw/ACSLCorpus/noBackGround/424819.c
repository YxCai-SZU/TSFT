#include <limits.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100) && (-100 <= (d) <= 100);
    ensures \result == a * c || \result == a * d || \result == b * c || \result == b * d || \result == c * b;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int ac;
    int ad;
    int bc;
    int bd;
    int max_val;

    //@ assert (-100 <= (a) <= 100);
    //@ assert (-100 <= (b) <= 100);
    //@ assert (-100 <= (c) <= 100);
    //@ assert (-100 <= (d) <= 100);
    
    //@ assert (-10000 <= (a * c) <= 10000);
    ac = a * c;
    
    //@ assert (-10000 <= (a * d) <= 10000);
    ad = a * d;
    
    //@ assert (-10000 <= (b * c) <= 10000);
    bc = b * c;
    
    //@ assert (-10000 <= (b * d) <= 10000);
    bd = b * d;
    
    max_val = ac;
    
    if (ad > max_val) {
        max_val = ad;
    }
    if (bc > max_val) {
        max_val = bc;
    }
    if (bd > max_val) {
        max_val = bd;
    }
    
    return max_val;
}
