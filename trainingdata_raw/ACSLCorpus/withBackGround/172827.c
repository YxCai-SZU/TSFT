#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 1000000000;

    logic integer func_result(integer n) =
        (n / 11) * 2 + (n % 11 > 6 ? 2 : (n % 11 > 0 ? 1 : 0));

    lemma result_bounds:
        \forall integer n;
        is_valid_n(n) ==>
        func_result(n) <= n &&
        func_result(n) <= 2 * (n / 11) + 2;

    lemma division_bound:
        \forall integer n;
        is_valid_n(n) ==>
        n / 11 <= 90909090;

    lemma multiplication_bound:
        \forall integer n;
        is_valid_n(n) ==>
        (n / 11) * 2 <= 181818180;
*/

/*@
    requires is_valid_n(n);
    ensures \result <= n;
    ensures \result <= 2 * (n / 11) + 2;
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    // Variable declarations at scope top
    uint64_t result;
    uint64_t div_result;
    uint64_t mod_result;
    uint64_t temp;

    // Precondition verification
    //@ assert 1 <= n && n <= 1000000000;

    // Arithmetic safety verification
    //@ assert n / 11 <= 90909090;
    //@ assert (n / 11) * 2 <= 181818180;

    div_result = n / 11;
    mod_result = n % 11;
    temp = div_result * 2;

    if (mod_result > 6)
    {
        result = temp + 2;
    }
    else if (mod_result > 0)
    {
        result = temp + 1;
    }
    else
    {
        result = temp;
    }

    // Postcondition verification
    //@ assert result <= n;
    //@ assert result <= 2 * (n / 11) + 2;

    return result;
}
