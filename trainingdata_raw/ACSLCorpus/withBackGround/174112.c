#include <limits.h>

/*@
    predicate in_range(integer v) = -1000 <= v <= 1000;
    predicate product_in_range(integer p) = -1000000 <= p <= 1000000;
*/

/*@
    requires in_range(A) && in_range(B) && in_range(C) && in_range(D);
    ensures \result == A * B || \result == C * D;
    ensures \result >= A * B && \result >= C * D;
    assigns \nothing;
*/
int func(int A, int B, int C, int D)
{
    // Variable declarations at scope top
    int product1;
    int product2;
    int result;

    // Precondition assertions
    //@ assert in_range(A);
    //@ assert in_range(B);
    //@ assert in_range(C);
    //@ assert in_range(D);

    // Overflow safety assertions
    //@ assert product_in_range(A * B);
    //@ assert product_in_range(C * D);

    product1 = A * B;
    product2 = C * D;

    // Manual max implementation
    if (product1 > product2) {
        result = product1;
        //@ assert result == A * B;
        //@ assert result >= C * D;
    } else {
        result = product2;
        //@ assert result == C * D;
        //@ assert result >= A * B;
    }

    // Final verification
    //@ assert result == A * B || result == C * D;
    //@ assert result >= A * B && result >= C * D;
    return result;
}
