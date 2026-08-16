#include <stdbool.h>
#include <stddef.h>

/*@ requires n > 0 && n <= 100;
    requires \valid(a + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (0 <= ((a)[i]) <= 100));
    ensures \result >= 0;
    ensures \result <= n;
*/
int func(int n, int *a) {
    int ans = 0;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant ans >= 0;
        loop invariant ans <= i;
        loop invariant (\forall integer i; 0 <= i < (n) ==> (0 <= ((a)[i]) <= 100));
        loop assigns i, ans;
    */
    while (i < n) {
        //@ assert (0 <= (i) < (n));
        //@ assert (0 <= (a[i]) <= 100);
        
        if ((a[i] & 1) == 0) {
            ans += 1;
        }
        i += 1;
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= n;
    return ans;
}
