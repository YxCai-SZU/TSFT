#include <stdbool.h>
#include <stdint.h>

/*@
  requires 1 <= N <= 100;
  requires \valid(a + (0..N-1));
  requires \forall integer i; 0 <= i < N ==> 1 <= a[i] <= 100;
  ensures 0 <= \result <= N;
  assigns \nothing;
*/
int func(int64_t N, const int64_t* a) {
    int count = 0;
    int64_t i = 0;
    
    /*@
      loop invariant 0 <= i <= N;
      loop invariant 0 <= count <= i;
      loop invariant count <= N;
      loop assigns i, count;
    */
    while (i < N) {
        if (is_even(i)) {
            count += 1;
        }
        i += 1;
    }
    return count;
}
