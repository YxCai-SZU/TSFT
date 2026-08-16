#include <stdint.h>

/*@
    predicate is_valid_input(integer n, integer m) =
        1 <= n <= 1000000000000 && 1 <= m <= 1000000000000;
    
    logic integer min_val(integer n, integer m) =
        n < m ? n : m;
    
    lemma result_bound:
        \forall integer n, m, min_val, n_rem, m_rem, min_rem, result;
        is_valid_input(n, m) ==>
        min_val == (n < m ? n : m) ==>
        n_rem == n - min_val ==>
        m_rem == m - min_val ==>
        min_rem == (n_rem > 0 && m_rem > 0 ? (n_rem < m_rem ? n_rem : m_rem) : 0) ==>
        result == min_val + min_rem ==>
        result <= n + m;
*/

/*@
    requires is_valid_input(n, m);
    ensures \result <= n + m;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m) {
    uint64_t min_val;
    uint64_t result;
    uint64_t n_remaining;
    uint64_t m_remaining;
    uint64_t min_remaining;
    
    //@ assert is_valid_input(n, m);
    
    if (n < m) {
        min_val = n;
    } else {
        min_val = m;
    }
    //@ assert min_val == (n < m ? n : m);
    
    result = min_val;
    n_remaining = n - min_val;
    m_remaining = m - min_val;
    //@ assert n_remaining == n - min_val && m_remaining == m - min_val;
    
    if (n_remaining > 0 && m_remaining > 0) {
        if (n_remaining < m_remaining) {
            min_remaining = n_remaining;
        } else {
            min_remaining = m_remaining;
        }
        //@ assert min_remaining == (n_remaining < m_remaining ? n_remaining : m_remaining);
        result += min_remaining;
    } else {
        min_remaining = 0;
        //@ assert min_remaining == 0;
    }
    //@ assert result == min_val + min_remaining;
    
    //@ assert result <= n + m;
    return result;
}
