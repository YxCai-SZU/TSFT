#include <stdint.h>

/*@
    requires 1 <= l <= 1000;
    ensures \result == (l / 3) * (l / 3) * (l - 2 * (l / 3)) * 6 || \result == 0;
*/
int64_t func(int64_t l)
{
    int64_t l_div_3;
    int64_t temp_l;
    int64_t count;
    int64_t l_minus_2_l_div_3;
    int64_t ans;

    l_div_3 = 0;
    temp_l = l;
    count = 0;

    /*@
        loop invariant 1 <= l <= 1000;
        loop invariant 0 <= l_div_3;
        loop invariant 0 <= temp_l;
        loop invariant temp_l == l - 3 * l_div_3;
        loop invariant count == l_div_3;
        loop assigns temp_l, l_div_3, count;
        loop variant temp_l;
    */
    while (temp_l >= 3)
    {
        temp_l -= 3;
        l_div_3 += 1;
        count += 1;
    }

    l_minus_2_l_div_3 = l - 2 * l_div_3;

    //@ assert 0 <= l_div_3 <= 333;
    //@ assert 0 <= l_minus_2_l_div_3 <= 1000;
    //@ assert l_div_3 * l_div_3 <= 333 * 333;
    //@ assert l_div_3 * l_div_3 * l_minus_2_l_div_3 <= 333 * 333 * 1000;
    //@ assert l_div_3 * l_div_3 * l_minus_2_l_div_3 * 6 <= 333 * 333 * 1000 * 6;

    ans = l_div_3 * l_div_3 * l_minus_2_l_div_3 * 6;
    return ans;
}
