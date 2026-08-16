#include <stdbool.h>
#include <stdint.h>

/*@ predicate is_valid_array(integer N, int64_t *A) =
      (2 <= N && N <= 100000) &&
      \valid(A + (0 .. N-1)) &&
      \forall integer j; 0 <= j < N ==> (1 <= A[j] && A[j] <= 1000000000);
*/

/*@ lemma count_bound: \forall integer N, integer i, integer cnt;
      (2 <= N && N <= 100000) &&
      0 <= i <= N-1 &&
      0 <= cnt <= i ==>
      cnt <= N-1;
*/

/*@
  requires is_valid_array(N, A);
  ensures \result <= N-1;
  assigns \nothing;
*/
uint32_t func(int64_t N, const int64_t *A) {
    uint32_t count = 0;
    int64_t i = 0;
    
    //@ ghost int64_t N_spec = N;
    //@ ghost const int64_t *A_spec = A;
    
    /*@
      loop invariant 0 <= i <= N_spec-1;
      loop invariant count <= i;
      loop invariant is_valid_array(N_spec, A_spec);
      loop assigns i, count;
      loop variant N_spec - i;
    */
    while (i < N - 1) {
        //@ assert i < N_spec;
        if ((A[i] & 1) == 0) {
            count = count + 1;
        }
        i = i + 1;
    }
    
    //@ assert count <= N_spec-1;
    return count;
}
