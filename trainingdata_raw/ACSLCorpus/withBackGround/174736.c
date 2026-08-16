#include <limits.h>

/*@
    predicate valid_n(integer n) = 1 <= n <= 10000;

    logic integer thousand_part(integer n) = 1000 * (n / 1000);
    logic integer hundred_part(integer n) = 100 * ((n % 1000) / 100);
    logic integer ten_part(integer n) = 10 * (((n % 1000) % 100) / 10);
    logic integer unit_part(integer n) = ((n % 1000) % 100) % 10;
    logic integer decomposed_sum(integer n) = 
        thousand_part(n) + hundred_part(n) + ten_part(n) + unit_part(n);

    lemma decomposition_identity: 
        \forall integer n; valid_n(n) ==> decomposed_sum(n) == n;
*/

/*@
    requires valid_n(n);
    ensures \result == decomposed_sum(n);
    ensures \result == n;
*/
int func(int n)
{
    int result = 0;
    int temp_n = n;
    int count = 0;

    //@ assert valid_n(n);
    //@ assert temp_n == n;

    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant 0 <= count <= n / 1000;
        loop invariant result == 1000 * count;
        loop invariant temp_n == n - 1000 * count;
        loop invariant valid_n(n);
        loop assigns temp_n, result, count;
        loop variant temp_n;
    */
    while (temp_n >= 1000)
    {
        temp_n -= 1000;
        result += 1000;
        count += 1;
    }

    //@ assert result == thousand_part(n);
    //@ assert temp_n == n % 1000;

    count = 0;
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant 0 <= count <= (n % 1000) / 100;
        loop invariant result == thousand_part(n) + 100 * count;
        loop invariant temp_n == n - thousand_part(n) - 100 * count;
        loop invariant valid_n(n);
        loop assigns temp_n, result, count;
        loop variant temp_n;
    */
    while (temp_n >= 100)
    {
        temp_n -= 100;
        result += 100;
        count += 1;
    }

    //@ assert result == thousand_part(n) + hundred_part(n);
    //@ assert temp_n == (n % 1000) % 100;

    count = 0;
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant 0 <= count <= ((n % 1000) % 100) / 10;
        loop invariant result == thousand_part(n) + hundred_part(n) + 10 * count;
        loop invariant temp_n == n - thousand_part(n) - hundred_part(n) - 10 * count;
        loop invariant valid_n(n);
        loop assigns temp_n, result, count;
        loop variant temp_n;
    */
    while (temp_n >= 10)
    {
        temp_n -= 10;
        result += 10;
        count += 1;
    }

    //@ assert result == thousand_part(n) + hundred_part(n) + ten_part(n);
    //@ assert temp_n == unit_part(n);

    result += temp_n;

    //@ assert result == decomposed_sum(n);
    //@ assert decomposed_sum(n) == n;

    return result;
}
