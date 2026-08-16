#include <stdbool.h>

/* ACSL specifications from the first code snippet */
/*@
    predicate valid_input(integer n, integer m) =
        1 <= n <= 100 && 0 <= m <= n;

    logic integer mod2(integer x) =
        x % 2;

    lemma mod2_reduction:
        \forall integer x; x >= 0 ==> mod2(x) == (x >= 2 ? mod2(x - 2) : x);
*/

bool func1(long n, long m) {
    unsigned long n_unsigned;
    unsigned long m_unsigned;
    unsigned long n_mod_2;
    unsigned long m_mod_2;
    bool result;

    n_unsigned = (n < 0) ? (unsigned long)(-n) : (unsigned long)n;
    m_unsigned = (m < 0) ? (unsigned long)(-m) : (unsigned long)m;

    n_mod_2 = n_unsigned;
    while (n_mod_2 >= 2) {
        //@ assert n_mod_2 % 2 == (n_mod_2 - 2) % 2;
        n_mod_2 -= 2;
    }

    m_mod_2 = m_unsigned;
    while (m_mod_2 >= 2) {
        //@ assert m_mod_2 % 2 == (m_mod_2 - 2) % 2;
        m_mod_2 -= 2;
    }

    result = (n_mod_2 == m_mod_2) && (n_unsigned == m_unsigned);
    //@ assert result == (n == m);
    return result;
}

/* ACSL specifications from the second code snippet */
/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;
*/

/*@
    logic integer scaled_value(integer a) = (a * 10) / 4;
*/

/*@
    lemma arithmetic_equivalence:
        \forall integer a, b;
            valid_range(a, b) ==> (a * 5) / 2 == scaled_value(a);
*/

bool func2(unsigned int a, unsigned int b)
{
    unsigned int scaled;
    bool result;

    //@ assert valid_range(a, b);
    
    scaled = (a * 10) / 4;
    //@ assert scaled == scaled_value(a);
    
    result = scaled >= b;
    //@ assert result == (scaled_value(a) >= b);
    
    return result;
}

/* 
 * Scenario: Resource Allocation Verifier
 * In a system that manages resource allocation, we need to verify that two resource 
 * requests have the same parity (to ensure they can be paired) and that a scaled 
 * version of the first request meets a minimum threshold.
 * 
 * Data flow:
 * - Input: long n (resource request 1), long m (resource request 2), 
 *          unsigned int a (scaling factor input), unsigned int b (threshold)
 * - Process: First check if n and m have the same parity and value (func1), 
 *            then check if scaled a meets threshold b (func2)
 * - Output: true if both conditions are satisfied
 */

/*@
    predicate valid_system_input(integer n, integer m, integer a, integer b) =
        valid_input(n, m) && valid_range(a, b);
*/

bool resource_allocation_verifier(long n, long m, unsigned int a, unsigned int b)
{
    bool parity_check;
    bool threshold_check;
    bool result;

    parity_check = func1(n, m);
    
    threshold_check = func2(a, b);
    
    result = parity_check && threshold_check;
    
    //@ assert result == ((n == m) && (scaled_value(a) >= b));
    return result;
}
