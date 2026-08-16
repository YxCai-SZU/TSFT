#include <limits.h>

/*@
    requires (-1000 <= (a) <= 1000) && (-1000 <= (b) <= 1000) && (-1000 <= (c) <= 1000) && (-1000 <= (d) <= 1000);
    ensures \result == ((a) * (c)) || \result == ((a) * (d)) || 
            \result == ((b) * (c)) || \result == ((b) * (d));
    ensures \result >= ((a) * (c)) && \result >= ((a) * (d)) &&
            \result >= ((b) * (c)) && \result >= ((b) * (d));
*/
int func(int a, int b, int c, int d) {
    int ac;
    int ad;
    int bc;
    int bd;
    int max_val;
    
    //@ assert -1000000 <= a * c <= 1000000;
    ac = a * c;
    
    //@ assert -1000000 <= a * d <= 1000000;
    ad = a * d;
    
    //@ assert -1000000 <= b * c <= 1000000;
    bc = b * c;
    
    //@ assert -1000000 <= b * d <= 1000000;
    bd = b * d;
    
    max_val = ac;
    
    if (ad > max_val) {
        //@ assert max_val == ((a) * (c));
        max_val = ad;
    }
    
    if (bc > max_val) {
        //@ assert max_val >= ((a) * (c)) && max_val >= ((a) * (d));
        max_val = bc;
    }
    
    if (bd > max_val) {
        //@ assert max_val >= ((a) * (c)) && max_val >= ((a) * (d)) && max_val >= ((b) * (c));
        max_val = bd;
    }
    
    return max_val;
}
