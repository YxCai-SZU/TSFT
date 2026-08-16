#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (m) && (m) <= 100);
    ensures \result >= 0;
    ensures \result == n - 2 * m || \result == 0;
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t m)
{
    int64_t result;
    
    //@ assert (1 <= (n) && (n) <= 100 &&         1 <= (m) && (m) <= 100);
    result = n - 2 * m;
    
    //@ assert result == ((n) - 2 * (m));
    if (result < 0) {
        //@ assert ((n) - 2 * (m)) < 0;
        result = 0;
    }
    
    //@ assert result >= 0;
    return result;
}
