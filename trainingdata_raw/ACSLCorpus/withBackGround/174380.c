#include <stdint.h>

/*@
    predicate r_in_range(integer r) = 1 <= r && r <= 100;
    
    logic integer func_spec(integer r) = 3 * r * r;
    
    lemma func_bounds:
        \forall integer r;
        r_in_range(r) ==> 
            func_spec(r) >= 0 && func_spec(r) <= 300 * 100;
*/

/*@
    requires r_in_range(r);
    ensures \result == func_spec(r);
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t ans;
    
    //@ assert 1 <= r && r <= 100;
    
    //@ assert 3 * r >= 0;
    //@ assert 3 * r <= 300;
    //@ assert 3 * r * r >= 0;
    //@ assert 3 * r * r <= 300 * 100;
    
    ans = 3 * r * r;
    
    //@ assert ans >= 0;
    //@ assert ans <= 300 * 100;
    
    return ans;
}

int main()
{
    return 0;
}
