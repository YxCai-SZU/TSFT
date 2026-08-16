#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= c && c <= 100 &&
        1 <= k && k <= 100;

    predicate post_condition(integer res, integer a, integer c, integer k) =
        res >= -c && res <= a && res <= k;
*/

/*@
    requires valid_params(a, b, c, k);
    ensures post_condition(\result, a, c, k);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t res;
    int64_t rst;
    
    res = 0;
    rst = k;
    
    if (a <= rst)
    {
        res += a;
        rst -= a;
    }
    else
    {
        res = k;
        //@ assert post_condition(res, a, c, k);
        return res;
    }
    
    if (b <= rst)
    {
        rst -= b;
    }
    else
    {
        //@ assert post_condition(res, a, c, k);
        return res;
    }
    
    if (c <= rst)
    {
        res -= c;
    }
    
    //@ assert post_condition(res, a, c, k);
    return res;
}
