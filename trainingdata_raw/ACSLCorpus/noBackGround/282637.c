#include <limits.h>

/*@
    requires (2 <= (A) <= 100) && (2 <= (B) <= 100);
    ensures \result == (((A) - 1) * ((B) - 1));
    assigns \nothing;
*/
int func(int A, int B)
{
    // Variable declarations at scope top
    int res;

    //@ assert A > 1 && A <= 100;
    //@ assert B > 1 && B <= 100;
    //@ assert A - 1 >= 1 && A - 1 <= 99;
    //@ assert B - 1 >= 1 && B - 1 <= 99;
    //@ assert (A - 1) * (B - 1) >= 1 * 1;
    //@ assert (A - 1) * (B - 1) <= 99 * 99;

    res = (A - 1) * (B - 1);
    return res;
}
