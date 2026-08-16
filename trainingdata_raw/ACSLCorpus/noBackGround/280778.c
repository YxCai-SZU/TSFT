#include <stdint.h>

/*@ requires 1 <= n <= 10000;
    ensures \result >= 0;
    ensures \result < 1000;
    ensures \result == 1000 - (n % 1000) || \result == 0;
    assigns \nothing;
 */
int32_t func(int32_t n)
{
    uint32_t n_unsigned;
    uint32_t res;
    int32_t ans;
    
    //@ assert 1 <= n <= 10000;
    
    if (n < 0) {
        n_unsigned = (uint32_t)(n + 1);
    } else {
        n_unsigned = (uint32_t)n;
    }
    
    //@ assert n_unsigned >= 0;
    
    if (n_unsigned % 1000 != 0) {
        res = 1000 - n_unsigned % 1000;
    } else {
        res = 0;
    }
    
    //@ assert res >= 0;
    //@ assert res < 1000;
    //@ assert res == 1000 - (n_unsigned % 1000) || res == 0;
    
    if (n < 0) {
        ans = -(int32_t)res;
    } else {
        ans = (int32_t)res;
    }
    
    //@ assert ans >= 0;
    //@ assert ans < 1000;
    //@ assert ans == 1000 - (n % 1000) || ans == 0;
    
    return ans;
}

int main(void)
{
    return 0;
}
