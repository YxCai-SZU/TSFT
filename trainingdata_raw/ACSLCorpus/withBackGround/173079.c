#include <limits.h>

/*@
    predicate in_range(integer a) = -1000 <= a <= 1000;
    
    logic integer sum_val(integer a, integer b) = a + b;
    logic integer diff_val(integer a, integer b) = a - b;
    logic integer prod_val(integer a, integer b) = a * b;
    
    lemma product_bounds: 
        \forall integer a, b; in_range(a) && in_range(b) ==> 
        -1000000 <= prod_val(a, b) <= 1000000;
*/

/*@
    requires in_range(a) && in_range(b);
    ensures \result == sum_val(a, b) || 
            \result == diff_val(a, b) || 
            \result == prod_val(a, b);
    ensures \result >= sum_val(a, b) && 
            \result >= diff_val(a, b) && 
            \result >= prod_val(a, b);
*/
int func(int a, int b) {
    int sum;
    int diff;
    int prod;
    int max_val;
    
    //@ assert in_range(a);
    //@ assert in_range(b);
    
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
    
    //@ assert max_val >= sum_val(a, b);
    //@ assert max_val >= diff_val(a, b);
    //@ assert max_val >= prod_val(a, b);
    
    return max_val;
}
