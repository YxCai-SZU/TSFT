#include <stdint.h>

/*@
    predicate r_in_range(integer r) = 1 <= r && r <= 100;
    predicate ans_correct(integer ans, integer r) = ans == 3 * (r * r);
*/

/*@
    requires r_in_range(r);
    ensures ans_correct(\result, r);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t ans;
    
    //@ assert 1 <= r && r <= 100;
    //@ assert 1 <= r * r && r * r <= 10000;
    //@ assert 3 * (r * r) <= 30000;
    
    ans = 3 * (r * r);
    
    //@ assert ans_correct(ans, r);
    return ans;
}

int main()
{
    return 0;
}
