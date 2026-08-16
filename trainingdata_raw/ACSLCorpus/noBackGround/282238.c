#include <stdint.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (a) <= 50 && 1 <= (b) <= 50);
    ensures \result == n * a || \result == b;
    ensures \result <= n * a;
    ensures \result <= b;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t a, uint64_t b)
{
    // Variable declarations at top of scope
    uint64_t n_times_a;
    uint64_t min_value;

    //@ assert a <= 50;
    //@ assert b <= 50;
    //@ assert n <= 20;
    
    // Ensure no overflow in n * a
    //@ assert n * a <= 1000;
    
    n_times_a = n * a;
    
    if (n_times_a < b) {
        min_value = n_times_a;
    } else {
        min_value = b;
    }
    
    //@ assert min_value == n_times_a || min_value == b;
    //@ assert min_value <= n_times_a;
    //@ assert min_value <= b;
    
    return min_value;
}
