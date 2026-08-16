#include <stdint.h>

/*@
    predicate valid_range(integer x) = 0 <= x <= 4500;
*/

/*@
    logic integer compute_ans(integer r, integer g) = g + (g - r);
*/

/*@
    lemma ans_range_proof:
        \forall integer r, g;
            valid_range(r) && valid_range(g) ==> 
            -4500 <= g - r <= 4500;
*/

/*@
    requires valid_range(r);
    requires valid_range(g);
    ensures \result == compute_ans(r, g);
    assigns \nothing;
*/
int32_t func(int32_t r, int32_t g)
{
    int32_t ans;
    
    //@ assert valid_range(r);
    //@ assert valid_range(g);
    //@ assert -4500 <= g - r <= 4500;
    
    ans = g + (g - r);
    
    //@ assert ans == compute_ans(r, g);
    return ans;
}

int main()
{
    return 0;
}
