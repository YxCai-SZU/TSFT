#include <limits.h>

/*@
    requires (1 <= (n) <= 100);
    ensures \result == ((n) * 800 - ((n) / 15) * 200);
    assigns \nothing;
*/
int func(int n)
{
    int quotient = 0;
    int temp_n = n;
    int divisor = 15;

    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= quotient;
        loop invariant 0 <= temp_n;
        loop invariant n == temp_n + divisor * quotient;
        loop invariant 0 <= temp_n + divisor * quotient <= 100 + 15 * 100;
        loop invariant 0 <= divisor * quotient <= 15 * 100;
        loop assigns quotient, temp_n;
    */
    while (temp_n >= divisor)
    {
        temp_n -= divisor;
        quotient += 1;
    }

    //@ assert 0 <= quotient * 200 <= 100 * 200;

    int result = n * 800 - quotient * 200;
    return result;
}
