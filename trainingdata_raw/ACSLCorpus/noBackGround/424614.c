#include <stdbool.h>
#include <stdint.h>

/*@
  requires (1 <= (N) <= 200000);
  requires \valid(A + (0..N-1));
  requires \forall integer i; 0 <= i < N ==> (1 <= (A[i]) <= 1000000000);
  ensures 0 <= \result <= N;
  assigns \nothing;
*/
int64_t func(int64_t N, const int64_t *A) {
    int64_t count = 0;
    int64_t n = 0;
    
    /*@
      loop invariant 0 <= n <= N;
      loop invariant 0 <= count <= n;
      loop invariant (count % 2) == 0 || (count % 2) == 1;
      loop assigns n, count;
    */
    while (n < N) {
        int64_t i = A[n];
        //@ assert (1 <= (i) <= 1000000000);
        
        if ((i % 2) == 1 && (count % 2) == 0) {
            //@ assert (count % 2) == 0;
            count = count + 1;
            //@ assert (count % 2) == 1;
        }
        
        n = n + 1;
        //@ assert 0 <= count <= n;
    }
    
    //@ assert 0 <= count <= N;
    return count;
}
