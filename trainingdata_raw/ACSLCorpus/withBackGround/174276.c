#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_v(size_t *v, integer N, integer i) =
      v[i] >= 1 && v[i] <= 1000000000;
*/

/*@ predicate is_valid_w(size_t *w, integer M, integer j) =
      w[j] >= 1 && w[j] <= 1000000000;
*/

/*@ predicate distinct_v(size_t *v, integer N, integer i, integer j) =
      v[i] != v[j];
*/

/*@ predicate distinct_w(size_t *w, integer M, integer i, integer j) =
      w[i] != w[j];
*/

/*@ lemma ans_bounds:
      \forall integer N, M, ans;
      0 <= N <= 100000 && 0 <= M <= 100000 && 0 <= ans <= N + M ==>
      0 <= N + M - ans <= N + M;
*/

/*@
  requires \valid(v+(0..N-1)) && \valid(w+(0..M-1));
  requires N <= 100000 && M <= 100000;
  requires \forall integer i; 0 <= i < N ==> is_valid_v(v, N, i);
  requires \forall integer j; 0 <= j < M ==> is_valid_w(w, M, j);
  requires \forall integer i, j; 0 <= i < j < N ==> distinct_v(v, N, i, j);
  requires \forall integer i, j; 0 <= i < j < M ==> distinct_w(w, M, i, j);
  ensures \result >= 0 && \result <= N + M;
  assigns \nothing;
*/
size_t func(size_t *v, size_t N, size_t *w, size_t M) {
    size_t ans = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= N;
      loop invariant 0 <= ans <= i;
      loop assigns i, ans;
      loop variant N - i;
    */
    while (i < N) {
        bool found = false;
        size_t j = 0;
        
        /*@
          loop invariant 0 <= j <= M;
          loop invariant found == false;
          loop assigns j, found;
          loop variant M - j;
        */
        while (j < M) {
            //@ assert j < M ==> is_valid_w(w, M, j);
            if (v[i] == w[j]) {
                found = true;
                break;
            }
            j++;
        }
        
        if (found) {
            ans++;
        }
        i++;
    }
    
    size_t result = N + M - ans;
    //@ assert result >= 0 && result <= N + M;
    return result;
}
