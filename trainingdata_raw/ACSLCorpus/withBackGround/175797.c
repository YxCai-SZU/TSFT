#include <stdint.h>

/*@
    predicate r_in_range(integer r) = 1 <= r <= 100;

    lemma product_bound_1:
        \forall integer r; r_in_range(r) ==> 1 * 2 <= 100 * 2;

    lemma product_bound_2:
        \forall integer r; r_in_range(r) ==> 1 * 2 * 3 <= 100 * 2 * 3;

    lemma product_bound_3:
        \forall integer r; r_in_range(r) ==> 1 * 2 * 3 * 5 <= 100 * 2 * 3 * 5;

    lemma final_bound:
        \forall integer r; r_in_range(r) ==> 3 * r * r <= 3 * 100 * 100;
*/

/*@
    requires 1 <= r <= 100;
    ensures \result == 3 * r * r;
*/
int32_t func(int32_t r)
{
    int32_t result;
    //@ assert 1 <= r <= 100;
    
    //@ assert 1 * 2 <= 100 * 2;
    //@ assert 1 * 2 * 3 <= 100 * 2 * 3;
    //@ assert 1 * 2 * 3 * 5 <= 100 * 2 * 3 * 5;
    
    //@ assert 3 * r * r <= 3 * 100 * 100;
    
    result = 3 * r * r;
    //@ assert result == 3 * r * r;
    return result;
}
