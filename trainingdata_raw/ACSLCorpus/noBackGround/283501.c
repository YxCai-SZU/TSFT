#include <limits.h>

/*@
    requires (0 <= (x) <= 1000000000);
    ensures \result >= 0;
    ensures \result == (((x) / 1000) * 1000 + (((x) % 1000) / 100) * 100 + (((x) % 100) / 10) * 10 + ((x) % 10));
    assigns \nothing;
*/
int func(int x)
{
    int n;
    int sum;
    int div_1000;
    int div_100;
    int div_10;
    
    n = x;
    sum = 0;
    div_1000 = 0;
    
    /*@
        loop invariant 0 <= n <= x;
        loop invariant 0 <= div_1000 <= x / 1000;
        loop invariant n == x - div_1000 * 1000;
        loop invariant sum == div_1000 * 1000;
        loop assigns n, div_1000, sum;
    */
    while (n >= 1000)
    {
        n -= 1000;
        div_1000 += 1;
        sum += 1000;
    }
    
    div_100 = 0;
    /*@
        loop invariant 0 <= n <= x - div_1000 * 1000;
        loop invariant 0 <= div_100 <= (x % 1000) / 100;
        loop invariant n == x - div_1000 * 1000 - div_100 * 100;
        loop invariant sum == div_1000 * 1000 + div_100 * 100;
        loop assigns n, div_100, sum;
    */
    while (n >= 100)
    {
        n -= 100;
        div_100 += 1;
        sum += 100;
    }
    
    div_10 = 0;
    /*@
        loop invariant 0 <= n <= x - div_1000 * 1000 - div_100 * 100;
        loop invariant 0 <= div_10 <= (x % 100) / 10;
        loop invariant n == x - div_1000 * 1000 - div_100 * 100 - div_10 * 10;
        loop invariant sum == div_1000 * 1000 + div_100 * 100 + div_10 * 10;
        loop assigns n, div_10, sum;
    */
    while (n >= 10)
    {
        n -= 10;
        div_10 += 1;
        sum += 10;
    }
    
    sum += n;
    //@ assert sum == (((x) / 1000) * 1000 + (((x) % 1000) / 100) * 100 + (((x) % 100) / 10) * 10 + ((x) % 10));
    return sum;
}
