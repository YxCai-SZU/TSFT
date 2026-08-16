#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer abs_diff(integer x, integer y) = 
        x > y ? x - y : y - x;

    lemma diff_bounds:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==> 
            -99 <= a - b <= 99;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result >= 1 && \result <= 3;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int b1, c1, b2, ans;
    
    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 100;
    //@ assert c >= 1 && c <= 100;
    
    //@ assert a - b >= -99 && a - b <= 99;
    //@ assert b - c >= -99 && b - c <= 99;
    //@ assert c - b >= -99 && c - b <= 99;
    
    b1 = a > b ? a - b : b - a;
    c1 = b1 > c ? b1 - c : c - b1;
    b2 = c1 > b1 ? c1 - b1 : b1 - c1;
    
    //@ assert b1 == abs_diff(a, b);
    //@ assert c1 == abs_diff(b1, c);
    //@ assert b2 == abs_diff(c1, b1);
    
    if (a == b2 + c1) {
        ans = 1;
    } else if (a < b2 + c1) {
        ans = 2;
    } else {
        ans = 3;
    }
    
    //@ assert ans >= 1 && ans <= 3;
    return ans;
}
