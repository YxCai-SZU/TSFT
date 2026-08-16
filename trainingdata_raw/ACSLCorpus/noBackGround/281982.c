#include <stdint.h>

/*@
    requires 1 <= a && a <= 10;
    ensures \result == ((a) + (a) * (a) + (a) * (a) * (a));
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    // Variable declarations at scope top
    int64_t ans;

    //@ assert (1 <= (a) && (a) <= 10);
    //@ assert 1 <= a * a && a * a <= 100;
    //@ assert 1 <= a * a * a && a * a * a <= 1000;
    //@ assert 1 <= a + a * a && a + a * a <= 110;
    //@ assert 1 <= a + a * a + a * a * a && a + a * a + a * a * a <= 1110;

    ans = a + a * a + a * a * a;
    //@ assert ans == ((a) + (a) * (a) + (a) * (a) * (a));
    return ans;
}
