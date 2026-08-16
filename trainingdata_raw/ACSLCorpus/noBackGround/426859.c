#include <stdbool.h>
#include <stddef.h>

/*@
  requires (3 <= (N) <= 20);
  requires \valid(p + (0 .. N-1));
  requires (\forall integer i; 0 <= i < (N) ==> 1 <= (p)[i] <= (N) &&
      \forall integer i, j; 0 <= i < j < (N) ==> (p)[i] != (p)[j]);
  ensures \result >= 0;
  ensures \result <= N-2;
  assigns \nothing;
*/
int func(size_t N, int *p) {
    int count = 0;
    size_t i = 1;
    
    /*@
      loop invariant 1 <= i <= N-1;
      loop invariant count >= 0;
      loop invariant count <= i-1;
      loop invariant (\forall integer i; 0 <= i < (N) ==> 1 <= (p)[i] <= (N) &&
      \forall integer i, j; 0 <= i < j < (N) ==> (p)[i] != (p)[j]);
      loop invariant (3 <= (N) <= 20);
      loop assigns i, count;
      loop variant N-1-i;
    */
    while (i < N - 1) {
        //@ assert i < N && i > 0;
        
        if ((p[i-1] < p[i] && p[i] < p[i+1]) ||
            (p[i-1] > p[i] && p[i] > p[i+1])) {
            count += 1;
        }
        i += 1;
    }
    return count;
}
