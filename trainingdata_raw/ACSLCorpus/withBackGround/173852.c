#include <stddef.h>
#include <stdint.h>

/*@ predicate valid_params(size_t n, uint64_t *v) =
      n >= 1 && n <= 200000 &&
      \valid(v + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> v[i] >= 1 && v[i] <= 1000000000;
*/

/*@ lemma r_non_negative:
      \forall size_t n, uint64_t *v, integer r, size_t p;
      valid_params(n, v) && p <= n && r >= 0 && r <= p ==> r >= 0;
*/

/*@ lemma r_bound_by_p:
      \forall size_t n, uint64_t *v, integer r, size_t p;
      valid_params(n, v) && p <= n && r >= 0 && r <= p ==> r <= p;
*/

/*@ requires valid_params(n, v);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= n;
*/
int32_t func(size_t n, uint64_t *v) {
    int32_t r = 0;
    size_t p = 0;
    
    /*@
      loop invariant 0 <= p <= n;
      loop invariant 0 <= r <= p;
      loop invariant valid_params(n, v);
      loop assigns r, p;
      loop variant n - p;
    */
    while (p < n) {
        if (p % 2 == 0 && v[p] % 2 == 1) {
            r += 1;
        }
        p += 1;
        //@ assert r <= p;
    }
    
    //@ assert r >= 0;
    //@ assert r <= n;
    return r;
}
