#include <limits.h>

/*@
    requires -1000 <= a <= 1000;
    requires -1000 <= b <= 1000;
    ensures \result == a + b || \result == a - b || \result == a * b;
    ensures \result >= a + b;
    ensures \result >= a - b;
    ensures \result >= a * b;
    assigns \nothing;
*/
int func(int a, int b)
{
    int sum;
    int diff;
    int prod;
    int max_val;
    
    sum = a + b;
    diff = a - b;
    prod = a * b;
    
    max_val = sum;
    if (diff > max_val) {
        max_val = diff;
    }
    if (prod > max_val) {
        max_val = prod;
    }
    
    //@ assert max_val == sum || max_val == diff || max_val == prod;
    
    return max_val;
}
