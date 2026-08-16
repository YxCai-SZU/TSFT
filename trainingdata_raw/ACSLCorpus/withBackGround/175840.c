#include <stdbool.h>

/*@
    predicate is_multiple_of_3(integer n) = n % 3 == 0;
    predicate is_multiple_of_5(integer n) = n % 5 == 0;
    predicate is_multiple_of_3_or_5(integer n) = is_multiple_of_3(n) || is_multiple_of_5(n);
*/

/*@
    requires 1 <= n && n <= 100;
    ensures \result == true <==> (n % 3 == 0 || n % 5 == 0);
    assigns \nothing;
*/
bool func(unsigned int n)
{
    bool ok = false;
    unsigned int temp_n = n;
    unsigned int count3 = 0;

    /*@
        loop invariant 1 <= n && n <= 100;
        loop invariant 0 <= temp_n && temp_n <= n;
        loop invariant count3 <= n / 3;
        loop invariant temp_n == n - 3 * count3;
        loop assigns temp_n, count3;
        loop variant temp_n;
    */
    while (temp_n >= 3)
    {
        temp_n -= 3;
        count3 += 1;
    }

    //@ assert temp_n == n % 3;
    if (temp_n == 0)
    {
        ok = true;
    }

    temp_n = n;
    unsigned int count5 = 0;

    /*@
        loop invariant 1 <= n && n <= 100;
        loop invariant 0 <= temp_n && temp_n <= n;
        loop invariant count5 <= n / 5;
        loop invariant temp_n == n - 5 * count5;
        loop assigns temp_n, count5;
        loop variant temp_n;
    */
    while (temp_n >= 5)
    {
        temp_n -= 5;
        count5 += 1;
    }

    //@ assert temp_n == n % 5;
    if (temp_n == 0)
    {
        ok = true;
    }

    return ok;
}

int main()
{
    return 0;
}
