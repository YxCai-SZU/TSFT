#include <stdbool.h>

/*@
    predicate is_valid_param(integer N) = 1 <= N && N <= 9;
    predicate result_condition(integer N, bool result) = 
        result == (N == 3 || N == 5 || N == 7);
*/

/*@
    requires is_valid_param(N);
    ensures result_condition(N, \result);
    assigns \nothing;
*/
bool func(unsigned long N)
{
    bool result;
    //@ assert 1 <= N && N <= 9;
    result = (N == 3 || N == 5 || N == 7);
    //@ assert result_condition(N, result);
    return result;
}

/*@
    predicate valid_params(integer n, integer k) = 
        1 <= n && n <= 100000 && 0 <= k && k <= n - 1;
    predicate result_valid(integer res, integer n) = 
        res >= 0 && res < n;
*/

/*@
    requires valid_params(n, k);
    ensures result_valid(\result, n);
    assigns \nothing;
*/
long func2(long n, long k)
{
    long res;
    //@ assert valid_params(n, k);
    res = n - k - 1;
    if (res < 0) {
        res = -res;
    }
    //@ assert res >= 0;
    //@ assert res < n;
    return res;
}

/*@
    requires valid_params(n, k);
    ensures result_valid(\result, n);
    assigns \nothing;
*/
long func3(long n, long k)
{
    long res;
    //@ assert valid_params(n, k);
    res = n - k - 1;
    if (res < 0) {
        res = -res;
    }
    //@ assert res >= 0;
    //@ assert res < n;
    return res;
}

/*@
    requires valid_params(n, k);
    ensures result_valid(\result, n);
    assigns \nothing;
*/
long func4(long n, long k)
{
    long res;
    //@ assert valid_params(n, k);
    res = n - k - 1;
    if (res < 0) {
        res = -res;
    }
    //@ assert res >= 0;
    //@ assert res < n;
    return res;
}
