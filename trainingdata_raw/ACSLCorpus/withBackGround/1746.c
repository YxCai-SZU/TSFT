#include <stdint.h>

/*@
    predicate r_in_range(integer r) = 1 <= r <= 100;
    
    logic integer func_spec(integer r) = 3 * r * r;
    
    lemma product_nonnegative: \forall integer r; r_in_range(r) ==> 3 * r >= 0;
    lemma result_bounded: \forall integer r; r_in_range(r) ==> 3 * r * r <= 30000;
*/

/*@
    requires r_in_range(r);
    ensures \result == func_spec(r);
    assigns \nothing;
*/
int32_t func(int32_t r)
{
    // Variable declarations at scope top
    int32_t result;
    
    //@ assert 1 <= r <= 100;
    //@ assert 3 * r >= 0;
    //@ assert 3 * r * r <= 30000;
    
    result = 3 * r * r;
    return result;
}

int main(void)
{
    return 0;
}
