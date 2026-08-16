#include <stdbool.h>

/*@
    requires (10 <= (n) && (n) <= 99);
    ensures \result == (((n) % 10) == 9 || ((((n) / 10)) % 10) == 9);
    assigns \nothing;
*/
bool func(int n)
{
    int n_mod_10;
    int n_div_10;
    int n_div_10_mod_10;
    int count;

    // First loop: n_mod_10 = n % 10
    n_mod_10 = n;
    /*@
        loop invariant 10 <= n <= 99;
        loop invariant 0 <= n_mod_10 <= n;
        loop invariant n_mod_10 % 10 == n % 10;
        loop assigns n_mod_10;
        loop variant n_mod_10;
    */
    while (n_mod_10 >= 10)
    {
        n_mod_10 -= 10;
    }

    // Second loop: handle negative case (not needed for given range)
    /*@
        loop invariant 10 <= n <= 99;
        loop invariant n_mod_10 < 10;
        loop invariant n_mod_10 == n - 10 * (n / 10) || n_mod_10 == n - 10 * (n / 10) + 10;
        loop assigns n_mod_10;
        loop variant 10 + n_mod_10;
    */
    while (n_mod_10 < 0)
    {
        n_mod_10 += 10;
    }

    // Third loop: n_div_10 = n / 10
    n_div_10 = n;
    count = 0;
    /*@
        loop invariant 10 <= n <= 99;
        loop invariant 0 <= n_div_10 <= n;
        loop invariant 0 <= count <= n / 10;
        loop invariant n_div_10 == n - 10 * count;
        loop assigns n_div_10, count;
        loop variant n_div_10;
    */
    while (n_div_10 >= 10)
    {
        n_div_10 -= 10;
        count += 1;
    }
    n_div_10 = count;

    // Fourth loop: n_div_10_mod_10 = n_div_10 % 10
    n_div_10_mod_10 = n_div_10;
    /*@
        loop invariant 10 <= n <= 99;
        loop invariant 0 <= n_div_10_mod_10 <= n_div_10;
        loop invariant n_div_10_mod_10 % 10 == n_div_10 % 10;
        loop assigns n_div_10_mod_10;
        loop variant n_div_10_mod_10;
    */
    while (n_div_10_mod_10 >= 10)
    {
        n_div_10_mod_10 -= 10;
    }

    // Fifth loop: handle negative case (not needed for given range)
    /*@
        loop invariant 10 <= n <= 99;
        loop invariant n_div_10_mod_10 < 10;
        loop invariant n_div_10_mod_10 == n_div_10 - 10 * (n_div_10 / 10) || n_div_10_mod_10 == n_div_10 - 10 * (n_div_10 / 10) + 10;
        loop assigns n_div_10_mod_10;
        loop variant 10 + n_div_10_mod_10;
    */
    while (n_div_10_mod_10 < 0)
    {
        n_div_10_mod_10 += 10;
    }

    // Final condition check
    //@ assert n_mod_10 == n % 10;
    //@ assert n_div_10_mod_10 == (n / 10) % 10;
    if (n_mod_10 == 9 || n_div_10_mod_10 == 9)
    {
        return true;
    }
    else
    {
        return false;
    }
}
