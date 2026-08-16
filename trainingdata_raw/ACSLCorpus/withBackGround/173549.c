#include <stdbool.h>

/*@
    predicate valid_params(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    logic integer compute_ans(integer a, integer b, integer c) =
        (b + c) < a ? 0 : c - (a - b);
*/

/*@
    requires valid_params(a, b, c);
    ensures \result >= 0;
    ensures \result <= c;
    ensures (b + c) < a ==> \result == 0;
    ensures (b + c) >= a ==> \result == c - (a - b);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans;
    int min_val;

    //@ assert valid_params(a, b, c);
    
    if (b + c < a) {
        min_val = b + c;
        ans = 0;
    } else {
        min_val = a;
        ans = c - (a - b);
    }

    //@ assert ans == compute_ans(a, b, c);
    //@ assert ans >= 0;
    //@ assert ans <= c;

    return ans;
}
