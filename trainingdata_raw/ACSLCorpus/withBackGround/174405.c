#include <limits.h>

/*@
    predicate is_valid_range(integer n) = 1 <= n <= 100;

    logic integer manual_div(integer n) = n >= 0 ? n / 2 : n / 2;
    logic integer manual_mod(integer n) = n >= 0 ? n % 2 : n % 2;
    logic integer expected_result(integer n) = manual_div(n) + manual_mod(n);

    lemma div_mod_relation: \forall integer n; n == 2 * manual_div(n) + manual_mod(n);
    lemma mod_range_nonneg: \forall integer n; n >= 0 ==> 0 <= manual_mod(n) < 2;
    lemma mod_range_neg: \forall integer n; n < 0 ==> -2 < manual_mod(n) <= 0;
*/

/*@
    requires is_valid_range(n);
    ensures \result == expected_result(n);
    assigns \nothing;
*/
int func(int n)
{
    int half;
    int remainder;
    int count;
    int temp_n;

    // Compute half = n / 2
    if (n >= 0)
    {
        count = 0;
        temp_n = n;
        /*@
            loop invariant 0 <= temp_n <= n;
            loop invariant 0 <= count <= n / 2;
            loop invariant temp_n == n - 2 * count;
            loop assigns temp_n, count;
            loop variant temp_n;
        */
        while (temp_n >= 2)
        {
            temp_n -= 2;
            count += 1;
        }
        half = count;
    }
    else
    {
        count = 0;
        temp_n = n;
        /*@
            loop invariant n <= temp_n <= 0;
            loop invariant count <= n / 2;
            loop invariant temp_n == n - 2 * count;
            loop assigns temp_n, count;
            loop variant -temp_n;
        */
        while (temp_n <= -2)
        {
            temp_n += 2;
            count -= 1;
        }
        half = count;
    }

    // Compute remainder = n % 2
    if (n >= 0)
    {
        temp_n = n;
        /*@
            loop invariant 0 <= temp_n <= n;
            loop invariant temp_n == n - 2 * ((n - temp_n) / 2);
            loop assigns temp_n;
            loop variant temp_n;
        */
        while (temp_n >= 2)
        {
            temp_n -= 2;
        }
        remainder = temp_n;
    }
    else
    {
        temp_n = n;
        /*@
            loop invariant n <= temp_n <= 0;
            loop invariant temp_n == n - 2 * ((n - temp_n) / 2);
            loop assigns temp_n;
            loop variant -temp_n;
        */
        while (temp_n <= -2)
        {
            temp_n += 2;
        }
        remainder = temp_n;
    }

    //@ assert half == manual_div(n);
    //@ assert remainder == manual_mod(n);
    //@ assert half + remainder == expected_result(n);
    return half + remainder;
}
