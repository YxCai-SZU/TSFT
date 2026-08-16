#include <stdbool.h>

/*@
  requires 1 <= N <= 100;
  requires \valid(A + (0 .. N-1));
  requires ((1 <= (N) && (N) <= 100) &&
      (\forall integer i; 0 <= i < (N) ==> ((A)[i] == 0 || (A)[i] == 1)));
  ensures 0 <= \result <= N;
  assigns \nothing;
*/
int func(int N, int *A) {
    int count = 0;
    unsigned int i = 0;
    
    /*@
      loop invariant ((0 <= (i) && (i) <= (N)) &&
      (0 <= (count) && (count) <= (i)) &&
      ((1 <= ((N)) && ((N)) <= 100) &&
      (\forall integer i; 0 <= i < ((N)) ==> (((A))[i] == 0 || ((A))[i] == 1))));
      loop assigns i, count;
      loop variant N - i;
    */
    while (i < (unsigned int)N) {
        int num = A[i];
        
        //@ assert 0 <= i < N;
        
        if (((i & 1) == 0) && (num == 0)) {
            count += 1;
        }
        
        i += 1;
    }
    
    //@ assert 0 <= count <= N;
    return count;
}
