#include <stdint.h>

/*@
    predicate valid_input(integer l) =
        1 <= l <= 1000;

    logic integer div3(integer l) = l / 3;

    lemma div3_range:
        \forall integer l; valid_input(l) ==> 0 <= div3(l) <= 333;

    lemma cube_result:
        \forall integer l; valid_input(l) ==> 
            div3(l) * div3(l) * div3(l) == (l / 3) * (l / 3) * (l / 3);
*/

/*@
    requires valid_input(l);
    ensures \result == (l / 3) * (l / 3) * (l / 3);
    assigns \nothing;
*/
int64_t func(int64_t l)
{
    int64_t l_div_3;
    int64_t count;
    int64_t temp_l;

    l_div_3 = 0;
    count = 0;
    temp_l = l;

    /*@
        loop invariant 0 <= temp_l <= l;
        loop invariant 0 <= l_div_3 <= 333;
        loop invariant 0 <= count <= 333;
        loop invariant l == temp_l + 3 * l_div_3;
        loop invariant count == l_div_3;
        loop assigns temp_l, l_div_3, count;
        loop variant temp_l;
    */
    while (temp_l >= 3)
    {
        temp_l -= 3;
        l_div_3 += 1;
        count += 1;
        //@ assert l_div_3 <= 333;
    }

    //@ assert 0 <= temp_l < 3;
    //@ assert 0 <= l_div_3 <= 333;
    //@ assert l_div_3 * l_div_3 <= 333 * 333;
    //@ assert l_div_3 * l_div_3 * l_div_3 <= 333 * 333 * 333;
    //@ assert l_div_3 >= 0;
    //@ assert l_div_3 * l_div_3 >= 0;
    //@ assert l_div_3 * l_div_3 * l_div_3 >= 0;

    int64_t result = l_div_3 * l_div_3 * l_div_3;
    return result;
}
