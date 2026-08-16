#include <stddef.h>

/*@
    predicate in_range(integer n) = 1 <= n <= 10000;

    logic integer compute_result(integer n) = 
        1000 * ((n + 999) / 1000) - n;

    lemma result_properties:
        \forall integer n; in_range(n) ==> 
            compute_result(n) >= 0 && compute_result(n) < 1000;
*/

/*@
    requires in_range(n);
    ensures \result == compute_result(n);
    ensures \result >= 0 && \result < 1000;
*/
size_t func(size_t n) {
    size_t num;
    size_t result;

    //@ assert in_range(n);
    
    num = 1000 * ((n + 999) / 1000);
    
    //@ assert num >= n;
    //@ assert num < 1000 * 10000;
    
    result = num - n;
    
    //@ assert result == compute_result(n);
    //@ assert result >= 0;
    //@ assert result < 1000;
    
    return result;
}
