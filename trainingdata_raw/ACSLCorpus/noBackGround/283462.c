#include <limits.h>

/*@
    requires (1 <= (n) <= 10000);
    ensures \result == (1000 * (((n)) / 1000) +
        500 * ((((n)) % 1000) / 500) +
        100 * (((((n)) % 1000) % 500) / 100) +
        50 * ((((((n)) % 1000) % 500) % 100) / 50) +
        10 * (((((((n)) % 1000) % 500) % 100) % 50) / 10) +
        (((((((n)) % 1000) % 500) % 100) % 50) % 10));
    assigns \nothing;
*/
int func(int n)
{
    int value;
    int temp_n;
    int count_1000;
    int count_500;
    int count_100;
    int count_50;
    int count_10;

    value = 0;
    temp_n = n;
    count_1000 = 0;

    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant temp_n >= 0;
        loop invariant count_1000 >= 0;
        loop invariant temp_n == n - 1000 * count_1000;
        loop assigns temp_n, count_1000;
        loop variant temp_n;
    */
    while (temp_n >= 1000)
    {
        temp_n -= 1000;
        count_1000 += 1;
    }
    //@ assert temp_n == n - 1000 * count_1000;
    value += count_1000 * 1000;

    count_500 = 0;
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant temp_n >= 0;
        loop invariant count_500 >= 0;
        loop invariant temp_n == n - 1000 * count_1000 - 500 * count_500;
        loop assigns temp_n, count_500;
        loop variant temp_n;
    */
    while (temp_n >= 500)
    {
        temp_n -= 500;
        count_500 += 1;
    }
    //@ assert temp_n == n - 1000 * count_1000 - 500 * count_500;
    value += count_500 * 500;

    count_100 = 0;
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant temp_n >= 0;
        loop invariant count_100 >= 0;
        loop invariant temp_n == n - 1000 * count_1000 - 500 * count_500 - 100 * count_100;
        loop assigns temp_n, count_100;
        loop variant temp_n;
    */
    while (temp_n >= 100)
    {
        temp_n -= 100;
        count_100 += 1;
    }
    //@ assert temp_n == n - 1000 * count_1000 - 500 * count_500 - 100 * count_100;
    value += count_100 * 100;

    count_50 = 0;
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant temp_n >= 0;
        loop invariant count_50 >= 0;
        loop invariant temp_n == n - 1000 * count_1000 - 500 * count_500 - 100 * count_100 - 50 * count_50;
        loop assigns temp_n, count_50;
        loop variant temp_n;
    */
    while (temp_n >= 50)
    {
        temp_n -= 50;
        count_50 += 1;
    }
    //@ assert temp_n == n - 1000 * count_1000 - 500 * count_500 - 100 * count_100 - 50 * count_50;
    value += count_50 * 50;

    count_10 = 0;
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant temp_n >= 0;
        loop invariant count_10 >= 0;
        loop invariant temp_n == n - 1000 * count_1000 - 500 * count_500 - 100 * count_100 - 50 * count_50 - 10 * count_10;
        loop assigns temp_n, count_10;
        loop variant temp_n;
    */
    while (temp_n >= 10)
    {
        temp_n -= 10;
        count_10 += 1;
    }
    //@ assert temp_n == n - 1000 * count_1000 - 500 * count_500 - 100 * count_100 - 50 * count_50 - 10 * count_10;
    value += count_10 * 10 + temp_n;

    //@ assert value == (1000 * (((n)) / 1000) +         500 * ((((n)) % 1000) / 500) +         100 * (((((n)) % 1000) % 500) / 100) +         50 * ((((((n)) % 1000) % 500) % 100) / 50) +         10 * (((((((n)) % 1000) % 500) % 100) % 50) / 10) +         (((((((n)) % 1000) % 500) % 100) % 50) % 10));
    return value;
}
