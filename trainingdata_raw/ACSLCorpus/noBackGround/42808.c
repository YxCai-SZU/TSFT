#include <stdbool.h>

/*@
    requires (1 <= (k) <= 1000 && 1 <= (a) <= (b) <= 1000);
    ensures \result == ((((b) / (k)) * (k)) >= a);
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int div_result;
    unsigned int mul_result;
    bool ans;

    //@ assert 1 <= k <= 1000;
    //@ assert 1 <= a <= b <= 1000;

    div_result = b / k;
    //@ assert div_result <= 1000;

    mul_result = div_result * k;
    //@ assert mul_result <= 1000000;

    ans = mul_result >= a;
    //@ assert ans == ((((b) / (k)) * (k)) >= a);

    return ans;
}
