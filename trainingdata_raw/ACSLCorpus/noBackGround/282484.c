#include <stdbool.h>
#include <stddef.h>

/*@
  requires N >= 1 && N <= 100;
  requires \valid(a + (0 .. N-1));
  requires \forall integer i; 0 <= i < N ==> a[i] >= 1 && a[i] <= 100;
  assigns \nothing;
  ensures \result >= 0 && \result <= N;
*/
int func(int N, int *a) {
    int count = 0;
    int num = 1;
    size_t index = 0;

    /*@
      loop invariant 1 <= num <= N + 1;
      loop invariant 0 <= index <= (size_t)N;
      loop invariant 0 <= count <= (int)index;
      loop invariant index <= (size_t)N;
      loop invariant (((integer)N) >= 1 && ((integer)N) <= 100 &&
      \valid((a) + (0 .. ((integer)N)-1)) &&
      \forall integer i; 0 <= i < ((integer)N) ==> (a)[i] >= 1 && (a)[i] <= 100);
      loop assigns count, num, index;
      loop variant (size_t)N - index;
    */
    while (num <= N && index < (size_t)N) {
        //@ assert 0 <= index < (size_t)N;
        if (a[index] == num) {
            count += 1;
            num += 1;
        }
        index += 1;
    }
    //@ assert count >= 0 && count <= N;
    return count;
}
