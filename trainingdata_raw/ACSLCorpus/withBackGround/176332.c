#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer sumAB(integer a, integer b) = a + b;
    logic integer sumBC(integer b, integer c) = b + c;
    logic integer sumCA(integer c, integer a) = c + a;

    lemma sum_bound_AB: \forall integer a, b; valid_range(a) && valid_range(b) ==> sumAB(a, b) <= 200;
    lemma sum_bound_BC: \forall integer b, c; valid_range(b) && valid_range(c) ==> sumBC(b, c) <= 200;
    lemma sum_bound_CA: \forall integer c, a; valid_range(c) && valid_range(a) ==> sumCA(c, a) <= 200;
*/

/*@
    requires 1 <= A <= 100;
    requires 1 <= B <= 100;
    requires 1 <= C <= 100;
    ensures \result == (A + B == C || A + C == B || B + C == A);
    assigns \nothing;
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    unsigned int AB;
    unsigned int BC;
    unsigned int CA;
    bool result;

    //@ assert valid_range(A);
    //@ assert valid_range(B);
    //@ assert valid_range(C);

    //@ assert sumAB(A, B) <= 200;
    AB = A + B;

    //@ assert sumBC(B, C) <= 200;
    BC = B + C;

    //@ assert sumCA(C, A) <= 200;
    CA = C + A;

    if (AB == C || BC == A || CA == B)
    {
        //@ assert AB == C || BC == A || CA == B;
        result = true;
    }
    else
    {
        //@ assert !(AB == C || BC == A || CA == B);
        result = false;
    }

    return result;
}
