#include <stdint.h>
#include <stddef.h>

/*@
  requires ((N) >= 1 && (N) <= 100000 &&
      \valid((H) + (0 .. (N)-1)) &&
      \forall integer j; 0 <= j < (N) ==> (H)[j] >= 1 && (H)[j] <= 1000000000);
  ensures \result >= 0 && \result <= (int64_t)(N-1);
  assigns \nothing;
*/
int64_t func(size_t N, int64_t *H) {
    int64_t ans = 0;
    int64_t acc = 0;
    size_t i = 0;
    
    /*@
      loop invariant (0 <= (i) <= (N)-1 &&
      0 <= (acc) <= (int64_t)(i) &&
      0 <= (ans) <= (int64_t)(i) &&
      (((N)) >= 1 && ((N)) <= 100000 &&
      \valid(((H)) + (0 .. ((N))-1)) &&
      \forall integer j; 0 <= j < ((N)) ==> ((H))[j] >= 1 && ((H))[j] <= 1000000000));
      loop invariant N - i >= 0;
      loop assigns i, acc, ans;
      loop variant N - i;
    */
    while (i < N - 1) {
        //@ assert i < N-1;
        if (H[i] >= H[i + 1]) {
            acc += 1;
        } else {
            acc = 0;
        }
        ans = (acc > ans) ? acc : ans;
        i += 1;
    }
    return ans;
}
