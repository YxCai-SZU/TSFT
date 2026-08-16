#include <stdbool.h>
#include <stddef.h>

/*@ requires n > 0;
    requires \valid(a + (0..n-1));
    requires ((n) > 0 &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 100);
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
int func(int n, int *a) {
    int res = 0;
    int i = 0;
    
    /*@ loop invariant (0 <= (i) <= (n) &&
      (res) >= 0 &&
      (res) <= (i) &&
      (((n)) > 0 &&
      \forall integer i; 0 <= i < ((n)) ==> 1 <= ((a))[i] <= 100));
        loop invariant i <= n;
        loop assigns i, res;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if ((i & 1) == 0 && (a[i] & 1) == 1) {
            res += 1;
        }
        i += 1;
    }
    
    //@ assert res >= 0 && res <= n;
    return res;
}
