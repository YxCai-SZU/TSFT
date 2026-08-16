#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    predicate pi_approx(integer p) = p == 3142;
    
    logic integer scaled_product(integer pi, integer r) = 2 * pi * r;
    
    lemma product_bound: 
        \forall integer r, integer pi; 
        valid_range(r) && pi_approx(pi) ==> 
        scaled_product(pi, r) <= 2 * 100 * 100 * 3142;
*/

/*@
    requires valid_range(r);
    ensures \result == (2 * 3142 * r) / 1000;
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi_approx;
    int64_t scaled_r;
    int64_t result;
    int64_t temp;
    int64_t count;
    
    pi_approx = 3142;
    scaled_r = r * 1000;
    result = 0;
    temp = 2 * pi_approx * r;
    count = 0;
    
    //@ assert valid_range(r);
    //@ assert pi_approx(pi_approx);
    //@ assert temp == scaled_product(pi_approx, r);
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 3142;
        loop invariant temp >= 0;
        loop invariant count * 1000 + temp == 2 * pi_approx * r;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 1000)
    {
        temp -= 1000;
        count += 1;
    }
    
    result = count;
    return result;
}
