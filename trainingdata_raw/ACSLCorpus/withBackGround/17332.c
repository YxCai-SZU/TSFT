#include <stddef.h>
#include <stdint.h>

/*@ predicate valid_range(int64_t* arr, size_t len) =
      len >= 3 && len <= 100000 &&
      \forall size_t i; 0 <= i < len ==> arr[i] >= 1 && arr[i] <= 1000000000;
*/

/*@ predicate loop_invariant(int64_t* h, size_t n, size_t i, size_t cur_l, size_t max_l) =
      1 <= i && i <= n &&
      cur_l >= 0 && max_l >= 0 &&
      cur_l <= i - 1 && max_l <= i - 1 &&
      \valid(h + (0..n-1));
*/

/*@ lemma max_l_nonnegative:
      \forall int64_t* h; \forall size_t n, i, cur_l, max_l;
      loop_invariant(h, n, i, cur_l, max_l) ==> max_l >= 0;
*/

/*@
  requires \valid(h + (0..n-1));
  requires valid_range(h, n);
  ensures \result >= 0;
*/
int64_t func(size_t n, int64_t* h)
{
    int64_t cur_h;
    size_t cur_l;
    size_t max_l;
    size_t i;
    int64_t n_h;
    size_t tmp_max;

    cur_h = h[0];
    cur_l = 0;
    max_l = 0;
    i = 1;

    /*@ loop invariant loop_invariant(h, n, i, cur_l, max_l);
        loop assigns cur_h, cur_l, max_l, i, n_h, tmp_max;
        loop variant n - i;
    */
    while (i < n) {
        n_h = h[i];
        if (n_h <= cur_h) {
            cur_l = cur_l + 1;
        } else {
            tmp_max = (cur_l > max_l) ? cur_l : max_l;
            max_l = tmp_max;
            cur_l = 0;
        }
        cur_h = n_h;
        i = i + 1;
    }

    tmp_max = (cur_l > max_l) ? cur_l : max_l;
    max_l = tmp_max;
    //@ assert max_l >= 0;
    return (int64_t)max_l;
}
