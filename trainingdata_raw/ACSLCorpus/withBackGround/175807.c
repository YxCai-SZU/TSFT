#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 100 <= n && n <= 999;

    logic integer first_term(integer n) = 111 * (1000 - n) / 1000;
    logic integer second_term(integer n) = 111 * n / 1000;
    logic integer total_result(integer n) = first_term(n) + second_term(n);

    lemma overflow_prevention_first:
        \forall integer n; is_valid_n(n) ==> 111 * (1000 - n) <= 111 * 900;

    lemma overflow_prevention_second:
        \forall integer n; is_valid_n(n) ==> 111 * n <= 111 * 999;
*/

/*@
    requires is_valid_n(n);
    ensures \result == total_result(n);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    // Variable declarations at scope top
    uint64_t result;

    //@ assert is_valid_n(n);
    //@ assert 111 * (1000 - n) <= 111 * 900;
    //@ assert 111 * n <= 111 * 999;

    result = 111 * (1000 - n) / 1000 + 111 * n / 1000;
    //@ assert result == total_result(n);
    
    return result;
}
