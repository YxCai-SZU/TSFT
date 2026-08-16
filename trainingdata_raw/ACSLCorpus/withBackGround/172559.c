#include <stdbool.h>

/*@
    predicate is_valid_input(integer x) = 0 <= x <= 1;
    
    logic integer compute_result(integer x) = 1 - x;
    
    lemma result_correct: 
        \forall integer x; is_valid_input(x) ==> compute_result(x) == 1 - x;
*/

/*@
    requires is_valid_input(x);
    ensures \result == compute_result(x);
    assigns \nothing;
*/
int func(int x)
{
    // Variable declarations at top of scope
    int res;
    
    //@ assert x == 0 || x == 1;
    
    res = 1 - x;
    
    //@ assert res == compute_result(x);
    
    return res;
}

int main()
{
    return 0;
}
