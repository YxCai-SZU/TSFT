#include <stddef.h>

/*@
    predicate valid_range(integer n, integer m) =
        2 <= n && n <= 100 &&
        2 <= m && m <= 100;

    logic integer compute_result(integer n, integer m) =
        (n - 1) * (m - 1);

    lemma subtraction_bounds:
        \forall integer n, m;
        valid_range(n, m) ==>
        1 <= n - 1 && n - 1 <= 99 &&
        1 <= m - 1 && m - 1 <= 99;

    lemma product_bounds:
        \forall integer n, m;
        valid_range(n, m) ==>
        1 <= compute_result(n, m) && compute_result(n, m) <= 9801;
*/


size_t func(size_t n, size_t m)
{
    // Variable declarations at top of scope
    size_t n_minus_1;
    size_t m_minus_1;
    size_t result;

    //@ assert 2 <= n && n <= 100;
    //@ assert 2 <= m && m <= 100;

    // Proof of subtraction bounds
    //@ assert 1 <= n - 1;
    n_minus_1 = n - 1;
    //@ assert n_minus_1 <= 99;
    
    //@ assert 1 <= m - 1;
    m_minus_1 = m - 1;
    //@ assert m_minus_1 <= 99;

    // Proof of product bounds
    //@ assert n_minus_1 * m_minus_1 <= 99 * 99;
    //@ assert n_minus_1 * m_minus_1 >= 1 * 1;

    result = n_minus_1 * m_minus_1;
    //@ assert result == compute_result(n, m);
    
    return result;
}
