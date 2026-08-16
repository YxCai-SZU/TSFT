#include <stddef.h>

/*@
  requires ((N) > 0 &&
      \valid((A) + (0 .. (N)-1)) &&
      \forall integer i; 0 <= i < (N) ==> (A)[i] > 0 && (A)[i] <= 100);
  assigns \nothing;
  ensures 0 <= \result <= N;
*/
size_t func(size_t N, int *A) {
    size_t ans = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= N;
      loop invariant 0 <= ans <= i;
      loop invariant \forall integer j; 0 <= j < i ==> A[j] > 0 && A[j] <= 100;
      loop invariant ((N) > 0 &&
      \valid((A) + (0 .. (N)-1)) &&
      \forall integer i; 0 <= i < (N) ==> (A)[i] > 0 && (A)[i] <= 100);
      loop assigns ans, i;
      loop variant N - i;
    */
    while (i < N) {
        int Ai = A[i];
        
        //@ assert Ai > 0 && Ai <= 100;
        
        if ((i + 1) % 2 == 1 && Ai % 2 == 1) {
            ans += 1;
        }
        
        i += 1;
    }
    
    //@ assert 0 <= ans <= N;
    return ans;
}
