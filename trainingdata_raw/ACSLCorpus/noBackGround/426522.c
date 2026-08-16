#include <limits.h>

/*@
    requires (2 <= (A) <= 100) && (2 <= (B) <= 100);
    ensures \result == (((A) - 1) * ((B) - 1));
    assigns \nothing;
*/
int func(int A, int B) {
    // Variable declarations at scope top
    int ans;

    //@ assert A - 1 >= 1;
    //@ assert B - 1 >= 1;
    //@ assert (A - 1) * (B - 1) <= 9801;

    ans = (A - 1) * (B - 1);
    return ans;
}
