#include <stdint.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (a) <= 50 && 1 <= (b) <= 50);
    ensures \result <= b;
    ensures \result <= a * n;
    ensures \result >= b || \result == a * n;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t a, uint64_t b)
{
    // Variable declarations at top of scope
    uint64_t result;
    
    // Precondition verification
    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 50;
    //@ assert 1 <= b && b <= 50;
    
    // Overflow safety check
    //@ assert a * n <= 50 * 20;
    
    result = a * n;
    
    if (b < result) {
        result = b;
    }
    
    // Postcondition verification
    //@ assert result <= b;
    //@ assert result <= a * n;
    //@ assert result >= b || result == a * n;
    
    return result;
}
