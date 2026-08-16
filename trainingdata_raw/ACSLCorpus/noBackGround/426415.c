#include <limits.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    ensures \result == ((a) + (b)) || \result == ((a) - (b)) || \result == ((a) * (b));
    ensures \result >= ((a) + (b));
    ensures \result >= ((a) - (b));
    ensures \result >= ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b) {
    int max_val;
    
    //@ assert (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    max_val = a + b;
    
    if (a - b > max_val) {
        max_val = a - b;
    }
    
    //@ assert -10000 <= a * b <= 10000;
    if (a * b > max_val) {
        max_val = a * b;
    }
    
    //@ assert max_val == a + b || max_val == a - b || max_val == a * b;
    //@ assert max_val >= a + b;
    //@ assert max_val >= a - b;
    //@ assert max_val >= a * b;
    
    return max_val;
}
