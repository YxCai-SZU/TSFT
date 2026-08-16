#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((N) >= 1 && (N) <= 100 &&
      \valid((a) + (0 .. (N)-1)) &&
      \forall integer k; 0 <= k < (N) ==> (a)[k] >= 1 && (a)[k] <= 100);
  assigns \nothing;
  ensures 0 <= \result <= N;
*/
int func(int N, int *a) {
    int count = 0;
    int index = 0;
    int i = 0;
    
    /*@
      loop invariant (0 <= (i) <= (N) &&
      0 <= (count) <= (i) &&
      (index) >= 0 &&
      (index) <= (i) &&
      (((N)) >= 1 && ((N)) <= 100 &&
      \valid(((a)) + (0 .. ((N))-1)) &&
      \forall integer k; 0 <= k < ((N)) ==> ((a))[k] >= 1 && ((a))[k] <= 100));
      loop assigns i, count, index;
      loop variant N - i;
    */
    while (i < N) {
        //@ assert (0 <= (i) <= (N) &&       0 <= (count) <= (i) &&       (index) >= 0 &&       (index) <= (i) &&       (((N)) >= 1 && ((N)) <= 100 &&       \valid(((a)) + (0 .. ((N))-1)) &&       \forall integer k; 0 <= k < ((N)) ==> ((a))[k] >= 1 && ((a))[k] <= 100));
        if (i == a[index] - 1) {
            count = count + 1;
            index = index + 1;
        }
        i = i + 1;
    }
    //@ assert 0 <= count <= N;
    return count;
}
