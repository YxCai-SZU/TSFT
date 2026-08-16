#include <stdbool.h>

/*@
  requires 1 <= n <= 100;
  requires 1 <= m <= 100;
  requires \valid(days + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> 1 <= (days)[i] <= (m));
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
int func(int n, int m, int *days) {
    int count = 0;
    int index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant 0 <= count <= index;
      loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (days)[i] <= (m));
      loop invariant index <= n;
      loop assigns count, index;
    */
    while (index < n) {
        //@ assert 0 <= index < n;
        if (days[index] >= m) {
            count = count + 1;
        }
        index = index + 1;
    }
    return count;
}
