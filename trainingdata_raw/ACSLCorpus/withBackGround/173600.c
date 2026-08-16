#include <stdbool.h>

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    logic integer compute_ans(integer a, integer b, integer c) =
        c - (a - b);
*/

/*@
    requires valid_input(a, b, c);
    ensures \result >= 0;
    ensures \result <= c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans;
    //@ assert valid_input(a, b, c);
    ans = c - (a - b);
    
    if (ans < 0)
    {
        //@ assert 0 >= 0 && 0 <= c;
        return 0;
    }
    else
    {
        //@ assert ans <= c;
        return ans;
    }
}
