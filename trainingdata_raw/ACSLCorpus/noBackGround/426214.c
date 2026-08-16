#include <stdbool.h>
#include <stddef.h>

/*@ requires 1 <= n <= 100;
    requires \valid(a_vec + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (a_vec)[i] <= 100);
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
int func(int n, int *a_vec) {
    int ans = 0;
    int i = 0;
    
    /*@ loop invariant (0 <= (i) <= (n) &&
      0 <= (ans) <= (i) &&
      (\forall integer i; 0 <= i < ((n)) ==> 1 <= ((a_vec))[i] <= 100) &&
      1 <= (n) <= 100);
        loop assigns ans, i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if ((i & 1) == 0) {
            //@ assert 0 <= i < n;
            if ((a_vec[i] & 1) == 0) {
                ans += 1;
            }
        }
        i += 1;
    }
    return ans;
}
