#include <stdbool.h>
#include <stddef.h>

/*@
    requires 2 <= k <= 1000000;
    requires 2 <= n <= 200000;
    requires \valid(a + (0..n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 0 <= (a)[i] && (a)[i] < (k));
    requires (\forall integer i; 0 <= i < (n)-1 ==> (a)[i] < (a)[i+1]);
    ensures \result >= 0;
    ensures \result <= k;
*/
int func(int k, int n, int *a) {
    int dist = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= n-1;
        loop invariant dist >= 0;
        loop invariant dist <= k;
        loop invariant \forall integer j; 0 <= j < i ==> 0 <= a[j] && a[j] < k;
        loop invariant \forall integer j; 0 <= j < i-1 ==> a[j] < a[j+1];
        loop invariant 2 <= k <= 1000000;
        loop invariant 2 <= n <= 200000;
        loop invariant dist <= a[i];
        loop assigns dist, i;
        loop variant n - i;
    */
    while (i < (size_t)n - 1) {
        int next_dist = a[i] - dist;
        
        //@ assert next_dist == a[i] - dist;
        
        if (next_dist < 0) {
            dist = a[i];
        } else {
            dist += next_dist;
        }
        
        i++;
    }

    int last_dist = a[n - 1] - dist;
    int ans;
    
    if (last_dist < 0) {
        ans = k - last_dist;
    } else {
        ans = last_dist;
    }

    //@ assert ans >= 0;
    //@ assert ans <= k;
    
    return ans;
}
