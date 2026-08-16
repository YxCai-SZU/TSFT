#include <limits.h>

/*@ requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    ensures \result == ((a) + (b)) || 
            \result == ((a) - (b)) || 
            \result == ((a) * (b));
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

    //@ assert (-100 <= (a) <= 100);
    //@ assert (-100 <= (b) <= 100);
    
    sum = a + b;
    diff = a - b;
    
    //@ assert -10000 <= a * b <= 10000;
    prod = a * b;
    
    max_val = sum;
    
    if (diff > max_val) {
        max_val = diff;
    }
    
    if (prod > max_val) {
        max_val = prod;
    }
    
    //@ assert max_val == sum || max_val == diff || max_val == prod;
    //@ assert max_val >= sum;
    //@ assert max_val >= diff;
    //@ assert max_val >= prod;
    
    return max_val;
}
