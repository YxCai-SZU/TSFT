#include <stdint.h>

/*@
    requires (1 <= (a) <= 20 && 1 <= (b) <= 20);
    ensures (a <= 9 && b <= 9) ==> \result == (long long)(a * b);
    ensures (a > 9 || b > 9) ==> \result == -1;
    assigns \nothing;
*/
int64_t func(uint64_t a, uint64_t b)
{
    uint64_t max_value;
    int64_t result;
    
    //@ assert (1 <= (a) <= 20 && 1 <= (b) <= 20);
    
    if (a > b) {
        max_value = a;
    } else {
        max_value = b;
    }
    
    if (max_value <= 9) {
        //@ assert (1 <= (a) <= 9) && (1 <= (b) <= 9);
        //@ assert 1 <= a * b <= 81;
        result = (int64_t)(a * b);
    } else {
        result = -1;
    }
    
    return result;
}
