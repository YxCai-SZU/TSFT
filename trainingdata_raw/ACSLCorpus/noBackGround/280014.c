#include <stdint.h>

/*@
 requires (1 <= (n) <= 1000000000 &&
     1 <= (m) <= 1000000000);
 ensures ((\result) == 0 || (\result) == 1);
 assigns \nothing;
*/
int64_t func(uint64_t n, uint64_t m)
{
    int64_t result;
    
    if (n == m) {
        result = 1;
    } else {
        result = 0;
        //@ assert result == 0 || result == 1;
    }
    
    return result;
}
