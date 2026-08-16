#include <stdint.h>

/*@
    requires (1 <= (a) <= 10);
    ensures \result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    assigns \nothing;
*/
int32_t func(int32_t a)
{
    // Variable declarations at scope top
    int32_t a_pow2;
    int32_t a_pow3;
    int32_t result;

    //@ assert 1 <= a && a <= 10;
    //@ assert 1 <= a * a && a * a <= 100;
    //@ assert 1 <= a * a * a && a * a * a <= 1000;

    a_pow2 = a * a;
    a_pow3 = a * a * a;
    result = a + a_pow2 + a_pow3;

    //@ assert result == a + a_pow2 + a_pow3;
    return result;
}
