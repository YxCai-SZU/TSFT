#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(int N, int *a) =
      1 <= N <= 100 &&
      \valid(a + (0 .. N-1)) &&
      \forall integer i; 0 <= i < N ==> (a[i] == 1 || a[i] == 2 || a[i] == 3);
*/

/*@ lemma count_bounds:
      \forall integer N, integer num, integer count;
      0 <= num <= N && 0 <= count <= num ==> 0 <= count <= N;
*/

/*@
  requires valid_array(N, a);
  ensures 0 <= \result <= N;
  assigns \nothing;
*/
int func(int N, int *a) {
    int count = 0;
    int num = 0;
    int index = 0;
    
    /*@
      loop invariant 0 <= num <= N;
      loop invariant 0 <= index <= N;
      loop invariant index == num;
      loop invariant 0 <= count <= num;
      loop invariant \forall integer i; 0 <= i < index ==> (a[i] == 1 || a[i] == 2 || a[i] == 3);
      loop invariant valid_array(N, a);
      loop assigns count, num, index;
      loop variant N - num;
    */
    while (num < N) {
        //@ assert index < N;
        int value = a[index];
        
        if (value == 2) {
            count += 1;
        } else if (value == 1) {
            if (count > 0) {
                count -= 1;
            } else {
                count += 1;
            }
        } else {
            //@ assert value == 3;
            if (count > 0) {
                count -= 1;
            }
        }
        
        //@ assert 0 <= count <= num + 1;
        num += 1;
        index += 1;
    }
    
    //@ assert 0 <= count <= N;
    return count;
}
