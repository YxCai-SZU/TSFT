#include <stdint.h>

/*@
    requires 1 <= n <= 20;
    requires 1 <= a <= 100;
    requires 1 <= b <= 2000;
    ensures \result == n * a || \result == b;
    ensures \result <= b;
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t a, int64_t b)
{
    //@ assert ((n) >= 1 && (n) <= 20 && (a) >= 1 && (a) <= 100 && (n) * (a) <= 2000);
    int64_t product;
    product = n * a;
    //@ assert product <= b || product > b;
    if (product < b)
    {
        //@ assert product == n * a;
        //@ assert product <= b;
        return product;
    }
    else
    {
        //@ assert b <= b;
        return b;
    }
}
