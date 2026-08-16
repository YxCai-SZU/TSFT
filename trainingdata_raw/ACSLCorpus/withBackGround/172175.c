#include <stdint.h>

/*@ predicate both_small(integer a, integer b) = (a < 10 && b < 10); */
/*@ predicate one_large(integer a, integer b) = (a >= 10 || b >= 10); */

/*@ logic integer safe_product(integer a, integer b) = a * b; */

/*@ lemma product_bounds: 
      \forall integer a, b; 
      (1 <= a <= 9 && 1 <= b <= 9) ==> safe_product(a, b) <= 81; */

/*@ requires 1 <= a <= 20;
    requires 1 <= b <= 20;
    ensures (a < 10 && b < 10) ==> \result == a * b;
    ensures (a >= 10 || b >= 10) ==> \result == -1;
    assigns \nothing;
 */
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t a_usize;
    uint32_t b_usize;
    uint32_t ans;
    
    a_usize = a;
    b_usize = b;
    
    if (a_usize < 10 && b_usize < 10)
    {
        //@ assert a_usize >= 1 && a_usize <= 9;
        //@ assert b_usize >= 1 && b_usize <= 9;
        //@ assert a_usize * b_usize <= 81;
        ans = a_usize * b_usize;
    }
    else
    {
        return -1;
    }
    
    //@ assert both_small(a_usize, b_usize) ==> ans == a_usize * b_usize;
    return (int32_t)ans;
}
