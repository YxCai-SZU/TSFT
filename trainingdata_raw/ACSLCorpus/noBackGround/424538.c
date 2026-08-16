#include <stdint.h>

/*@ requires (1 <= (n) <= 100);
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
 */
int32_t func(uint32_t n)
{
    int32_t result;
    
    //@ assert (1 <= (n) <= 100);
    result = (int32_t)((n + 1) / 2);
    
    if (n % 2 == 0) {
        //@ assert result == (((n) + 1) / 2);
        //@ assert result - 1 >= 0;
        return result - 1;
    } else {
        //@ assert result == (((n) + 1) / 2);
        //@ assert result <= n;
        return result;
    }
}
