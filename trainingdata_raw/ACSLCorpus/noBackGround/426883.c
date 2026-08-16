#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= ((a) * (b)) && \result >= ((c) * (d));
    assigns \nothing;
*/
int func(int a, int b, int c, int d) {
    int x;
    int y;
    int max_val;
    
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert ((a) * (b)) <= 100000000;
    x = a * b;
    
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    //@ assert ((c) * (d)) <= 100000000;
    y = c * d;
    
    if (x > y) {
        max_val = x;
    } else {
        max_val = y;
    }
    
    //@ assert max_val == ((a) * (b)) || max_val == ((c) * (d));
    //@ assert max_val >= ((a) * (b)) && max_val >= ((c) * (d));
    
    return max_val;
}
