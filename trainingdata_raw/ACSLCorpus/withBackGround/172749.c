#include <stdbool.h>

/*@
    predicate valid_range(integer k, integer a, integer b) =
        1 <= k <= 1000 &&
        1 <= a <= b <= 1000;

    logic integer safe_div(integer b, integer k) = b / k;

    logic integer safe_mul(integer div, integer k) = div * k;

    lemma mul_bound: \forall integer k, integer b;
        valid_range(k, 1, b) ==> safe_div(b, k) * k <= 1000000;
*/

/*@
    requires valid_range(k, a, b);
    ensures \result == (safe_mul(safe_div(b, k), k) >= a);
    assigns \nothing;
*/
bool func(int k, int a, int b)
{
    // Variable declarations at top
    int div_result;
    int mul_result;
    bool comparison_result;

    //@ assert valid_range(k, a, b);
    
    div_result = b / k;
    //@ assert div_result == safe_div(b, k);
    
    mul_result = div_result * k;
    //@ assert mul_result == safe_mul(div_result, k);
    
    comparison_result = mul_result >= a;
    //@ assert comparison_result == (safe_mul(safe_div(b, k), k) >= a);
    
    return comparison_result;
}

int main()
{
    int k = 7;
    int a = 300;
    int b = 450;
    bool result;
    
    //@ assert valid_range(k, a, b);
    result = func(k, a, b);
    //@ assert result == (safe_mul(safe_div(b, k), k) >= a);
    
    return 0;
}
