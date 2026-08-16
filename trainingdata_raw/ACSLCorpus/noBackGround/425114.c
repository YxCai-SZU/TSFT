#include <stdint.h>

/*@
    requires 2 <= A && A <= 100;
    requires 2 <= B && B <= 100;
    ensures \result == ((A) * (B) - (A) - (B) + 1);
    ensures \result > 0;
    assigns \nothing;
*/
uint64_t func(uint64_t A, uint64_t B) {
    // Variable declarations at scope top
    uint64_t result;

    //@ assert (2 <= (A) && (A) <= 100);
    //@ assert (2 <= (B) && (B) <= 100);
    //@ assert A * B <= 100 * 100;
    //@ assert A * B - A >= 0;
    //@ assert A * B - A - B >= -100;
    //@ assert A * B - A - B + 1 >= 1;
    //@ assert A * B - A - B + 1 <= ((100) * (100) - (100) - (100) + 1);

    result = A * B - A - B + 1;
    //@ assert result == ((A) * (B) - (A) - (B) + 1);
    //@ assert result > 0;
    
    return result;
}
