/*@
    predicate valid_input(integer A, integer B, integer C) =
        1 <= A && A <= 9 &&
        1 <= B && B <= 9 &&
        1 <= C && C <= 9;

    logic integer compute_k(integer B, integer C) = B * 10 + C;

    lemma mod_preserved:
        \forall integer k, integer B, integer C;
        k == compute_k(B, C) ==> k % 4 == compute_k(B, C) % 4;
*/

#include <stdbool.h>

/*@
    requires valid_input(A, B, C);
    ensures \result == ((B * 10 + C) % 4 < 1);
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    // Variable declarations at scope top
    unsigned int k;
    bool result;

    //@ assert valid_input(A, B, C);
    k = B * 10 + C;

    /*@
        loop invariant 1 <= A && A <= 9;
        loop invariant 1 <= B && B <= 9;
        loop invariant 1 <= C && C <= 9;
        loop invariant k <= B * 10 + C;
        loop invariant k % 4 == (B * 10 + C) % 4;
        loop assigns k;
    */
    while (k >= 4)
    {
        //@ assert k % 4 == (B * 10 + C) % 4;
        k -= 4;
    }

    //@ assert k == (B * 10 + C) % 4;
    result = (k < 1);
    return result;
}
