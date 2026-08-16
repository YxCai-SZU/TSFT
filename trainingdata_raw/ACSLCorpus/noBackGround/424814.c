#include <stdbool.h>
#include <stddef.h>

/*@
  requires N >= 1 && N <= 100;
  requires \valid(a + (0 .. N-1));
  requires \forall integer i; 0 <= i < N ==> a[i] >= 1 && a[i] <= 100;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result <= N;
*/
int func(size_t N, int *a) {
    int count = 0;
    size_t num = 0;
    
    /*@
      loop invariant 0 <= num <= N;
      loop invariant count >= 0;
      loop invariant count <= num;
      loop invariant \valid(a + (0 .. N-1));
      loop assigns count, num;
      loop variant N - num;
    */
    while (num < N) {
        //@ assert num < N;
        if (num % 2 == 0 && a[num] % 2 == 1) {
            //@ assert count >= 0;
            count += 1;
        }
        //@ assert count >= 0;
        num += 1;
    }
    //@ assert num == N;
    //@ assert count >= 0;
    //@ assert count <= N;
    return count;
}
