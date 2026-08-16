#include <stdbool.h>
/*@
    requires ((n) >= 1 && (n) <= 100 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 100);
    ensures \result >= 0 && \result <= n;
    ensures \forall integer i; 0 <= i < n ==> 
        (i + 1 - a[i] <= 0 || \result >= 1) && 
        (i + 1 - a[i] > 0 || \result <= n);
    assigns \nothing;
*/
int func(int n, int *a) {
    int ans = 0;
    int i = 1;
    //@ assert n >= 1 && n <= 100;
    
    /*@
        loop invariant (1 <= (i) && (i) <= (n) + 1 &&
        (ans) >= 0 && (ans) <= (i) - 1 &&
        \forall integer j; 0 <= j < (i) - 1 ==> 
            (j + 1 - (a)[j] <= 0 || (ans) >= 1) && 
            (j + 1 - (a)[j] > 0 || (ans) <= (n)) &&
        (n) >= 1 && (n) <= 100);
        loop assigns i, ans;
        loop variant n + 1 - i;
    */
    while (i <= n) {
        int index = i - 1;
        //@ assert i >= 1 && i <= n + 1;
        //@ assert a[index] >= 1 && a[index] <= 100;
        
        if (i - a[index] > 0) {
            ans += 1;
        }
        i += 1;
    }
    return ans;
}
