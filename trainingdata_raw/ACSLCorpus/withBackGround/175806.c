#include <stdbool.h>

/*@
    predicate bounds(integer x, integer y) =
        1 <= x <= 205 && 1 <= y <= 205;

    logic integer calculate_ans(integer x, integer y) =
        (x > 1 ? (x - 1) * 100 : 0) +
        (y > 1 ? (y - 1) * 100 : 0) +
        (x == 1 && y == 1 ? 0 :
         x == 1 || y == 1 ? 100 : 200);

    lemma ans_nonnegative:
        \forall integer x, y; bounds(x, y) ==> calculate_ans(x, y) >= 0;

    lemma ans_bounded:
        \forall integer x, y; bounds(x, y) ==> calculate_ans(x, y) <= 1000000;
*/

/*@
    requires bounds(x, y);
    ensures \result >= 0;
    ensures \result <= 1000000;
    assigns \nothing;
*/
int func(int x, int y)
{
    int ans = 0;

    //@ assert bounds(x, y);
    
    if (x > 1)
    {
        ans += (x - 1) * 100;
    }
    
    if (y > 1)
    {
        ans += (y - 1) * 100;
    }
    
    if (x == 1 && y == 1)
    {
        //@ assert ans == calculate_ans(x, y);
        return ans;
    }
    else if (x == 1 || y == 1)
    {
        ans += 100;
    }
    else
    {
        ans += 200;
    }
    
    //@ assert ans == calculate_ans(x, y);
    return ans;
}
