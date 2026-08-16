#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer m) =
        1 <= n <= 100 && 0 <= m <= n * n;

    logic integer diff(integer n, integer m) = n * n - m;

    lemma n_square_bound: \forall integer n; 1 <= n <= 100 ==> n * n <= 10000;
    lemma diff_nonnegative: \forall integer n, m; valid_params(n, m) ==> diff(n, m) >= 0;
    lemma diff_bound: \forall integer n, m; valid_params(n, m) ==> diff(n, m) <= 10000;
*/

/*@
    requires valid_params(n, m);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (n * n - m) % 2 == 0;
    ensures \result == 0 ==> (n * n - m) % 2 != 0;
*/
int func(unsigned int n, unsigned int m)
{
    // Variable declarations at scope top
    unsigned int a;
    bool is_even;
    unsigned int temp;

    //@ assert n * n <= 10000;
    //@ assert n * n >= m;
    //@ assert n * n - m <= 10000;

    a = n * n - m;
    is_even = true;
    temp = a;

    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= m <= n * n;
        loop invariant 0 <= temp <= a;
        loop invariant a == n * n - m;
        loop invariant temp % 2 == a % 2;
        loop invariant n * n <= 10000;
        loop assigns temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
    }

    if (temp == 1)
    {
        is_even = false;
    }

    if (is_even)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
