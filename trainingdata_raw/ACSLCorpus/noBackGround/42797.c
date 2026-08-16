#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    assigns \nothing;
*/
int32_t a_calc(int32_t a)
{
    // Variable declarations at scope top
    int32_t a_pow2;
    int32_t a_pow3;
    int32_t ans;

    //@ assert (1 <= (a) && (a) <= 10);

    // a * a calculation
    a_pow2 = a * a;
    //@ assert a_pow2 == ((a) * (a));

    // a * a * a calculation
    a_pow3 = a * a * a;
    //@ assert a_pow3 == ((a) * (a) * (a));

    // Final sum
    ans = a + a_pow2 + a_pow3;
    //@ assert ans == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));

    return ans;
}
