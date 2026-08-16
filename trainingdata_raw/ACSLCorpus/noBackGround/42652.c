#include <stdbool.h>
#include <stddef.h>

/*@
  requires N >= 1 && N <= 100;
  requires M >= 1 && M <= 100;
  requires ((N) >= 1 && (N) <= 100 &&
      \forall integer i; 0 <= i < (N) ==> (X_N)[i] >= 1 && (X_N)[i] <= 100);
  requires ((M) >= 1 && (M) <= 100 &&
      \forall integer i; 0 <= i < (M) ==> (A_M)[i] >= 1 && (A_M)[i] <= 100);
  assigns \nothing;
  ensures \result >= 0;
*/
int func(int N, int *X_N, int M, int *A_M) {
    int ans = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= N && index <= M;
        loop invariant ans >= 0;
        loop invariant ans <= (int)index;
        loop assigns ans, index;
        loop variant N - index;
    */
    while (index < (size_t)N && index < (size_t)M) {
        //@ assert 0 <= index < N && 0 <= index < M;
        
        if (X_N[index] == A_M[index]) {
            ans += 1;
        }
        
        index += 1;
    }
    
    return ans;
}
