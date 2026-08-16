#include <stdint.h>

/*@
    predicate is_in_range(integer x) = 400 <= x <= 1999;
    
    logic integer compute_ret(integer x) = 8 - (x - 400) / 200;
    
    lemma ret_range: \forall integer x; is_in_range(x) ==> 1 <= compute_ret(x) <= 8;
*/

/*@
    requires is_in_range(x);
    ensures \result == compute_ret(x);
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    int64_t d;
    int64_t ret;
    
    //@ assert is_in_range(x);
    d = x - 400;
    ret = 8;
    
    /*@
        loop invariant 0 <= d <= x - 400;
        loop invariant d == x - 400 - 200 * (8 - ret);
        loop invariant 1 <= ret <= 8;
        loop assigns d, ret;
        loop variant d;
    */
    while (d >= 200)
    {
        //@ assert d >= 200;
        d = d - 200;
        ret = ret - 1;
        //@ assert d >= 0;
    }
    
    //@ assert ret == compute_ret(x);
    return ret;
}
