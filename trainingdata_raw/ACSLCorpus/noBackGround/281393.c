#include <limits.h>

/*@
    requires (1 <= (A) && (A) <= 10000 &&
        1 <= (B) && (B) <= 10000 &&
        1 <= (C) && (C) <= 10000 &&
        1 <= (D) && (D) <= 10000);
    ensures \result >= 0;
    ensures \result <= A + B + C + D;
    assigns \nothing;
*/
long func(long A, long B, long C, long D) {
    long res;
    long ans;
    long tmp;

    // First conditional block
    if (A < B) {
        ans = B - A;
        //@ assert ans >= 0;
        tmp = ans + C;
    } else {
        ans = A - B;
        //@ assert ans >= 0;
        tmp = ans + C;
    }
    res = tmp;

    // Second conditional block
    if (D < res) {
        res = D;
    }

    // Final verification assertion
    //@ assert res <= A + B + C + D;
    return res;
}
