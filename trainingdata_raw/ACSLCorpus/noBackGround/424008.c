#include <stdbool.h>
#include <stddef.h>

/*@
  requires 1 <= N <= 200;
  requires \valid(numbers + (0 .. N-1));
  requires (\forall integer i; 0 <= i < (N) ==> 1 <= (numbers)[i] <= 1000000000);
  assigns \nothing;
  ensures 0 <= \result <= N;
*/
int func(int N, int *numbers) {
    int before = 0;
    int ans = 0;
    int now = 0;
    int index = 0;
    
    /*@
      loop invariant (0 <= (index) <= (N) &&
      0 <= (now) <= (index) &&
      0 <= (ans) <= (index) &&
      (\forall integer i; 0 <= i < ((N)) ==> 1 <= ((numbers))[i] <= 1000000000) &&
      1 <= (N) <= 200 &&
      ((index) > 0 ==> (before) == (numbers)[(index)-1]));
      loop assigns before, ans, now, index;
      loop variant N - index;
    */
    while (index < N) {
        int a = numbers[index];
        if (before >= a) {
            now += 1;
            //@ assert now >= 1;
            int old_ans = ans;
            ans = (ans > now) ? ans : now;
            //@ assert ans >= old_ans;
        } else {
            now = 0;
        }
        before = a;
        index += 1;
    }
    return ans;
}
