#include <stdint.h>

/*@
    predicate is_valid_range(integer l) = 1 <= l <= 1000;
    
    logic integer div3(integer l) = l / 3;
    
    lemma div3_bounds: \forall integer l; is_valid_range(l) ==> 0 <= div3(l) <= 333;
    lemma cube_bounds: \forall integer w; 0 <= w <= 333 ==> 0 <= w*w*w <= 333*333*333;
    lemma cube_identity: \forall integer l, integer w; is_valid_range(l) && w == div3(l) ==> w*w*w == div3(l)*div3(l)*div3(l);
*/

/*@
    requires is_valid_range(l);
    ensures \result == div3(l)*div3(l)*div3(l);
    assigns \nothing;
*/
int64_t func(int64_t l)
{
    int64_t w;
    int64_t temp_l;
    
    w = 0;
    temp_l = l;
    
    /*@
        loop invariant 0 <= temp_l <= l;
        loop invariant w == (l - temp_l) / 3;
        loop invariant temp_l == l - 3 * w;
        loop invariant temp_l >= 0;
        loop invariant 0 <= w <= 333;
        loop assigns w, temp_l;
        loop variant temp_l;
    */
    while (temp_l >= 3)
    {
        temp_l = temp_l - 3;
        w = w + 1;
    }
    
    //@ assert w == l / 3;
    //@ assert 0 <= w && w <= 333;
    //@ assert 0 <= w*w && w*w <= 333*333;
    //@ assert 0 <= w*w*w && w*w*w <= 333*333*333;
    //@ assert w*w*w == (l / 3) * (l / 3) * (l / 3);
    
    return w * w * w;
}

int main()
{
    return 0;
}
