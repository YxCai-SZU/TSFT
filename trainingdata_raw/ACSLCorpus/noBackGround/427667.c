#include <stdint.h>

/*@
    requires (1 <= (n) <= 100000 && 0 <= (k) <= (n));
    ensures \result == ((n) > (k) ? (n) - (k) : 0);
    ensures \result == n - k || \result == 0;
*/
int64_t func(int64_t n, int64_t k)
{
    int64_t result = 0;
    
    //@ assert result == 0;
    
    if (n > k) {
        result = n - k;
        //@ assert result == n - k;
    }
    
    //@ assert result == n - k || result == 0;
    return result;
}
