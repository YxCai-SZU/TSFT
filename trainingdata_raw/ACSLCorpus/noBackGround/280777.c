#include <stdint.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    ensures \result == ((a) + (b)) || \result == ((a) - (b)) || \result == ((a) * (b));
    ensures \result >= ((a) + (b));
    ensures \result >= ((a) - (b));
    ensures \result >= ((a) * (b));
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b) {
    int64_t sum_val;
    int64_t diff_val;
    int64_t prod_val;
    int64_t max_val;
    
    //@ assert (-100 <= (a) <= 100);
    //@ assert (-100 <= (b) <= 100);
    
    sum_val = a + b;
    diff_val = a - b;
    
    //@ assert -10000 <= a * b <= 10000;
    prod_val = a * b;
    
    max_val = sum_val;
    if (diff_val > max_val) {
        max_val = diff_val;
    }
    if (prod_val > max_val) {
        max_val = prod_val;
    }
    
    //@ assert max_val >= sum_val;
    //@ assert max_val >= diff_val;
    //@ assert max_val >= prod_val;
    
    return max_val;
}
