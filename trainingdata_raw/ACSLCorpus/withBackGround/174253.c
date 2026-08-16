#include <stddef.h>

/*@
    predicate valid_input(integer A, integer P) =
        0 <= A && A <= 100 &&
        0 <= P && P <= 100;

    logic integer compute_result(integer A, integer P) =
        (A * 3 + P) / 2;

    lemma max_bound:
        \forall integer A, P;
        valid_input(A, P) ==> compute_result(A, P) <= (100 * 3 + 100) / 2;
*/

/*@
    requires valid_input(A, P);
    ensures \result == compute_result(A, P);
    ensures \result <= (100 * 3 + 100) / 2;
*/
size_t func(size_t A, size_t P)
{
    // Variable declarations at scope top
    size_t ans;

    //@ assert 0 <= A * 3 && A * 3 <= 100 * 3;
    //@ assert 0 <= A * 3 + P && A * 3 + P <= 100 * 3 + 100;

    ans = (A * 3 + P) / 2;

    //@ assert ans == compute_result(A, P);
    //@ assert ans <= (100 * 3 + 100) / 2;

    return ans;
}
