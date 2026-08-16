#include <stdbool.h>

/*@
    requires (1 <= (k) <= 1000 && 1 <= (a) <= (b) <= 1000);
    ensures \result == true <==> (b / k * k >= a);
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int div_result;
    unsigned int mul_result;
    bool ans;

    //@ assert 1 <= k <= 1000;
    //@ assert 1 <= a <= b <= 1000;

    //@ assert b / k <= 1000;
    //@ assert (b / k) * k <= 1000000;

    div_result = b / k;
    mul_result = div_result * k;
    ans = (mul_result >= a);

    //@ assert ans == true <==> (b / k * k >= a);
    return ans;
}
