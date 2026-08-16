#include <stdbool.h>

/*@
    predicate is_zero(integer x) = x == 0;
    predicate is_nonzero(integer x) = x != 0;
    predicate ans_zero(integer a, integer x) = a == 0 ==> is_zero(x);
    predicate ans_one(integer a, integer x) = a == 1 ==> is_nonzero(x);
*/

/*@
    requires -1 <= X <= 1;
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> X == 0;
    ensures \result == 1 ==> X != 0;
*/
int func(int X)
{
    int ans;
    
    //@ assert -1 <= X <= 1;
    
    if (X == 0)
    {
        ans = 0;
        //@ assert ans == 0;
        //@ assert is_zero(X);
    }
    else
    {
        ans = 1;
        //@ assert ans == 1;
        //@ assert is_nonzero(X);
    }
    
    //@ assert ans == 0 || ans == 1;
    //@ assert ans_zero(ans, X);
    //@ assert ans_one(ans, X);
    
    return ans;
}
