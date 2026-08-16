#include <stdint.h>

/*@
    predicate is_in_range(integer l) = 1 <= l <= 1000;
    
    logic integer div3(integer l) = l / 3;
    
    lemma div3_range: \forall integer l; is_in_range(l) ==> 0 <= div3(l) <= 333;
    lemma cube_range: \forall integer l; is_in_range(l) ==> 0 <= div3(l) * div3(l) * div3(l) <= 333333333;
*/

/*@
    requires is_in_range(l);
    ensures \result == div3(l) * div3(l) * div3(l);
    assigns \nothing;
*/
int64_t func(int64_t l)
{
    int64_t w = 0;
    int64_t temp_l = l;
    
    /*@
        loop invariant 0 <= w <= div3(l);
        loop invariant temp_l == l - 3 * w;
        loop invariant is_in_range(l);
        loop assigns w, temp_l;
        loop variant temp_l;
    */
    while (temp_l >= 3)
    {
        temp_l -= 3;
        w += 1;
    }
    
    //@ assert w == div3(l);
    
    //@ assert 0 <= w * w <= 333333;
    //@ assert 0 <= w * w * w <= 333333333;
    
    int64_t ans = w * w * w;
    
    //@ assert ans == div3(l) * div3(l) * div3(l);
    
    return ans;
}
