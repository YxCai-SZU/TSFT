#include <limits.h>

/*@
    predicate is_positive(integer x) = x > 0;
    predicate is_negative(integer x) = x < 0;
    
    lemma sign_lemma:
        \forall integer x;
            (x != 0 && -40 <= x <= 40) ==> 
            (is_positive(x) || is_negative(x));
*/

/*@
    requires -40 <= X <= 40;
    requires X != 0;
    ensures (X > 0 ==> \result == 1);
    ensures (X < 0 ==> \result == -1);
    assigns \nothing;
*/
int func(int X)
{
    int result;
    
    //@ assert X != 0;
    
    if (X > 0)
    {
        //@ assert is_positive(X);
        result = 1;
    }
    else
    {
        //@ assert is_negative(X);
        result = -1;
    }
    
    return result;
}
