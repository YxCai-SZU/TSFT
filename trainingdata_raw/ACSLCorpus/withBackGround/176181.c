#include <stddef.h>
#include <stdint.h>

/*@
    predicate valid_array(int64_t *p, size_t n) =
        n >= 1 && n <= 200000 &&
        \valid(p + (0 .. n-1)) &&
        (\forall integer i; 0 <= i < n ==> p[i] >= 1 && p[i] <= (int64_t)n) &&
        (\forall integer i, j; 0 <= i < j < n ==> p[i] != p[j]);

    predicate loop_invariant(int64_t *p, size_t n, size_t index, int32_t result, int64_t p_ref) =
        1 <= index && index <= n &&
        1 <= result && result <= (int32_t)index &&
        (p_ref <= p[0] || (\exists integer k; 0 <= k < index && p_ref == p[k])) &&
        (\forall integer k; 0 <= k < index ==> p[k] >= 1 && p[k] <= (int64_t)n) &&
        (\forall integer k, j; 0 <= k < j < index ==> p[k] != p[j]);

    lemma index_bounds: \forall int64_t *p, size_t n; valid_array(p, n) ==> n >= 1 && n <= 200000;
    lemma array_length: \forall int64_t *p, size_t n; valid_array(p, n) ==> \valid(p + (0 .. n-1));
    lemma element_range: \forall int64_t *p, size_t n, integer i; valid_array(p, n) && 0 <= i < n ==> p[i] >= 1 && p[i] <= (int64_t)n;
    lemma distinct_elements: \forall int64_t *p, size_t n, integer i, j; valid_array(p, n) && 0 <= i < j < n ==> p[i] != p[j];
*/

/*@
    requires valid_array(p, n);
    assigns \nothing;
    ensures \result >= 1 && \result <= (int32_t)n;
*/
int32_t func(size_t n, int64_t *p) {
    int32_t result = 1;
    size_t index = 1;
    int64_t p_ref = p[0];
    
    /*@
        loop invariant loop_invariant(p, n, index, result, p_ref);
        loop assigns index, result, p_ref;
        loop variant n - index;
    */
    while (index < n) {
        int64_t p_current = p[index];
        
        //@ assert p_current >= 1 && p_current <= (int64_t)n;
        //@ assert index > 0;
        //@ assert index < n;
        
        if (p_current < p_ref) {
            result += 1;
            p_ref = p_current;
        }
        index += 1;
    }
    return result;
}
