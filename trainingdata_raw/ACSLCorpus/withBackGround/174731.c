#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_inputs(integer a, integer b, integer c, integer k) =
      0 <= a && 0 <= b && 0 <= c &&
      1 <= k && k <= a + b + c && k <= 2000000000;
*/

/*@ predicate vector_invariant(integer a, integer b, integer c,
                               integer sum, integer k_remaining,
                               integer k, integer i) =
      i >= 0 && i <= 3 &&
      k_remaining >= 0 && k_remaining <= k &&
      sum >= 0 && sum <= k &&
      sum + k_remaining == k;
*/

/*@ lemma sum_relation:
      \forall integer sum, k_remaining, k;
      sum + k_remaining == k && sum >= 0 && k_remaining >= 0 ==>
      sum <= k && k_remaining <= k;
*/

/*@
  requires valid_inputs(a, b, c, k);
  assigns \nothing;
  ensures \result <= k;
*/
long func(long a, long b, long c, long k) {
    long k_remaining;
    long sum;
    long v[3];
    size_t i;
    
    k_remaining = k;
    sum = 0;
    i = 0;
    v[0] = a;
    v[1] = b;
    v[2] = c;
    
    /*@
      loop invariant vector_invariant(a, b, c, sum, k_remaining, k, i);
      loop invariant i <= 3;
      loop assigns i, sum, k_remaining;
      loop variant 3 - i;
    */
    while (i < 3 && k_remaining > 0) {
        long x;
        long min_val;
        
        x = v[i];
        //@ assert 0 <= x;
        
        if (x < k_remaining) {
            min_val = x;
        } else {
            min_val = k_remaining;
        }
        //@ assert 0 <= min_val <= k_remaining;
        
        sum += min_val;
        k_remaining -= min_val;
        i += 1;
        
        //@ assert sum + k_remaining == k;
    }
    
    //@ assert sum <= k;
    return sum;
}
