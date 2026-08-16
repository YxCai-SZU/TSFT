#include <stdint.h>

/*@
    predicate k_in_range(integer k) = 1 <= k && k <= 100;
    logic integer result_value(integer k) = 3 * k * k;
    lemma result_bounds: \forall integer k; k_in_range(k) ==> 3 <= result_value(k) && result_value(k) <= 30000;
*/

/*@
    requires k_in_range(k);
    ensures \result == result_value(k);
    assigns \nothing;
*/
int64_t func(int64_t k)
{
    //@ assert k_in_range(k);
    
    //@ assert 3 <= 3 * k * k && 3 * k * k <= 30000;
    
    return 3 * k * k;
}

int main()
{
    return 0;
}
