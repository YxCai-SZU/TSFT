#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    requires 1 <= x <= n - 1;
    requires \valid(an + (0..n-1));
    requires \valid(bn + (0..m-1));
    requires \forall integer i; 0 <= i < n ==> 1 <= an[i] <= n && an[i] != x;
    requires \forall integer j; 0 <= j < m ==> 1 <= bn[j] <= n && bn[j] != x;
    requires \forall integer i, j; 0 <= i < n && 0 <= j < m ==> an[i] != bn[j];
    ensures \result >= 0;
    ensures \result <= m;
*/
int func(int n, int m, int x, int *an, int *bn) {
    int ans = 0;
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= m;
        loop invariant 0 <= ans <= i;
        loop assigns i, ans;
        loop variant m - i;
    */
    while (i < m) {
        int v = bn[i];
        bool is_ungrouped = true;
        int j = 0;
        
        /*@
            loop invariant 0 <= j <= n;
            loop invariant is_ungrouped ==>
                (\forall integer k; 0 <= k < j ==> an[k] != v);
            loop assigns j, is_ungrouped;
            loop variant n - j;
        */
        while (j < n) {
            if (an[j] == v) {
                is_ungrouped = false;
                break;
            }
            j++;
        }
        
        if (is_ungrouped) {
            ans++;
        }
        i++;
    }
    
    int max_val;
    if (ans > (m - ans)) {
        max_val = ans;
    } else {
        max_val = m - ans;
    }
    
    //@ assert max_val >= 0;
    //@ assert max_val <= m;
    
    return max_val;
}
