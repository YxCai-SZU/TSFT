#include <limits.h>

/*@
    predicate bounds(int x) = -100 <= x <= 100;
    predicate sum_bounds(int s) = -200 <= s <= 200;
*/

/*@
    requires bounds(A) && bounds(B) && bounds(C) && bounds(D);
    ensures \result == A + B || \result == A + C || \result == A + D ||
            \result == B + C || \result == B + D || \result == C + D;
    assigns \nothing;
*/
int func(int A, int B, int C, int D)
{
    int max_value;
    int AC;
    int AD;
    int BC;
    int BD;
    int CD;

    //@ assert bounds(A);
    //@ assert bounds(B);
    max_value = A + B;

    //@ assert bounds(A);
    //@ assert bounds(C);
    AC = A + C;
    if (AC > max_value) {
        max_value = AC;
    }

    //@ assert bounds(A);
    //@ assert bounds(D);
    AD = A + D;
    if (AD > max_value) {
        max_value = AD;
    }

    //@ assert bounds(B);
    //@ assert bounds(C);
    BC = B + C;
    if (BC > max_value) {
        max_value = BC;
    }

    //@ assert bounds(B);
    //@ assert bounds(D);
    BD = B + D;
    if (BD > max_value) {
        max_value = BD;
    }

    //@ assert bounds(C);
    //@ assert bounds(D);
    CD = C + D;
    if (CD > max_value) {
        max_value = CD;
    }

    return max_value;
}
