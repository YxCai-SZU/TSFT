#include <stdint.h>

/*@
    predicate in_range(integer x) = -100 <= x <= 100;

    // Verification properties for postconditions
    predicate cond1(integer a, integer b, integer c, integer r) =
        a == b && a != c ==> r == c;
    predicate cond2(integer a, integer b, integer c, integer r) =
        b == c && a != b ==> r == a;
    predicate cond3(integer a, integer b, integer c, integer r) =
        c == a && b != c ==> r == b;
*/

/*@
    requires in_range(A) && in_range(B) && in_range(C);
    ensures cond1(A, B, C, \result);
    ensures cond2(A, B, C, \result);
    ensures cond3(A, B, C, \result);
*/
int64_t func(int64_t A, int64_t B, int64_t C)
{
    int64_t result;

    //@ assert in_range(A) && in_range(B) && in_range(C);

    if (A == B && A != C) {
        //@ assert A == B && A != C;
        //@ assert A == B;
        //@ assert A != C;
        //@ assert in_range(C);
        result = C;
    } else if (B == C && A != B) {
        //@ assert B == C && A != B;
        //@ assert B == C;
        //@ assert A != B;
        //@ assert in_range(A);
        result = A;
    } else if (C == A && B != C) {
        //@ assert C == A && B != C;
        //@ assert C == A;
        //@ assert B != C;
        //@ assert in_range(B);
        result = B;
    } else {
        if (A == B && B == C) {
            //@ assert A == B && B == C;
        }
        result = 0;
    }

    //@ assert cond1(A, B, C, result);
    //@ assert cond2(A, B, C, result);
    //@ assert cond3(A, B, C, result);
    return result;
}
