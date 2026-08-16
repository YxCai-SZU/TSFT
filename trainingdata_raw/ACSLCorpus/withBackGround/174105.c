#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer m) =
        1 <= n <= 10000 && 0 <= m <= 1000;

    logic integer calculate_ans(integer n) =
        (n / 500) * 1000 + (n % 500 / 100) * 100 + (n % 500 % 100 / 50) * 50;

    lemma ans_decomposition:
        \forall integer n; valid_params(n, 0) ==>
        calculate_ans(n) == (n / 500) * 1000 + (n % 500 / 100) * 100 + (n % 500 % 100 / 50) * 50;
*/

/*@
    requires valid_params(n, m);
    ensures \result == (m >= calculate_ans(n));
*/
bool func(unsigned int n, unsigned int m)
{
    unsigned int div;
    unsigned int rem;
    unsigned int div2;
    unsigned int rem2;
    unsigned int div3;
    unsigned int rem3;
    unsigned int ans;
    bool result;

    div = n / 500;
    rem = n % 500;
    div2 = rem / 100;
    rem2 = rem % 100;
    div3 = rem2 / 50;
    rem3 = rem2 % 50;
    ans = div * 1000 + div2 * 100 + div3 * 50;

    //@ assert ans == (n / 500) * 1000 + (n % 500 / 100) * 100 + (n % 500 % 100 / 50) * 50;
    //@ assert ans == calculate_ans(n);

    result = (m >= ans);
    return result;
}
