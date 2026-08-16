#include <stdint.h>

/*@
    predicate is_valid_params(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer compute_result(integer a, integer b) =
        a - b * 2;

    logic integer final_result(integer a, integer b) =
        compute_result(a, b) > 0 ? compute_result(a, b) : 0;

    lemma result_non_negative:
        \forall integer a, b;
        is_valid_params(a, b) ==> final_result(a, b) >= 0;

    lemma result_correct:
        \forall integer a, b;
        is_valid_params(a, b) ==> 
        (final_result(a, b) == compute_result(a, b) || final_result(a, b) == 0);
*/

/*@
    requires is_valid_params(a, b);
    ensures \result >= 0;
    ensures \result == compute_result(a, b) || \result == 0;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t res;
    int64_t ans;
    
    //@ assert is_valid_params(a, b);
    
    res = a - b * 2;
    
    //@ assert res == compute_result(a, b);
    
    if (res > 0)
    {
        ans = res;
        //@ assert ans == compute_result(a, b);
    }
    else
    {
        ans = 0;
        //@ assert ans == 0;
    }
    
    //@ assert ans == final_result(a, b);
    //@ assert ans >= 0;
    //@ assert ans == compute_result(a, b) || ans == 0;
    
    return ans;
}
