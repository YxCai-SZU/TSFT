#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 20 &&
        1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 2000);
    ensures \result == n * a || \result == b;
    ensures \result <= b;
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t a, int64_t b)
{
    // Variable declarations at scope top
    int64_t min_val;
    
    //@ assert (1 <= (n) && (n) <= 20 &&         1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 2000);
    //@ assert n * a <= 2000;
    
    if (n * a < b) {
        min_val = n * a;
    } else {
        min_val = b;
    }
    
    //@ assert min_val == n * a || min_val == b;
    //@ assert min_val <= b;
    
    return min_val;
}
