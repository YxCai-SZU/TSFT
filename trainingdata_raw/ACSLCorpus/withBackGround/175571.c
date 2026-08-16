#include <stdint.h>

/*@
    predicate valid_range(integer n) = 2 <= n <= 100;
    
    logic integer compute_result(integer n, integer m) = (n - 1) * (m - 1);
    
    lemma result_bounds:
        \forall integer n, m; valid_range(n) && valid_range(m) ==> 1 <= compute_result(n, m) <= 9801;
*/

/*@
    requires valid_range(n) && valid_range(m);
    ensures \result == compute_result(n, m);
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t m) {
    // Variable declarations at scope top
    uint32_t n_minus_one;
    uint32_t m_minus_one;
    uint32_t result;
    
    // Precondition implies these are safe
    //@ assert 2 <= n <= 100;
    //@ assert 2 <= m <= 100;
    
    n_minus_one = n - 1;
    m_minus_one = m - 1;
    
    // Critical verification property
    //@ assert 1 <= n_minus_one <= 99;
    
    // Critical verification property  
    //@ assert 1 <= m_minus_one <= 99;
    
    result = n_minus_one * m_minus_one;
    
    // Critical verification property
    //@ assert result == compute_result(n, m);
    
    return result;
}

#ifdef TESTING
#include <assert.h>

int main() {
    // Test case 1
    uint32_t res1 = func(3, 3);
    //@ assert res1 == 4;
    assert(res1 == 4);
    
    // Test case 2
    uint32_t res2 = func(10, 10);
    //@ assert res2 == 81;
    assert(res2 == 81);
    
    return 0;
}
#endif
