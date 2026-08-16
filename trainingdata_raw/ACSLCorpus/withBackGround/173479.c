#include <stdbool.h>

/*@
    predicate valid_range(integer k, integer a, integer b) =
        1 <= k <= 1000 && 1 <= a <= b <= 1000;

    logic integer safe_div(integer b, integer k) = b / k;

    logic integer safe_mul(integer d, integer k) = d * k;

    lemma division_bound:
        \forall integer k, b;
        valid_range(k, 1, b) ==> safe_div(b, k) <= 1000;

    lemma multiplication_bound:
        \forall integer k, b;
        valid_range(k, 1, b) ==> safe_mul(safe_div(b, k), k) <= 1000000;
*/

/*@
    requires valid_range(k, a, b);
    ensures \result == (safe_mul(safe_div(b, k), k) >= a);
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int div_result;
    unsigned int mul_result;
    bool ans;

    //@ assert valid_range(k, a, b);
    
    //@ assert safe_div(b, k) <= 1000;
    div_result = b / k;
    
    //@ assert safe_mul(div_result, k) <= 1000000;
    mul_result = div_result * k;
    
    ans = (mul_result >= a);
    
    //@ assert ans == (safe_mul(safe_div(b, k), k) >= a);
    return ans;
}
