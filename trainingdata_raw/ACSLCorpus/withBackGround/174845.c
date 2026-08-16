#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer sum_abc(integer a, integer b, integer c) = a + b + c;
    logic integer sum_abd(integer a, integer b, integer d) = a + b + d;
    logic integer sum_acd(integer a, integer c, integer d) = a + c + d;
    logic integer sum_bcd(integer b, integer c, integer d) = b + c + d;

    lemma result_positive: \forall integer a,b,c,d;
        valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) ==>
        sum_abc(a,b,c) >= 3 && sum_abd(a,b,d) >= 3 && sum_acd(a,c,d) >= 3 && sum_bcd(b,c,d) >= 3;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == sum_abc(a,b,c) || \result == sum_abd(a,b,d) || 
            \result == sum_acd(a,c,d) || \result == sum_bcd(b,c,d);
    ensures \result >= 3;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t min_ab;
    int64_t min_bc;
    int64_t min_cd;
    int64_t min_ab_c;
    int64_t min_bc_d;
    int64_t min_ab_cd;
    int64_t min1;
    int64_t min2;
    int64_t result;

    //@ assert valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    
    min_ab = (a < b) ? a : b;
    min_bc = (b < c) ? b : c;
    min_cd = (c < d) ? c : d;
    min_ab_c = (min_ab < c) ? min_ab : c;
    min_bc_d = (min_bc < d) ? min_bc : d;
    min_ab_cd = (min_ab < d) ? min_ab : d;

    min1 = (min_ab_c < min_bc_d) ? min_ab_c : min_bc_d;
    min2 = (min_ab_cd < min1) ? min_ab_cd : min1;

    result = (a + b + c > b + c + d) ? (a + b + c) : (b + c + d);

    //@ assert result == sum_abc(a,b,c) || result == sum_bcd(b,c,d);
    
    return result;
}
