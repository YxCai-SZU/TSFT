#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100);
    requires \valid(a + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 100);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int func(int n, int *a) {
    int ans = 0;
    int i = 0;
    
    /*@
        loop invariant (0 <= (i) <= (n) &&
        0 <= (ans) <= (i) &&
        (1 <= ((n)) <= 100) &&
        (\forall integer i; 0 <= i < ((n)) ==> 1 <= ((a))[i] <= 100) &&
        (ans) <= (i));
        loop assigns i, ans;
        loop variant n - i;
    */
    while (i < n) {
        int value = a[i];
        
        //@ assert 0 <= i < n;
        //@ assert 1 <= value <= 100;
        
        if (((i & 1) == 0) && ((value & 1) == 1)) {
            ans += 1;
        }
        i += 1;
    }
    
    //@ assert 0 <= ans <= n;
    return ans;
}
