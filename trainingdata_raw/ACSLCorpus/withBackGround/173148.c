#include <stdint.h>

/*@
    predicate valid_k(integer k) = 1 <= k <= 23;
    logic integer func_result(integer k) = 48 - k;
    lemma result_range: \forall integer k; valid_k(k) ==> 0 <= func_result(k) <= 48;
*/

/*@
    requires valid_k(k);
    ensures \result == func_result(k);
    assigns \nothing;
*/
int32_t func(int32_t k)
{
    //@ assert 0 <= 48 - k;
    //@ assert 48 - k <= 48;
    
    return 48 - k;
}

int main()
{
    return 0;
}
