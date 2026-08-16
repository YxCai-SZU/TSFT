#include <limits.h>
#include <stdbool.h>

/*@
    requires 2 <= n <= 100;
    requires 1 <= w <= 100;
    requires \valid(wv + (0 .. n-1));
    requires ((n) >= 2 && (n) <= 100 &&
        \forall integer i; 0 <= i < (n) ==> (wv)[i] >= 1 && (wv)[i] <= 100);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int n, int w, int *wv) {
    int ans = INT_MAX;
    int t = 1;
    
    /*@
        loop invariant 1 <= t <= n;
        loop invariant ans >= 0;
        loop invariant ans <= INT_MAX;
        loop invariant ((n) >= 2 && (n) <= 100 &&
        \forall integer i; 0 <= i < (n) ==> (wv)[i] >= 1 && (wv)[i] <= 100);
        loop invariant 1 <= w <= 100;
        loop invariant 2 <= n <= 100;
        loop assigns ans, t;
        loop variant n - t;
    */
    while (t < n) {
        int s1 = 0;
        int i = 0;
        
        /*@
            loop invariant 0 <= i <= t;
            loop invariant s1 >= 0;
            loop invariant s1 <= i * 100;
            loop invariant ((n) >= 2 && (n) <= 100 &&
        \forall integer i; 0 <= i < (n) ==> (wv)[i] >= 1 && (wv)[i] <= 100);
            loop assigns s1, i;
            loop variant t - i;
        */
        while (i < t) {
            //@ assert i < n;
            s1 += wv[i];
            i++;
        }
        
        int s2 = 0;
        i = t;
        
        /*@
            loop invariant t <= i <= n;
            loop invariant s2 >= 0;
            loop invariant s2 <= (i - t) * 100;
            loop invariant ((n) >= 2 && (n) <= 100 &&
        \forall integer i; 0 <= i < (n) ==> (wv)[i] >= 1 && (wv)[i] <= 100);
            loop assigns s2, i;
            loop variant n - i;
        */
        while (i < n) {
            //@ assert i < n;
            s2 += wv[i];
            i++;
        }
        
        int diff = s1 >= s2 ? s1 - s2 : s2 - s1;
        if (diff < ans) {
            ans = diff;
        }
        t++;
    }
    
    //@ assert ans >= 0;
    return ans;
}
