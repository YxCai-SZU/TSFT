#include <limits.h>

/*@
    requires (-100 <= (A) <= 100) && (-100 <= (B) <= 100) && (-100 <= (C) <= 100) && (-100 <= (D) <= 100);
    ensures \result == A + C || \result == A + D || \result == B + C || \result == B + D;
    assigns \nothing;
*/
int func(int A, int B, int C, int D)
{
    int max1;
    int max2;
    int res;

    //@ assert (-100 <= (A) <= 100) && (-100 <= (B) <= 100) && (-100 <= (C) <= 100) && (-100 <= (D) <= 100);

    if (A > B) {
        max1 = A;
    } else {
        max1 = B;
    }
    //@ assert max1 == A || max1 == B;

    if (C > D) {
        max2 = C;
    } else {
        max2 = D;
    }
    //@ assert max2 == C || max2 == D;

    //@ assert -200 <= max1 + max2 <= 200;
    res = max1 + max2;

    //@ assert res == A + C || res == A + D || res == B + C || res == B + D;
    return res;
}
