#include <limits.h>

/*@
    predicate is_valid_l(integer l) = 1 <= l <= 1000;
    
    logic integer div3(integer l) = l / 3;
    
    lemma div3_range: \forall integer l; is_valid_l(l) ==> 0 <= div3(l) <= 333;
    lemma cube_bound: \forall integer e; 0 <= e <= 333 ==> e * e * e <= 333 * 333 * 333;
*/

/*@
    requires is_valid_l(l);
    ensures \result == div3(l) * div3(l) * div3(l);
    assigns \nothing;
*/
int func(int l)
{
    int e;
    int temp_l;
    
    e = 0;
    temp_l = l;
    
    /*@
        loop invariant 1 <= l <= 1000;
        loop invariant 0 <= e;
        loop invariant e <= div3(l);
        loop invariant temp_l == l - 3 * e;
        loop invariant temp_l >= 0;
        loop assigns e, temp_l;
        loop variant temp_l;
    */
    while (temp_l >= 3)
    {
        temp_l = temp_l - 3;
        e = e + 1;
    }
    
    //@ assert temp_l >= 0;
    //@ assert e >= 0 && e <= 333;
    //@ assert e * e <= 333 * 333;
    //@ assert e * e * e <= 333 * 333 * 333;
    
    int ans = e * e * e;
    return ans;
}
