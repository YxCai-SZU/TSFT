#include <stdint.h>

/*@
    predicate non_negative(integer v) = v >= 0;
    predicate val_bounds(integer v, integer x) = 0 <= v <= x;
    predicate val_eq_sub(integer v, integer x, integer t, integer base) =
        v == x - base * t;
    predicate val_eq_mod_sub(integer v, integer x, integer t, integer base, integer mod_base) =
        v == x % mod_base - base * t;
    predicate val_eq_mod_mod_sub(integer v, integer x, integer t, integer base, integer mod_base1, integer mod_base2) =
        v == (x % mod_base1) % mod_base2 - base * t;
*/

/*@
    logic integer total_res(integer x) =
        1000 * (x / 1000) +
        100 * ((x % 1000) / 100) +
        10 * (((x % 1000) % 100) / 10) +
        (x % 10);
*/

/*@
    requires 0 <= x <= 1000000000;
    ensures \result >= 0;
    ensures \result == total_res(x);
*/
int32_t func(int32_t x)
{
    int32_t res;
    int32_t val;
    int32_t tmp;

    res = 0;
    val = x;
    tmp = 0;

    /*@
        loop invariant 0 <= val <= x;
        loop invariant tmp >= 0;
        loop invariant val == x - 1000 * tmp;
        loop assigns tmp, val;
        loop variant val;
    */
    while (val >= 1000)
    {
        tmp = tmp + 1;
        val = val - 1000;
        //@ assert 0 <= val <= x;
    }
    res = res + tmp * 1000;

    tmp = 0;
    /*@
        loop invariant 0 <= val <= x % 1000;
        loop invariant tmp >= 0;
        loop invariant val == x % 1000 - 100 * tmp;
        loop assigns tmp, val;
        loop variant val;
    */
    while (val >= 100)
    {
        tmp = tmp + 1;
        val = val - 100;
        //@ assert 0 <= val <= x % 1000;
    }
    res = res + tmp * 100;

    tmp = 0;
    /*@
        loop invariant 0 <= val <= (x % 1000) % 100;
        loop invariant tmp >= 0;
        loop invariant val == (x % 1000) % 100 - 10 * tmp;
        loop assigns tmp, val;
        loop variant val;
    */
    while (val >= 10)
    {
        tmp = tmp + 1;
        val = val - 10;
        //@ assert 0 <= val <= (x % 1000) % 100;
    }
    res = res + tmp * 10;

    res = res + val;
    //@ assert res == total_res(x);
    return res;
}
