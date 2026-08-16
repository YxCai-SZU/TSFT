#include <stdbool.h>

/*@
    predicate is_positive(integer x) = x > 0;
    predicate is_within_range(integer x) = 1 <= x && x <= 20;

    logic integer compute_result(integer n, integer m) =
        n > m ? 0 : 1;

    lemma result_correct:
        \forall integer n, m;
        is_within_range(n) && is_within_range(m) ==>
        (n > m ==> compute_result(n, m) == 0) &&
        (n <= m ==> compute_result(n, m) == 1);
*/

/*@
    requires 1 <= n <= 20;
    requires 1 <= m <= 20;
    ensures (n > m ==> \result == 0);
    ensures (n <= m ==> \result == 1);
    assigns \nothing;
*/
int func(int n, int m)
{
    int result;
    
    //@ assert is_within_range(n);
    //@ assert is_within_range(m);
    
    if (n > m)
    {
        result = 0;
        //@ assert result == 0;
    }
    else
    {
        result = 1;
        //@ assert result == 1;
    }
    
    //@ assert n > m ==> result == 0;
    //@ assert n <= m ==> result == 1;
    
    return result;
}
