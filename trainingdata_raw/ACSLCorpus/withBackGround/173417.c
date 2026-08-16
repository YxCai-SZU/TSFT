#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(int *a, size_t N) =
      \forall integer i; 0 <= i < N ==> 1 <= a[i] <= 100;
*/

/*@ predicate ans_bounds(integer ans, integer i, integer N) =
      ans >= 0 && ans <= i && i <= N - 1;
*/

/*@ lemma N_bounds: \forall integer N; 2 <= N <= 100 ==> N - 1 >= 1; */

/*@
  requires 2 <= N <= 100;
  requires \valid(a + (0 .. N-1));
  requires valid_array(a, N);
  assigns \nothing;
  ensures 0 <= \result <= N - 1;
*/
int func(size_t N, int *a) {
    int ans = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= N - 1;
      loop invariant ans_bounds(ans, i, N);
      loop invariant valid_array(a, N);
      loop invariant 2 <= N <= 100;
      loop assigns ans, i;
      loop variant N - 1 - i;
    */
    while (i < N - 1) {
        int val = a[i];
        int next_val = a[i + 1];
        
        //@ assert 0 <= i < N && i + 1 < N;
        //@ assert 1 <= val <= 100 && 1 <= next_val <= 100;
        
        if ((val & 1) == 0 || (next_val & 1) == 0) {
            ans += 1;
        }
        i += 1;
        //@ assert ans_bounds(ans, i, N);
    }
    return ans;
}
