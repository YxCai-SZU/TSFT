#include <stddef.h>

/*@
    predicate valid_params(integer n, integer m) =
        1 <= n <= 100000 && 1 <= m <= 100000;

    logic integer compute_res(integer n, integer m) =
        (2 * n < m) ? n + ((m - 2 * n) / 4) : m / 2;

    lemma res_bound: \forall integer n, m; 
        valid_params(n, m) ==> compute_res(n, m) <= n + m;
*/

/*@
    requires valid_params(n, m);
    ensures \result <= n + m;
    assigns \nothing;
*/
size_t func(size_t n, size_t m)
{
    size_t res;
    size_t i;

    //@ assert valid_params(n, m);
    
    if (2 * n < m)
    {
        res = n + ((m - 2 * n) / 4);
    }
    else
    {
        res = m / 2;
    }
    
    //@ assert res == compute_res(n, m);
    //@ assert res <= n + m;
    
    i = 0;
    /*@
        loop invariant 0 <= i <= res;
        loop invariant valid_params(n, m);
        loop assigns i;
        loop variant res - i;
    */
    while (i < res)
    {
        i = i + 1;
    }
    
    //@ assert i == res;
    return res;
}
