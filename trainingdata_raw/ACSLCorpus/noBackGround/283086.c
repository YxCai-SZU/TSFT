#include <stdint.h>

/*@
    requires (3 <= (N) <= 100);
    assigns \nothing;
    ensures \result == (180 * ((N) - 2));
*/
int64_t func(uint64_t N)
{
    int64_t result;
    
    //@ assert 180 * ((int64_t)N - 2) == 180 * ((int64_t)N - 2);
    //@ assert 180 * ((int64_t)N - 2) >= 0;
    //@ assert 180 * ((int64_t)N - 2) <= 180 * 98;
    
    result = 180 * ((int64_t)N - 2);
    return result;
}
