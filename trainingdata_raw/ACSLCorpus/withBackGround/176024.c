#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= a && a <= 9 &&
        1 <= b && b <= 9 &&
        1 <= c && c <= 9;

    logic integer compute_ans(integer a, integer b, integer c) =
        c < a + 1 ? 10 * (a + 1) + c :
        a + 1 < b ? 10 * (b + 1) + a :
                    10 * (c + 1) + b;

    lemma ans_range: \forall integer a, b, c;
        valid_input(a, b, c) ==> 10 <= compute_ans(a, b, c) <= 999;
*/

/*@
    requires valid_input(A, B, C);
    ensures \result >= 10 && \result <= 999;
    assigns \nothing;
*/
int64_t func(int64_t A, int64_t B, int64_t C)
{
    int64_t ans;
    //@ assert valid_input(A, B, C);
    
    if (C < A + 1) {
        ans = 10 * (A + 1) + C;
    } else if (A + 1 < B) {
        ans = 10 * (B + 1) + A;
    } else {
        ans = 10 * (C + 1) + B;
    }
    
    //@ assert ans == compute_ans(A, B, C);
    //@ assert ans >= 10;
    //@ assert ans <= 999;
    
    return ans;
}
