#include <stdbool.h>
#include <limits.h>

/*@ requires n >= 3 && n <= 200000 && n % 2 == 1;
    requires \valid(a + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 1000000000;
    assigns \nothing;
    ensures \result >= 0;
*/
int func(int n, int *a) {
    int ans = INT_MAX;
    int i = 1;
    
    /*@ loop invariant 1 <= i <= n - 1;
        loop invariant ans >= 0;
        loop assigns i, ans;
        loop variant n - i;
    */
    while (i < n - 1) {
        int l = a[i] < a[i - 1] ? a[i - 1] - a[i] : a[i] - a[i - 1];
        int r = a[i + 1] < a[i] ? a[i] - a[i + 1] : a[i + 1] - a[i];
        int min_val = l < r ? l : r;
        
        //@ assert l >= 0;
        //@ assert r >= 0;
        //@ assert min_val >= 0;
        
        ans = ans < min_val ? ans : min_val;
        
        //@ assert ans >= 0;
        
        i++;
    }
    
    return ans;
}
