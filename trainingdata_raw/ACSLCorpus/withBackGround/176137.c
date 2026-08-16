#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@ predicate is_valid_array(size_t n, int64_t *p) =
      n >= 1 && n <= 200000 &&
      \valid(p + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> p[i] >= 1 && p[i] <= n &&
      \forall integer i, j; 0 <= i < j < n ==> p[i] != p[j];
*/

/*@ predicate loop_invariant(size_t n, int64_t *p, size_t i, int count, int64_t min) =
      1 <= i && i <= n &&
      1 <= count && count <= i &&
      min >= 1 && min <= n &&
      \forall integer k; 0 <= k < i ==> p[k] >= 1 && p[k] <= n &&
      \forall integer k, j; 0 <= k < j < i ==> p[k] != p[j];
*/

/*@ lemma count_bound: \forall size_t n, i, int count, int64_t min, int64_t *p; 
      loop_invariant(n, p, i, count, min) ==> count <= n;
*/

/*@ requires is_valid_array(n, p);
    ensures \result >= 1 && \result <= n;
    assigns \nothing;
*/
int func(size_t n, int64_t *p) {
    int64_t min;
    int count;
    size_t i;
    
    //@ assert n >= 1 && n <= 200000;
    
    min = p[0];
    count = 1;
    i = 1;
    
    /*@ loop invariant loop_invariant(n, p, i, count, min);
        loop assigns i, count, min;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert i < n;
        
        if (min >= p[i]) {
            count = count + 1;
            min = p[i];
        }
        i = i + 1;
    }
    
    //@ assert count <= n;
    
    return count;
}
