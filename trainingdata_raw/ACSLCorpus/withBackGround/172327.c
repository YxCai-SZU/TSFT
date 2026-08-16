#include <stdint.h>

/*@
    predicate x_in_range(integer x) = 0 <= x <= 1000000000;

    logic integer div_500(integer x) = x / 500;
    logic integer mod_500(integer x) = x % 500;
    logic integer div_5(integer m) = m / 5;
    logic integer expected_result(integer x) = 
        div_500(x) * 1000 + div_5(mod_500(x)) * 5;

    lemma div_500_bound: \forall integer x; x_in_range(x) ==> 0 <= div_500(x);
    lemma mod_500_bound: \forall integer x; x_in_range(x) ==> 0 <= mod_500(x) < 500;
    lemma div_5_bound: \forall integer m; 0 <= m < 500 ==> 0 <= div_5(m);
*/

/*@
    requires x_in_range(x);
    ensures \result == expected_result(x);
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t res = 0;
    uint64_t temp_x = x;
    uint64_t x_div_500 = 0;
    uint64_t x_mod_500 = 0;
    uint64_t x_mod_500_div_5 = 0;

    //@ assert x_in_range(x);
    
    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant x_div_500 <= div_500(x);
        loop invariant temp_x == x - x_div_500 * 500;
        loop assigns temp_x, x_div_500;
        loop variant temp_x;
    */
    while (temp_x >= 500)
    {
        //@ assert temp_x >= 500;
        temp_x -= 500;
        x_div_500 += 1;
        //@ assert temp_x == x - x_div_500 * 500;
    }

    x_mod_500 = temp_x;
    //@ assert x_mod_500 == mod_500(x);
    
    temp_x = x_mod_500;
    
    /*@
        loop invariant 0 <= temp_x <= x_mod_500;
        loop invariant x_mod_500_div_5 <= div_5(x_mod_500);
        loop invariant temp_x == x_mod_500 - x_mod_500_div_5 * 5;
        loop assigns temp_x, x_mod_500_div_5;
        loop variant temp_x;
    */
    while (temp_x >= 5)
    {
        //@ assert temp_x >= 5;
        temp_x -= 5;
        x_mod_500_div_5 += 1;
        //@ assert temp_x == x_mod_500 - x_mod_500_div_5 * 5;
    }

    //@ assert x_mod_500_div_5 == div_5(x_mod_500);
    
    res = x_div_500 * 1000 + x_mod_500_div_5 * 5;
    
    //@ assert x_div_500 == div_500(x);
    //@ assert res == expected_result(x);
    
    return res;
}
