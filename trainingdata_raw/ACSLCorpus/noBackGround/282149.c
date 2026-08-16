#include <stdbool.h>
#include <limits.h>

/*@
    requires n > 0 && n <= 100;
    requires \valid(a + (0 .. n-1));
    requires ((n) > 0 && (n) <= 100 &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= 100);
    ensures \result >= 0;
*/
int func(int n, int *a) {
    int ans = INT_MAX;
    int i = 0;
    
    //@ ghost int old_n = n;
    //@ ghost int *old_a = a;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant n == old_n;
        loop invariant ((n) > 0 && (n) <= 100 &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= 100);
        loop invariant ans >= 0;
        loop invariant \forall integer k; 0 <= k < i ==> 1 <= a[k] && a[k] <= 100;
        loop assigns i, ans;
        loop variant n - i;
    */
    while (i < n) {
        int a_i = a[i];
        int is_even = (a_i & 1) == 0 ? 1 : 0;
        int tmp = 0;
        int j = 0;
        
        /*@
            loop invariant 0 <= j <= a_i;
            loop invariant tmp >= 0;
            loop invariant n == old_n;
            loop invariant ((n) > 0 && (n) <= 100 &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= 100);
            loop invariant tmp == ((is_even) == 1 ? (j) : 2 * (j));
            loop assigns j, tmp;
            loop variant a_i - j;
        */
        while (j < a_i) {
            if (is_even == 1) {
                tmp += 1;
            } else {
                tmp += 2;
            }
            j += 1;
        }
        
        //@ assert tmp >= 0;
        
        if (ans < tmp) {
            // ans remains unchanged
        } else {
            ans = tmp;
        }
        
        i += 1;
    }
    
    return ans;
}
