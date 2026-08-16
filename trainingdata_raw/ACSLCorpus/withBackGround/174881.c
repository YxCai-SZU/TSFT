#include <stdint.h>

/*@
    predicate valid_range(integer a) = 1 <= a <= 9;

    logic integer safe_sum(integer a, integer b) = a + b;

    lemma sum_range: \forall integer a, b; valid_range(a) && valid_range(b) ==> 0 <= safe_sum(a, b) <= 18;
*/

/*@
    requires valid_range(A) && valid_range(B);
    ensures (\result == A + B && A + B < 10) || \result == -1;
*/
int64_t func(int64_t A, int64_t B)
{
    // Variable declarations at scope top
    int64_t result;

    //@ assert 1 <= A <= 9;
    //@ assert 1 <= B <= 9;

    if (A + B < 10)
    {
        result = A + B;
        //@ assert result == A + B && A + B < 10;
    }
    else
    {
        result = -1;
        //@ assert result == -1;
    }

    return result;
}
