#include <stdbool.h>
#include <stddef.h>

/* Original function 1: compute grid area */
/*@
    predicate valid_range(integer n, integer m) =
        2 <= n && n <= 100 &&
        2 <= m && m <= 100;

    logic integer compute_result(integer n, integer m) =
        (n - 1) * (m - 1);

    lemma bounds_lemma:
        \forall integer n, m;
        valid_range(n, m) ==>
        1 <= n - 1 && n - 1 <= 99 &&
        1 <= m - 1 && m - 1 <= 99;

    lemma multiplication_bound:
        \forall integer n, m;
        valid_range(n, m) ==>
        (n - 1) * (m - 1) <= 99 * 99;
*/

unsigned int func_area(unsigned int n, unsigned int m)
{
    unsigned int n_minus_1;
    unsigned int m_minus_1;
    unsigned int result;

    //@ assert 2 <= n && n <= 100;
    //@ assert 2 <= m && m <= 100;

    n_minus_1 = n - 1;
    //@ assert n_minus_1 == n - 1;
    
    m_minus_1 = m - 1;
    //@ assert m_minus_1 == m - 1;

    //@ assert 1 <= n_minus_1;
    //@ assert n_minus_1 <= 99;
    //@ assert 1 <= m_minus_1;
    //@ assert m_minus_1 <= 99;

    //@ assert n_minus_1 * m_minus_1 <= 99 * 99;
    
    result = n_minus_1 * m_minus_1;
    //@ assert result == (n - 1) * (m - 1);
    
    return result;
}

/* Original function 2: find first zero in valid array */
/*@ predicate is_valid_element(long long *xs, integer i) =
      xs[i] == i + 1 || xs[i] == 0;
*/

/*@ predicate exists_zero(long long *xs, integer len) =
      \exists integer j; 0 <= j < len && xs[j] == 0;
*/

/*@ predicate scanned_no_zero(long long *xs, integer i) =
      \forall integer j; 0 <= j < i ==> xs[j] != 0;
*/

/*@ lemma zero_exists_in_range:
      \forall long long *xs, integer len;
        len == 5 && exists_zero(xs, len) ==>
        \exists integer j; 0 <= j < len && xs[j] == 0;
*/

size_t func_zero(long long *xs) {
    size_t pos;
    bool found;
    size_t i;
    
    pos = 0;
    found = false;
    i = 0;
    
    while (i < 5 && !found) {
        //@ assert 0 <= i < 5;
        if (xs[i] == 0) {
            pos = i;
            found = true;
        }
        i += 1;
    }
    
    //@ assert found == true;
    //@ assert pos < 5;
    //@ assert xs[pos] == 0;
    return pos + 1;
}

/* Synthesized function: grid-based zero search scenario
 * Real-world scenario: In a 5x5 grid (like a game board or sensor grid),
 * compute the grid area and then find the first zero element in a row,
 * verifying that the position found is within the grid bounds.
 */
size_t synthesized_func(unsigned int n, unsigned int m, long long *xs) {
    unsigned int area;
    size_t position;
    
    /* Compute grid area */
    area = func_area(n, m);
    
    /* Find first zero position in the array */
    position = func_zero(xs);
    
    /* High-level property: the found position (1-indexed) is within the grid area
     * For a 5x5 grid, area = (5-1)*(5-1) = 16, and position <= 5, so position <= area
     * This represents a valid state transition: the position found is within the grid bounds
     */
    //@ assert position <= area;
    
    return position;
}
