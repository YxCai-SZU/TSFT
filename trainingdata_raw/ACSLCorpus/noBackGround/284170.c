#include <stdint.h>

/*@
    requires 1 <= x <= 100000;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> ((x / 100) % 5 != 0 && (x / 100) % 5 != 1);
    ensures \result == 0 ==> ((x / 100) % 5 == 0 || (x / 100) % 5 == 1);
    assigns \nothing;
*/
int32_t func(uint32_t x)
{
    // Variable declarations at scope top
    uint32_t h;
    int32_t ans;

    h = x / 100;
    ans = 0;

    //@ assert h == x / 100;

    if (h % 5 != 0 && h % 5 != 1) {
        ans = 1;
    }

    // Verification assertions
    //@ assert ans == 1 || ans == 0;

    /*@
        assert ans == 1 ==> (h % 5 != 0 && h % 5 != 1);
    */

    /*@
        assert ans == 0 ==> (h % 5 == 0 || h % 5 == 1);
    */

    return ans;
}
