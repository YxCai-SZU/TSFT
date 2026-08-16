#include <limits.h>

/*@
    predicate valid_range(integer n) = 1 <= n <= 100;

    logic integer half_plus_remainder(integer n) = n / 2 + n % 2;

    lemma count_bound: \forall integer n; valid_range(n) ==> n/2 <= 50;
*/

/*@
    requires valid_range(n);
    ensures \result == half_plus_remainder(n);
    assigns \nothing;
*/
int func(int n)
{
    int result;
    int temp_n;
    int count;
    int remainder;

    result = 0;
    temp_n = n;
    count = 0;

    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant 0 <= count <= n/2;
        loop invariant temp_n == n - 2 * count;
        loop invariant count <= 50;
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 2)
    {
        temp_n -= 2;
        count += 1;
    }

    if (temp_n == 1)
        remainder = 1;
    else
        remainder = 0;

    //@ assert count + remainder == half_plus_remainder(n);
    result = count + remainder;

    return result;
}
