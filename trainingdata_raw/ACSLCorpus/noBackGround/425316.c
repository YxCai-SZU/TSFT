#include <stddef.h>

/*@ requires ((n) >= 1 && (k) >= 1 && (n) <= 100000 && (k) <= (n));
    ensures \result == n - k + 1;
    assigns \nothing;
*/
size_t func(size_t n, size_t k) {
    size_t result;
    
    //@ assert n - k + 1 <= 100000;
    result = n - k + 1;
    
    //@ assert result == n - k + 1;
    return result;
}
