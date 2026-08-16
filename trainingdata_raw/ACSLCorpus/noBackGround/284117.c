#include <stdbool.h>
#include <stdint.h>

/*@ requires 1 <= n <= 20 && 1 <= d <= 20;
    ensures (n % 2 == 0 ==> \result == 0) && (n % 2 != 0 ==> \result == 1);
 */
int32_t func(uint32_t n, uint32_t d)
{
    int32_t ans;
    //@ assert 1 <= n <= 20;
    
    if (n % 2 == 0) {
        ans = 0;
        //@ assert ans == 0;
    } else {
        ans = 1;
        //@ assert ans == 1;
    }
    
    //@ assert (n % 2 == 0 ==> ans == 0) && (n % 2 != 0 ==> ans == 1);
    return ans;
}
