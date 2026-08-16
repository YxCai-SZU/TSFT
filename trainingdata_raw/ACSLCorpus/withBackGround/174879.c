#include <stddef.h>
#include <stdint.h>

/*@ predicate is_valid_params(size_t n, int64_t k, int64_t *h) =
      n >= 1 && n <= 100000 &&
      k >= 1 && k <= 500 &&
      \valid(h + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> h[i] >= 1 && h[i] <= 500;
*/

/*@ predicate loop_invariant(size_t index, size_t n, int32_t num, int64_t *h) =
      index <= n &&
      num >= 0 &&
      num <= (int32_t)index &&
      \valid(h + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> h[i] >= 1 && h[i] <= 500;
*/

/*@ lemma params_preserved:
      \forall size_t n, int64_t k, int64_t *h, size_t index;
      is_valid_params(n, k, h) && index > 0 ==>
      n >= 1 && n <= 100000 && k >= 1 && k <= 500;
*/

/*@
  requires is_valid_params(n, k, h);
  ensures \result >= 0 && \result <= (int32_t)n;
  assigns \nothing;
*/
int32_t func(size_t n, int64_t k, int64_t *h)
{
    int32_t num = 0;
    size_t index = 0;

    /*@
      loop invariant loop_invariant(index, n, num, h);
      loop assigns num, index;
      loop variant n - index;
    */
    while (index < n)
    {
        //@ assert index < n;
        if (h[index] >= k)
        {
            num += 1;
        }
        index += 1;
    }
    return num;
}
