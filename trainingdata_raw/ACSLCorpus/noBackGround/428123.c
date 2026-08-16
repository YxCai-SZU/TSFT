#include <stddef.h>
#include <stdbool.h>

/*@
  requires N >= 3 && N <= 200000;
  requires \valid(p + (0 .. N-1));
  requires (\forall integer i, j; 0 <= i < j < (N) ==> (p)[i] != (p)[j]);
  requires (\forall integer i; 0 <= i < ((N)) ==> 1 <= (p)[i] && (p)[i] <= (N));
  assigns \nothing;
  ensures 0 <= \result <= N - 2;
*/
long func(size_t N, const long* p) {
    long ans = 0;
    size_t i = 1;
    
    /*@
      loop invariant 1 <= i <= N - 1;
      loop invariant 0 <= ans <= (long)i - 1;
      loop invariant (\forall integer i, j; 0 <= i < j < (i) ==> (p)[i] != (p)[j]);
      loop invariant (\forall integer i; 0 <= i < (i) ==> 1 <= (p)[i] && (p)[i] <= (N));
      loop invariant N >= 3 && N <= 200000;
      loop assigns ans, i;
      loop variant N - i;
    */
    while (i < N - 1) {
        //@ assert i < N;
        
        if (p[i - 1] < p[i] && p[i] < p[i + 1]) {
            ans += 1;
        }
        
        if (p[i - 1] > p[i] && p[i] > p[i + 1]) {
            ans += 1;
        }
        
        i += 1;
        //@ assert i <= N - 1;
    }
    
    return ans;
}
