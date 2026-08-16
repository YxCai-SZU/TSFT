#include <limits.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    requires (1 <= (d) <= 100);
    ensures \result >= 0;
    ensures \result <= a + c + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d) {
    int min_b;
    int min_a;
    int res;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    //@ assert (1 <= (d) <= 100);
    
    if (b < c + d) {
        min_b = b;
    } else {
        min_b = c + d;
    }
    //@ assert min_b == (((b) < (c + d)) ? (b) : (c + d));
    
    if (a < c + d) {
        min_a = a;
    } else {
        min_a = c + d;
    }
    //@ assert min_a == (((a) < (c + d)) ? (a) : (c + d));
    
    if (min_b > min_a) {
        res = min_b - min_a;
    } else {
        res = min_a - min_b;
    }
    //@ assert res == (((min_b) > (min_a)) ? (min_b) - (min_a) : (min_a) - (min_b));
    
    //@ assert res >= 0;
    //@ assert res <= a + c + d;
    
    return res;
}
