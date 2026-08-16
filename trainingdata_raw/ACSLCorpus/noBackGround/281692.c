#include <stdbool.h>

/*@
  requires 1 <= n <= 10000;
  requires 1 <= k <= 10000;
  requires 1 <= y < x <= 10000;
  ensures \result == n * x || \result == k * x + (n - k) * y;
*/
unsigned int func(unsigned int n, unsigned int k, unsigned int x, unsigned int y)
{
    // Variable declarations at top of scope
    unsigned int res;

    if (n <= k)
    {
        //@ assert n * x <= 10000 * 10000;
        res = n * x;
    }
    else
    {
        //@ assert k * x <= 10000 * 10000;
        //@ assert (n - k) * y <= 10000 * 10000;
        res = k * x + (n - k) * y;
    }

    return res;
}

/*@
  requires a >= 0 && a <= 4294967295;
  ensures \result == (a % 2 == 0);
*/
bool is_even_func(unsigned int a)
{
    // Variable declarations at top of scope
    bool ret;

    //@ assert a >= 0 && a <= 4294967295;
    ret = (a % 2 == 0);
    return ret;
}
