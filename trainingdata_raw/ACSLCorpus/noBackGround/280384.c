#include <stddef.h>

/*@
  requires ((N) > 0 && (K) > 0 &&
      \valid((H) + (0 .. (N)-1)) &&
      \forall size_t j; 0 <= j < (N) ==> (H)[j] > 0);
  assigns \nothing;
  ensures 0 <= \result <= N;
*/
size_t func(size_t N, size_t K, const size_t H[]) {
    size_t count = 0;
    size_t i = 0;

    /*@
      loop invariant 0 <= i <= N;
      loop invariant 0 <= count <= i;
      loop assigns i, count;
      loop variant N - i;
    */
    while (i < N) {
        //@ assert i < N;
        if (H[i] >= K) {
            count += 1;
        }
        i += 1;
    }

    //@ assert count <= N;
    return count;
}
