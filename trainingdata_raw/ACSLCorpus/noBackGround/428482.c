#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((N) >= 1 && (N) <= 100000 &&
      (K) >= 1 && (K) <= 500);
  requires (\valid((H) + (0 .. (N)-1)) &&
      \forall integer i; 0 <= i < (N) ==> (H)[i] >= 1 && (H)[i] <= 500);
  ensures \result >= 0 && \result <= N;
*/
long func(long N, long K, const long *H) {
    long count = 0;
    unsigned long index = 0;
    
    /*@
      loop invariant 0 <= index <= N;
      loop invariant 0 <= count <= index;
      loop assigns count, index;
      loop variant N - index;
    */
    while (index < (unsigned long)N) {
        //@ assert 0 <= index < N;
        if (H[index] >= K) {
            count += 1;
        }
        index += 1;
    }
    //@ assert count <= N;
    return count;
}
