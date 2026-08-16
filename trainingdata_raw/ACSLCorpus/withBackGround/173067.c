#include <stdbool.h>
#include <stddef.h>

/*@ predicate distinct_elements(int *p, integer N) =
      \forall integer i, j; 0 <= i < j < N ==> p[i] != p[j];
*/

/*@ predicate in_range(int *p, integer N) =
      \forall integer i; 0 <= i < N ==> 1 <= p[i] <= N;
*/

/*@ lemma ans_bounds:
      \forall integer ans, integer index, integer n;
      ans >= 0 && ans <= index && ans <= n ==> ans >= 0 && ans <= n;
*/

/*@
  requires 1 <= N <= 200000;
  requires \valid(p + (0..N-1));
  requires distinct_elements(p, N);
  requires in_range(p, N);
  ensures \result >= 0;
  ensures \result <= N;
*/
int func(size_t N, const int *p) {
    int ans = 0;
    size_t n = 1;
    size_t index = 0;
    
    /*@
      loop invariant 1 <= n <= N + 1;
      loop invariant 0 <= index <= N;
      loop invariant ans >= 0;
      loop invariant ans <= index;
      loop invariant \forall integer i; 0 <= i < index ==> 1 <= p[i] <= N;
      loop invariant ans <= n;
      loop assigns ans, n, index;
    */
    while (index < N && n < N) {
        //@ assert index < N && n < N;
        if ((int)n >= p[index]) {
            //@ assert (int)n >= p[index];
            ans += 1;
            n += 1;
        }
        index += 1;
    }
    //@ assert ans >= 0 && ans <= N;
    return ans;
}
