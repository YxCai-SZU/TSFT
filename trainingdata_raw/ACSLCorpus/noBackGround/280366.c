#include <stdbool.h>

/*@
  requires (1 <= (N) && (N) <= 100 &&
      1 <= (X) && (X) <= 10000);
  requires \valid(L + (0 .. N-1));
  requires (\forall integer j; 0 <= j < (N) ==> 1 <= (L)[j] && (L)[j] <= 100);
  ensures 0 <= \result <= N;
*/
int func(int N, int X, int *L) {
    int d = 0;
    int count = 0;
    int i = 0;
    
    /*@
      loop invariant 0 <= i <= N;
      loop invariant 0 <= d <= X + 100;
      loop invariant count == i;
      loop invariant count <= N;
      loop invariant \forall integer k; 0 <= k < i ==> d >= L[k];
      loop assigns d, count, i;
    */
    while (d <= X && i < N) {
        //@ assert 0 <= i < N;
        count += 1;
        d += L[i];
        i += 1;
    }
    
    //@ assert 0 <= count <= N;
    return count;
}
