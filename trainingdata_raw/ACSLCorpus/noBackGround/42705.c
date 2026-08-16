#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == a * b || \result == c * d;
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int a, int b, int c, int d) {
    int max_val;
    
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    
    //@ assert a * b >= 1 && a * b <= 10000 * 10000;
    //@ assert c * d >= 1 && c * d <= 10000 * 10000;
    
    if (a * b > c * d) {
        max_val = a * b;
    } else {
        max_val = c * d;
    }
    
    //@ assert max_val == a * b || max_val == c * d;
    //@ assert max_val >= 1;
    
    return max_val;
}
