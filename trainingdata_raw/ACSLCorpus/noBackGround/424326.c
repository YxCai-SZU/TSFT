#include <stddef.h>

/*@
  requires (1 <= (N) <= 100000);
  requires \valid(H + (0 .. N-1));
  requires ((1 <= ((N)) <= 100000) &&
      \forall integer i; 0 <= i < (N) ==> (1 <= ((H)[i]) <= 1000000000));
  assigns \nothing;
  ensures 0 <= \result <= N;
*/
int func(size_t N, const int *H) {
    int count = 0;
    int cur_h = 0;
    size_t idx = 0;

    /*@
      loop invariant 0 <= idx <= N;
      loop invariant 0 <= count <= idx;
      loop invariant cur_h >= 0;
      loop invariant \forall integer i; 0 <= i < idx ==> H[i] >= 0;
      loop assigns idx, count, cur_h;
      loop variant N - idx;
    */
    while (idx < N) {
        int h = H[idx];
        //@ assert 0 <= h <= 1000000000;
        if (cur_h < h) {
            //@ assert cur_h < h;
            count += 1;
            cur_h = h;
        }
        idx += 1;
    }
    //@ assert 0 <= count <= N;
    return count;
}
