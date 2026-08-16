#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    
    logic integer calculate_result(integer r) = 
        (2 * r * 3142) / 1000;
*/

/*@
    requires valid_range(r);
    ensures \result == calculate_result(r);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t pi;
    int64_t ans;
    int64_t temp;
    int64_t div;
    
    pi = 3142;
    ans = 0;
    temp = 2 * r * pi;
    div = 1000;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 3142;
        loop invariant div == 1000;
        loop invariant temp >= 0;
        loop invariant ans >= 0;
        loop invariant temp == 2 * r * pi - ans * div;
        loop assigns temp, ans;
        loop variant temp;
    */
    while (temp >= div)
    {
        //@ assert temp >= div;
        temp -= div;
        ans += 1;
    }
    
    //@ assert ans == calculate_result(r);
    return ans;
}

/*@
    lemma result_correctness: 
        \forall integer r; valid_range(r) ==> 
        calculate_result(r) == (2 * r * 3142) / 1000;
*/
