#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_params(integer N, integer X) =
      1 <= N && N <= 100 &&
      1 <= X && X <= 10000;
*/

/*@ predicate valid_array(integer N, long *L) =
      \forall integer i; 0 <= i < N ==> 1 <= L[i] && L[i] <= 100;
*/

/*@ lemma count_bound:
      \forall integer N, integer i, integer count;
      0 <= i <= N && 0 <= count <= i ==> count <= N;
*/

/*@ lemma sum_bound:
      \forall integer N, integer X, long *L, integer d, integer i;
      valid_params(N, X) && valid_array(N, L) &&
      0 <= i <= N && 0 <= d && d <= X + 100 * i ==>
      d <= X + 100 * N;
*/

/*@ requires valid_params(N, X);
    requires N >= 1;
    requires \valid(L + (0 .. N-1));
    requires valid_array(N, L);
    ensures \result >= 0;
    ensures \result <= N;
*/
long func(long N, long X, const long *L) {
    long d;
    long count;
    long i;
    
    d = 0;
    count = 0;
    i = 0;
    
    /*@ loop invariant 0 <= i <= N;
        loop invariant d >= 0;
        loop invariant d <= X + 100 * N;
        loop invariant count >= 0;
        loop invariant count <= i;
        loop assigns d, count, i;
    */
    while (d <= X && i < N) {
        //@ assert count <= N;
        count = count + 1;
        d = d + L[i];
        i = i + 1;
    }
    
    //@ assert count <= N;
    return count;
}
