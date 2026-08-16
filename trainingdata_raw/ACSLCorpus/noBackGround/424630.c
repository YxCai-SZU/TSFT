#include <stdint.h>

/*@
    requires (1 <= (a) <= 10);
    ensures \result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    assigns \nothing;
*/
int32_t func(int32_t a)
{
    // Variable declarations at scope top
    int32_t a_pow_2;
    int32_t a_pow_3;
    int32_t ans;

    //@ assert (1 <= (a) <= 10);
    //@ assert 1 <= a && a <= 10;

    //@ assert a * a <= 100;
    //@ assert a * a * a >= 1;
    //@ assert a * a * a <= 1000;

    a_pow_2 = a * a;
    a_pow_3 = a * a * a;
    ans = a + a_pow_2 + a_pow_3;

    //@ assert ans == a + a_pow_2 + a_pow_3;
    return ans;
}
