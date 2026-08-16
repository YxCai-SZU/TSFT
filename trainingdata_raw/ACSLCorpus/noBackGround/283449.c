#include <stdbool.h>
#include <stdint.h>

/*@
  requires N >= 1 && N <= 200000;
  requires \valid(A + (0 .. N-1));
  requires (\forall integer i; 0 <= i < (N) ==> (1 <= ((A)[i]) <= 1000000000));
  ensures \result >= -1;
  ensures \result >= 0 ==> \result <= N-1;
*/
int64_t func(int64_t N, int64_t* A) {
    int64_t ans = 1;
    int64_t cnt = 0;
    int64_t i = 0;
    
    /*@
      loop invariant 0 <= i <= N;
      loop invariant ans == 0 || ans == 1;
      loop invariant cnt >= 0;
      loop invariant cnt <= i;
      loop invariant (\forall integer i; 0 <= i < (N) ==> (1 <= ((A)[i]) <= 1000000000));
      loop invariant \forall integer j; 0 <= j < i ==> (1 <= (A[j]) <= 1000000000);
      loop assigns i, ans, cnt;
    */
    while (i < N) {
        int64_t a = A[i];
        
        //@ assert (1 <= (a) <= 1000000000);
        
        if (a & 1) {
            cnt = cnt + 1;
        }
        
        if (a == 1) {
            ans = 1;
        } else if ((a & (a - 1)) == 0) {
            ans = 1;
        } else {
            ans = 0;
        }
        
        i = i + 1;
    }
    
    if (ans == 0 || cnt == 0) {
        return -1;
    } else {
        return cnt - 1;
    }
}
