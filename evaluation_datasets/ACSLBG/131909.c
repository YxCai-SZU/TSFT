#include <stdbool.h>

/*@
    predicate valid_inputs(integer n, integer k) =
        1 <= n && n <= 100 &&
        1 <= k && k <= 100;

    logic integer division_result(integer n, integer k) = n / k;

    lemma division_bound: \forall integer n, k; 
        valid_inputs(n, k) && n % k == 0 ==> division_result(n, k) <= 100;
*/


bool can_distribute_evenly(unsigned int n, unsigned int k)
{
    //@ assert valid_inputs(n, k);
    
    //@ assert n / k <= 100;
    
    //@ assert n % k == 0 ==> n / k <= 100;
    
    return n % k == 0;
}

int main()
{
    return 0;
}
