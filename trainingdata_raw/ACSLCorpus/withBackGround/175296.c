#include <limits.h>

/*@
    predicate in_range(integer n) = 1 <= n <= 10000;

    logic integer mod1000(integer x) = x % 1000;

    lemma mod_loop1:
        \forall integer n, m;
            in_range(n) && m >= 1000 && mod1000(m) == mod1000(n) ==>
            mod1000(m - 1000) == mod1000(n);

    lemma mod_loop2:
        \forall integer n, m;
            in_range(n) && m < 0 && mod1000(m) == mod1000(n) ==>
            mod1000(m + 1000) == mod1000(n);
*/

/*@
    requires in_range(n);
    ensures (n % 1000 == 0) ==> \result == 0;
    ensures (n % 1000 != 0) ==> \result == 1000 - n % 1000;
    assigns \nothing;
*/
int func(int n)
{
    int m;
    m = n;

    /*@
        loop invariant in_range(n);
        loop invariant 0 <= m <= n;
        loop invariant m % 1000 == n % 1000;
        loop assigns m;
        loop variant m;
    */
    while (m >= 1000)
    {
        //@ assert m % 1000 == n % 1000;
        m -= 1000;
    }

    /*@
        loop invariant in_range(n);
        loop invariant m < 1000;
        loop invariant m % 1000 == n % 1000;
        loop assigns m;
        loop variant -m;
    */
    while (m < 0)
    {
        //@ assert m % 1000 == n % 1000;
        m += 1000;
    }

    int res;
    if (m == 0)
    {
        res = 0;
    }
    else
    {
        res = 1000 - m;
    }

    //@ assert (n % 1000 == 0) ==> (res == 0);
    //@ assert (n % 1000 != 0) ==> (res == 1000 - n % 1000);
    return res;
}
