#include <stdbool.h>

/*@
    predicate is_valid_range(integer a) =
        1 <= a && a <= 9;

    predicate strictly_increasing(integer a, integer b, integer c) =
        a < b && b < c;

    logic integer compute_count(integer a, integer b, integer c) =
        (a < b ? 1 : 0) + (b < c ? 1 : 0);

    lemma count_implies_increasing:
        \forall integer a, b, c;
            is_valid_range(a) && is_valid_range(b) && is_valid_range(c) ==>
            (compute_count(a, b, c) == 2 <==> strictly_increasing(a, b, c));
*/

/*@
    requires 1 <= A && A <= 9;
    requires 1 <= B && B <= 9;
    requires 1 <= C && C <= 9;
    ensures \result == true <==> (A < B && B < C);
    ensures \result == false <==> !(A < B && B < C);
*/
bool func(int A, int B, int C)
{
    int count = 0;

    //@ assert is_valid_range(A) && is_valid_range(B) && is_valid_range(C);

    if (A < B)
    {
        count += 1;
    }

    if (B < C)
    {
        count += 1;
    }

    //@ assert count == compute_count(A, B, C);
    //@ assert count == 2 <==> strictly_increasing(A, B, C);

    if (count == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
