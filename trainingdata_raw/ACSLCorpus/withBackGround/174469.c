#include <stdint.h>

/*@
    predicate is_valid_range(integer l) =
        1 <= l <= 1000;

    logic integer div3(integer l) = l / 3;

    logic integer cube(integer x) = x * x * x;

    lemma cube_bounds:
        \forall integer e; 0 <= e <= 333 ==>
        0 <= cube(e) <= cube(333);

    lemma div3_equiv:
        \forall integer l, e, temp_l;
        is_valid_range(l) ==>
        (temp_l == l - 3 * e && 0 <= e && e <= 333 && temp_l >= 0 && temp_l < 3) ==>
        e == div3(l);
*/

/*@
    requires is_valid_range(l);
    ensures \result == cube(div3(l));
    assigns \nothing;
*/
int64_t func(int64_t l)
{
    int64_t e = 0;
    int64_t temp_l = l;

    /*@
        loop invariant 1 <= l <= 1000;
        loop invariant 0 <= e <= 333;
        loop invariant temp_l >= 0;
        loop invariant temp_l == l - 3 * e;
        loop assigns e, temp_l;
        loop variant temp_l;
    */
    while (temp_l >= 3)
    {
        temp_l -= 3;
        e += 1;
    }

    //@ assert temp_l == l - 3 * e;
    //@ assert 0 <= temp_l < 3;
    //@ assert e == l / 3;
    
    int64_t result = e * e * e;
    return result;
}
