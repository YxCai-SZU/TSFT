#include <stdint.h>

/*@ requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) + (a) * (a) + (a) * (a) * (a));
 */
int64_t func(int64_t a)
{
    //@ assert (1 <= (a) && (a) <= 10);
    int64_t a_pow_2;
    int64_t a_pow_3;
    int64_t ans;
    
    //@ assert (1 <= (a * a) && (a * a) <= 100);
    a_pow_2 = a * a;
    
    //@ assert (1 <= (a * a * a) && (a * a * a) <= 1000);
    a_pow_3 = a * a * a;
    
    //@ assert (1 <= (a + a_pow_2) && (a + a_pow_2) <= 110);
    ans = a + a_pow_2 + a_pow_3;
    
    //@ assert (2 <= (ans) && (ans) <= 1110);
    //@ assert ans == ((a) + (a) * (a) + (a) * (a) * (a));
    return ans;
}
