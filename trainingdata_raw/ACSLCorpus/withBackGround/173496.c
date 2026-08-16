#include <limits.h>

/*@
    predicate r_in_range(integer r) = 1 <= r <= 100;
    
    logic integer func_spec(integer r) = 3 * r * r;
    
    lemma func_spec_nonneg: \forall integer r; r_in_range(r) ==> func_spec(r) >= 0;
    lemma no_overflow: \forall integer r; r_in_range(r) ==> func_spec(r) <= INT_MAX;
*/

/*@
    requires r_in_range(r);
    requires r == (int)r;
    ensures \result == func_spec(r);
    ensures \result >= 0;
*/
int func(int r)
{
    int ans;
    
    //@ assert 1 <= r && r <= 100;
    
    //@ assert 3 * (long long)r * (long long)r <= (long long)INT_MAX;
    
    ans = 3 * r * r;
    
    //@ assert ans == func_spec(r);
    //@ assert ans >= 0;
    
    return ans;
}

int main()
{
    return 0;
}
