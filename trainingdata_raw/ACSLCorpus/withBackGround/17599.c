#include <stddef.h>

/*@ predicate valid_params(integer n, integer k) =
      n >= 1 && n <= 100000 &&
      k >= 1 && k <= 500;
*/

/*@ predicate valid_array(integer n, int *h) =
      \valid(h + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> h[i] >= 1 && h[i] <= 500;
*/

/*@ logic integer count_ge_k(integer idx, integer n, int *h, integer k) =
      idx <= 0 ? 0 :
      count_ge_k(idx-1, n, h, k) + (h[idx-1] >= k ? 1 : 0);
*/

/*@ lemma loop_invariant_maintains_count:
      \forall integer idx, integer n, int *h, integer k;
      valid_array(n, h) && 0 <= idx < n ==>
      count_ge_k(idx+1, n, h, k) == 
      count_ge_k(idx, n, h, k) + (h[idx] >= k ? 1 : 0);
*/

/*@ requires valid_params(n, k) && valid_array(n, h);
    ensures \result >= 0 && \result <= (int)n;
    assigns \nothing;
 */
int func(size_t n, int k, int *h)
{
    int res = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= res <= (int)index;
        loop invariant res == count_ge_k(index, n, h, k);
        loop assigns index, res;
     */
    while (index < n) {
        //@ assert index < n;
        if (h[index] >= k) {
            //@ assert h[index] >= k;
            res = res + 1;
        }
        index += 1;
    }
    return res;
}
