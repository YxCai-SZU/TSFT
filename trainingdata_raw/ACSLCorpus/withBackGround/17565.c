#include <stdint.h>

/*@ predicate is_valid_n(integer n) = 1 <= n && n <= 100; */

/*@ logic integer half(integer n) = n / 2; */
/*@ logic integer remainder(integer n) = n % 2; */
/*@ logic integer expected_result(integer n) = half(n) + remainder(n); */

/*@
    lemma half_correct: \forall integer n; is_valid_n(n) ==> half(n) == n / 2;
    lemma remainder_correct: \forall integer n; is_valid_n(n) ==> remainder(n) == n % 2;
    lemma result_correct: \forall integer n; is_valid_n(n) ==> expected_result(n) == (n / 2) + (n % 2);
*/

/*@
    requires is_valid_n(n);
    ensures \result == expected_result(n);
*/
uint32_t func(uint32_t n)
{
    // Variable declarations at the top
    uint32_t half_n;
    uint32_t is_odd;
    uint32_t result;
    
    half_n = n / 2;
    is_odd = n % 2;
    
    //@ assert half_n == half(n);
    //@ assert is_odd == remainder(n);
    
    result = half_n + is_odd;
    //@ assert result == expected_result(n);
    
    return result;
}
