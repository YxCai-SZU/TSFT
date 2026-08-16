#include <stddef.h>

/*@
    predicate is_valid_input(integer n, integer m) =
        1 <= n && 1 <= m && n <= 1000000000000 && m <= 1000000000000;

    logic integer min_val(integer n, integer m) =
        n < m ? n : m;

    logic integer compute_result(integer n, integer m) =
        n == m ? min_val(n, m) * 2 - 1 :
        (n == m - 1 || m == n - 1) ? min_val(n, m) * 2 :
        min_val(n, m) * 2 + 1;

    lemma result_bounds:
        \forall integer n, m;
            is_valid_input(n, m) ==> 0 <= compute_result(n, m) && compute_result(n, m) <= n + m;
*/

/*@
    requires is_valid_input(n, m);
    ensures \result >= 0;
    ensures \result <= n + m;
    assigns \nothing;
*/
size_t func(size_t n, size_t m) {
    size_t min_val;
    size_t result;

    //@ assert is_valid_input(n, m);
    
    if (n < m) {
        min_val = n;
    } else {
        min_val = m;
    }
    
    min_val = min_val * 2;
    
    if (n == m) {
        //@ assert min_val - 1 >= 0;
        result = min_val - 1;
    } else if (n == m - 1 || m == n - 1) {
        //@ assert min_val >= 0;
        result = min_val;
    } else {
        //@ assert min_val + 1 >= 0;
        result = min_val + 1;
    }
    
    //@ assert result >= 0;
    //@ assert result <= n + m;
    return result;
}
