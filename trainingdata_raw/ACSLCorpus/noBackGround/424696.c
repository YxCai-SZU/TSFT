#include <stdbool.h>

/*@ requires 1 <= k <= n <= 50;
    ensures \result == n - k + 1;
    assigns \nothing;
 */
long func(long n, long k)
{
    long result;
    //@ assert n - k + 1 == n - k + 1;
    result = n - k + 1;
    return result;
}

/*@ ensures \result <==> (((x) % 2) == 0);
    assigns \nothing;
 */
bool is_even_func(long x)
{
    bool ret;
    //@ assert (x % 2) == 0 <==> (((x) % 2) == 0);
    ret = ((x % 2) == 0);
    return ret;
}

/*@ ensures \result <==> (((x) % 2) != 0);
    assigns \nothing;
 */
bool is_odd_func(long x)
{
    bool ret;
    //@ assert (x % 2) != 0 <==> (((x) % 2) != 0);
    ret = ((x % 2) != 0);
    return ret;
}
