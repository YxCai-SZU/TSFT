#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    logic integer sum_abc(integer a, integer b, integer c) = a + b + c;
    logic integer sum_10a_bc(integer a, integer b, integer c) = 10 * a + b + c;
    logic integer sum_10b_ca(integer b, integer c, integer a) = 10 * b + c + a;
    logic integer sum_10c_ab(integer c, integer a, integer b) = 10 * c + a + b;

    lemma max_value_bound:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==>
            sum_10a_bc(a, b, c) <= 10 * 9 + 9 + 9 &&
            sum_10b_ca(b, c, a) <= 10 * 9 + 9 + 9 &&
            sum_10c_ab(c, a, b) <= 10 * 9 + 9 + 9;
*/

/*@
    requires 1 <= A <= 9;
    requires 1 <= B <= 9;
    requires 1 <= C <= 9;
    ensures \result == sum_abc(A, B, C) ||
            \result == sum_10a_bc(A, B, C) ||
            \result == sum_10b_ca(B, C, A) ||
            \result == sum_10c_ab(C, A, B);
*/
long func(long A, long B, long C)
{
    long max1;
    long max2;
    long result;

    //@ assert valid_range(A);
    //@ assert valid_range(B);
    //@ assert valid_range(C);

    if (A > B)
    {
        max1 = A;
    }
    else
    {
        max1 = B;
    }

    if (max1 > C)
    {
        max2 = max1;
    }
    else
    {
        max2 = C;
    }

    if (max2 == A)
    {
        //@ assert max2 == A;
        //@ assert sum_10a_bc(A, B, C) <= 10 * 9 + 9 + 9;
        result = 10 * A + B + C;
        return result;
    }
    else if (max2 == B)
    {
        //@ assert max2 == B;
        //@ assert sum_10b_ca(B, C, A) <= 10 * 9 + 9 + 9;
        result = 10 * B + C + A;
        return result;
    }
    else
    {
        //@ assert max2 == C;
        //@ assert sum_10c_ab(C, A, B) <= 10 * 9 + 9 + 9;
        result = 10 * C + A + B;
        return result;
    }
}
