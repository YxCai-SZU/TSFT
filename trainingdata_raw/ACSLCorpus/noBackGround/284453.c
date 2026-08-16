#include <limits.h>

/*@
    requires (-1000 <= (a) <= 1000) && (-1000 <= (b) <= 1000);
    ensures \result == ((a) + (b)) || \result == ((a) - (b)) || \result == ((a) * (b));
    ensures \result >= ((a) + (b));
    ensures \result >= ((a) - (b));
    ensures \result >= ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b) {
    int sum;
    int diff;
    int prod;
    int max_val;
    
    //@ assert (-1000 <= (a) <= 1000);
    //@ assert (-1000 <= (b) <= 1000);
    
    sum = a + b;
    diff = a - b;
    
    //@ assert -1000000 <= a * b <= 1000000;
    prod = a * b;
    
    max_val = sum;
    
    if (diff > max_val) {
        max_val = diff;
    }
    
    if (prod > max_val) {
        max_val = prod;
    }
    
    //@ assert max_val == ((a) + (b)) || max_val == ((a) - (b)) || max_val == ((a) * (b));
    //@ assert max_val >= ((a) + (b));
    //@ assert max_val >= ((a) - (b));
    //@ assert max_val >= ((a) * (b));
    
    return max_val;
}
