#include <stdbool.h>

/*@
    predicate valid_vector(int *s, integer len) =
        len == 3 &&
        \valid(s + (0 .. 2)) &&
        1 <= s[0] <= 100 &&
        1 <= s[1] <= 100 &&
        1 <= s[2] <= 100;

    logic integer vector_len(int *s) = 3;

    lemma vector_len_proof:
        \forall int *s; valid_vector(s, vector_len(s)) ==> vector_len(s) == 3;
*/

/*@
    requires valid_vector(s, 3);
    ensures \result == (s[0] <= s[2] - s[1]);
    assigns \nothing;
*/
bool func(int *s)
{
    // Variable declarations at scope top
    bool result;

    //@ assert \valid(s + (0 .. 2));
    //@ assert 1 <= s[0] <= 100;
    //@ assert 1 <= s[1] <= 100;
    //@ assert 1 <= s[2] <= 100;
    
    result = (s[0] <= s[2] - s[1]);
    return result;
}
