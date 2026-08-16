#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_params(integer N, integer X) =
      1 <= N <= 100 && 1 <= X <= 10000;
*/

/*@ predicate valid_array(integer N, long *L) =
      \valid(L + (0 .. N-1)) &&
      \forall integer i; 0 <= i < N ==> 1 <= L[i] <= 100;
*/

/*@ predicate loop_invariant(size_t i, long N, long d, long X, long count, long *L) =
      0 <= i <= (size_t)N &&
      d >= 0 &&
      d <= X + 100 &&
      count >= 0 &&
      count <= (long)i &&
      (long)i <= N &&
      \forall integer j; 0 <= j < (long)i ==> 1 <= L[j] <= 100 &&
      count <= N;
*/

/*@ lemma count_bound: \forall long count, size_t i, long N;
      count <= (long)i && (long)i <= N ==> count <= N;
*/

/*@ requires valid_params(N, X);
    requires valid_array(N, L);
    ensures \result >= 0;
    ensures \result <= N;
*/
long func(long N, long X, long *L) {
    long d = 0;
    long count = 0;
    size_t i = 0;
    
    /*@ loop invariant loop_invariant(i, N, d, X, count, L);
        loop assigns d, count, i;
        loop variant N - (long)i;
    */
    while (d <= X && i < (size_t)N) {
        //@ assert count <= N;
        count += 1;
        d += L[i];
        i += 1;
        //@ assert count <= N;
    }
    return count;
}
