#include <stdbool.h>
#include <stddef.h>

/*@
  requires N >= 1 && N <= 20;
  requires \valid(H + (0 .. N-1));
  requires ((N) >= 1 && (N) <= 20 &&
      \forall integer i; 0 <= i < (N) ==> (H)[i] >= 1 && (H)[i] <= 100);
  assigns \nothing;
  ensures \result >= 0 && \result <= N;
  ensures \forall integer n; 0 <= n < N ==> H[n] >= 1 && H[n] <= 100;
*/
int func(int N, int *H) {
    int max_value = 0;
    int ans = 0;
    size_t index = 0;
    
    //@ ghost int *ghost_H = H;
    //@ ghost int ghost_N = N;
    
    /*@
      loop invariant ((index) >= 0 && (index) <= (N) &&
      (ans) >= 0 && (ans) <= (index) &&
      (max_value) <= 100 &&
      ((index) == 0 || (max_value) >= 1) &&
      \forall integer k; 0 <= k < (index) ==> (max_value) >= (H)[k]);
      loop invariant H == ghost_H && N == ghost_N;
      loop invariant ((N) >= 1 && (N) <= 20 &&
      \forall integer i; 0 <= i < (N) ==> (H)[i] >= 1 && (H)[i] <= 100);
      loop assigns max_value, ans, index;
      loop variant N - index;
    */
    while (index < (size_t)N) {
        int Hn = H[index];
        
        //@ assert 0 <= index && index < N;
        //@ assert Hn >= 1 && Hn <= 100;
        
        if (max_value <= Hn) {
            //@ assert max_value <= Hn;
            ans += 1;
            max_value = Hn;
            //@ assert ans >= 1;
            //@ assert max_value >= 1;
        }
        
        //@ assert \forall integer k; 0 <= k < index ==> max_value >= H[k];
        index += 1;
        //@ assert index <= N;
    }
    
    //@ assert ans >= 0 && ans <= N;
    return ans;
}
