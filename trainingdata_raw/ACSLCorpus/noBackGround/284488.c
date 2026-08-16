#include <stdint.h>

/*@
    requires (1 <= (a) <= 20 && 1 <= (b) <= 20);
    ensures (a <= 9 && b <= 9) ==> \result == (long long)(a * b);
    ensures (a > 9 || b > 9) ==> \result == -1;
    assigns \nothing;
*/
int64_t func(uint64_t a, uint64_t b)
{
    int64_t result;
    
    if (a > 9 || b > 9) {
        result = -1;
        return result;
    }
    
    //@ assert 1 <= a && a <= 9;
    //@ assert 1 <= b && b <= 9;
    //@ assert a * b <= 81;
    
    result = (int64_t)(a * b);
    return result;
}
