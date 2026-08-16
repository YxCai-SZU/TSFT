#include <stdint.h>

/*@
    predicate is_valid_n(integer n) =
        1 <= n && n <= 100000;

    logic integer div_100(integer n) = n / 100;
    logic integer mod_100(integer n) = n % 100;

    lemma div_bound: \forall integer n; is_valid_n(n) ==> div_100(n) <= 1000;
    lemma mod_bound: \forall integer n; is_valid_n(n) ==> mod_100(n) <= 99;
    lemma mul_bound: \forall integer n; is_valid_n(n) ==> 5 * div_100(n) <= 5000;
*/


uint32_t func(uint32_t n)
{
    uint32_t num;
    uint32_t rem;
    //@ assert is_valid_n(n);
    num = n / 100;
    rem = n % 100;
    //@ assert num <= 1000;
    //@ assert rem <= 99;
    //@ assert 5 * num <= 5000;
    if (rem <= 5 * num)
    {
        //@ assert mod_100(n) <= 5 * div_100(n);
        return 1;
    }
    else
    {
        //@ assert mod_100(n) > 5 * div_100(n);
        return 0;
    }
}
