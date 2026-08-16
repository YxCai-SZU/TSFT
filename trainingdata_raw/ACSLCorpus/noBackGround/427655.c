#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == 800 * n - 200 * (n / 15);
    assigns \nothing;
*/
int func(int n)
{
    int x;
    int quotient = 0;
    int remainder = n;
    int divisor = 15;
    int y;
    int ans;
    
    //@ assert (1 <= (n) && (n) <= 100);
    x = 800 * n;
    
    /*@
        loop invariant 0 <= quotient <= n / 15;
        loop invariant remainder == n - quotient * divisor;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder >= divisor;
        quotient = quotient + 1;
        remainder = remainder - divisor;
    }
    
    //@ assert quotient == n / 15;
    y = 200 * quotient;
    ans = x - y;
    
    //@ assert ans == 800 * n - 200 * (n / 15);
    return ans;
}
