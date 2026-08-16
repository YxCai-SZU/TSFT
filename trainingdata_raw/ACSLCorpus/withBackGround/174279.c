#include <limits.h>

/*@
    predicate is_valid_input(integer x) =
        x * x * x <= INT_MAX &&
        x * x * x >= INT_MIN;
*/

/*@
    lemma intermediate_bound:
        \forall integer x;
            is_valid_input(x) ==>
                x * x <= INT_MAX &&
                x * x >= INT_MIN;
*/

/*@
    lemma final_bound:
        \forall integer x;
            is_valid_input(x) ==>
                x * x * x <= INT_MAX &&
                x * x * x >= INT_MIN;
*/

/*@
    requires is_valid_input(x);
    ensures \result == x * x * x;
    assigns \nothing;
*/
int func(int x)
{
    //@ assert x * x <= INT_MAX && x * x >= INT_MIN;
    //@ assert x * x * x <= INT_MAX && x * x * x >= INT_MIN;
    //@ assert x * x * x <= INT_MAX && x * x * x >= INT_MIN;
    
    int result;
    result = x * x * x;
    return result;
}
