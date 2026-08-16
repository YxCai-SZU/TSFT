#include <stddef.h>

/*@ predicate valid_array(integer N, int *H) =
      N >= 1 && N <= 20 &&
      \valid(H + (0 .. N-1)) &&
      \forall integer i; 0 <= i < N ==> H[i] >= 1 && H[i] <= 100;
*/

/*@ predicate max_ge_prefix(integer idx, integer N, int *H, integer max_val) =
      idx > 0 ==> \forall integer k; 0 <= k < idx ==> max_val >= H[k];
*/

/*@ lemma count_bounds:
      \forall integer idx, integer cnt;
      1 <= cnt <= idx ==> cnt >= 1 && cnt <= idx;
*/

/*@
  requires valid_array(N, H);
  assigns \nothing;
  ensures \result >= 1;
  ensures \result <= N;
*/
int func(size_t N, int *H) {
    int max;
    size_t count;
    size_t index;
    
    max = H[0];
    count = 1;
    index = 1;
    
    /*@
      loop invariant 0 <= index <= N;
      loop invariant 1 <= N <= 20;
      loop invariant \valid(H + (0 .. N-1));
      loop invariant \forall integer j; 0 <= j < N ==> H[j] >= 1 && H[j] <= 100;
      loop invariant max_ge_prefix(index, N, H, max);
      loop invariant 1 <= count <= index;
      loop assigns max, count, index;
      loop variant N - index;
    */
    while (index < N) {
        int h = H[index];
        //@ assert h >= 1 && h <= 100;
        
        if (max <= h) {
            count += 1;
            max = h;
        }
        index += 1;
    }
    
    //@ assert count >= 1;
    //@ assert count <= N;
    return count;
}
