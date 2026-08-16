#include <stdint.h>

/*@
    requires 1 <= a <= 10;
    ensures \result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    // Variable declarations at scope top
    int64_t a_pow2;
    int64_t a_pow3;
    int64_t ans;

    //@ assert (1 <= (a) <= 10);
    //@ assert 1 <= ((a) * (a)) && ((a) * (a)) <= 100;
    //@ assert 1 <= ((a) * (a) * (a)) && ((a) * (a) * (a)) <= 1000;
    //@ assert 1 <= a + ((a) * (a)) && a + ((a) * (a)) <= 110;
    //@ assert 1 <= ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a)))) && ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a)))) <= 1110;

    a_pow2 = a * a;
    a_pow3 = a * a * a;
    ans = a + a_pow2 + a_pow3;

    //@ assert ans == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    return ans;
}
