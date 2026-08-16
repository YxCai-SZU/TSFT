#include <stdbool.h>
#include <stddef.h>

/*@ requires ((k) >= 1 && (k) <= 500 &&
    (n) >= 1 && (n) <= 100000 &&
    \valid((h) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 500);
    assigns \nothing;
    ensures ((\result) >= 0 && (\result) <= (n));
    ensures (\forall integer i; 0 <= i < (n) ==> 
        ((h)[i] >= (k) ==> (\result) >= 1) || ((h)[i] < (k) ==> (\result) >= 0));
*/
int func(int k, int n, int *h) {
    int ans = 0;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= ans <= i;
        loop invariant \valid(h + (0 .. n-1));
        loop invariant \forall integer j; 0 <= j < n ==> h[j] >= 1 && h[j] <= 500;
        loop invariant (\forall integer i; 0 <= i < (i) ==> 
        ((h)[i] >= (k) ==> (ans) >= 1) || ((h)[i] < (k) ==> (ans) >= 0));
        loop invariant k >= 1 && k <= 500;
        loop invariant n >= 1 && n <= 100000;
        loop assigns i, ans;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (h[i] >= k) {
            ans += 1;
        }
        i += 1;
    }
    return ans;
}
