#include <stdbool.h>

/*@
    requires 10 <= n <= 99;
    ensures \result == (n % 10 == 9 || n / 10 == 9);
    assigns \nothing;
*/
bool func(int n)
{
    int remainder;
    int mod_10;
    int div_result;
    int temp_n;
    bool condition;

    // Manual modulus operation: n % 10
    remainder = n;
    /*@
        loop invariant 10 <= n <= 99;
        loop invariant 0 <= remainder <= n;
        loop invariant remainder == n || remainder == n - 10 || remainder == n - 20 || 
                     remainder == n - 30 || remainder == n - 40 || remainder == n - 50 || 
                     remainder == n - 60 || remainder == n - 70 || remainder == n - 80 || 
                     remainder == n - 90;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 10)
    {
        remainder -= 10;
    }

    /*@
        loop invariant 10 <= n <= 99;
        loop invariant -10 <= remainder < 10;
        loop invariant remainder == n - 10 * (n / 10) || remainder == n - 10 * (n / 10) + 10;
        loop assigns remainder;
        loop variant -remainder;
    */
    while (remainder < 0)
    {
        remainder += 10;
    }
    mod_10 = remainder;

    // Manual division operation: n / 10
    div_result = 0;
    temp_n = n;
    /*@
        loop invariant 10 <= n <= 99;
        loop invariant 0 <= temp_n <= n;
        loop invariant div_result <= n / 10;
        loop invariant temp_n == n - 10 * div_result;
        loop assigns temp_n, div_result;
        loop variant temp_n;
    */
    while (temp_n >= 10)
    {
        temp_n -= 10;
        div_result += 1;
    }

    /*@
        loop invariant 10 <= n <= 99;
        loop invariant -10 <= temp_n < 10;
        loop invariant div_result <= n / 10;
        loop invariant temp_n == n - 10 * div_result;
        loop assigns temp_n, div_result;
        loop variant -temp_n;
    */
    while (temp_n < 0)
    {
        temp_n += 10;
        div_result -= 1;
    }

    //@ assert ((mod_10) == (n) % 10);
    //@ assert ((div_result) == (n) / 10);
    condition = (div_result == 9) || (mod_10 == 9);
    return condition;
}
