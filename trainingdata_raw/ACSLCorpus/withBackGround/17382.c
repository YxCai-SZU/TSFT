#include <stdint.h>

/*@
    predicate valid_range(integer l) = 1 <= l <= 1000;

    logic integer div3(integer l) = l / 3;

    logic integer cube(integer x) = x * x * x;

    lemma division_property:
        \forall integer l; valid_range(l) ==> 0 <= div3(l) <= 333;

    lemma cube_bound:
        \forall integer x; 0 <= x <= 333 ==> 0 <= cube(x) <= 333*333*333;
*/

/*@
    requires valid_range(l);
    ensures \result == cube(div3(l));
    ensures 0 <= \result <= 333*333*333;
*/
int64_t func(int64_t l)
{
    int64_t r;
    int64_t temp_l;
    int64_t count;

    r = 0;
    temp_l = l;
    count = 0;

    /*@
        loop invariant 1 <= l <= 1000;
        loop invariant 0 <= temp_l;
        loop invariant temp_l == l - 3 * count;
        loop invariant 0 <= count <= l / 3;
        loop assigns temp_l, count;
        loop variant temp_l;
    */
    while (temp_l >= 3)
    {
        temp_l -= 3;
        count += 1;
    }

    r = count;

    //@ assert r == l / 3;
    //@ assert 0 <= r && r <= 333;
    //@ assert 0 <= r * r && r * r <= 333 * 333;
    //@ assert 0 <= r * r * r && r * r * r <= 333 * 333 * 333;

    return r * r * r;
}
