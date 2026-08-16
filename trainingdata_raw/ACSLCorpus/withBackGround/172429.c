#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 10000;
    predicate b_in_range(integer b) = 1 <= b <= 10000;
    predicate c_in_range(integer c) = 1 <= c <= 10000;
    predicate d_in_range(integer d) = 1 <= d <= 10000;
    
    logic integer product(integer c, integer d) = c * d;
    
    lemma product_in_range:
        \forall integer c, d;
        c_in_range(c) && d_in_range(d) ==> 1 <= product(c, d) <= 100000000;
*/

/*@
    requires a_in_range(a) && b_in_range(b) && c_in_range(c) && d_in_range(d);
    ensures \result == (a >= c * d) || (b >= d) || (a + b >= c * d + d);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    // Variable declarations at scope top
    unsigned int min_val;
    unsigned int min_val2;
    unsigned int min_val3;
    unsigned int max_val;
    bool condition_met;
    
    //@ assert 1 <= c <= 10000;
    //@ assert 1 <= d <= 10000;
    //@ assert c * d <= 10000 * 10000;
    
    // Calculate min_val
    if (a < b) {
        min_val = a;
    } else {
        min_val = b;
    }
    
    // Calculate min_val2
    if (min_val < c * d) {
        min_val2 = min_val;
    } else {
        min_val2 = c * d;
    }
    
    // Calculate min_val3
    if (min_val2 < d) {
        min_val3 = min_val2;
    } else {
        min_val3 = d;
    }
    
    // Calculate max_val
    if (a + b > c * d + d) {
        max_val = a + b;
    } else {
        max_val = c * d + d;
    }
    
    //@ assert min_val3 == d || min_val3 < d;
    
    // Check condition
    if (a >= c * d || b >= d || a + b >= c * d + d) {
        condition_met = true;
    } else {
        condition_met = (min_val3 == d);
    }
    
    //@ assert condition_met == (a >= c * d) || (b >= d) || (a + b >= c * d + d);
    return condition_met;
}
