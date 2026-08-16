#include <stdbool.h>

/*@ requires 1 <= n <= 100000;
    requires 1 <= m <= 100000;
    requires \valid(a + (0 .. n-1));
    requires \valid(b + (0 .. m-1));
    requires ((n) >= 1 && (n) <= 100000 &&
        \forall integer k; 0 <= k < (n) ==> (a)[k] >= 1 && (a)[k] <= 1000000000);
    requires ((m) >= 1 && (m) <= 100000 &&
        \forall integer k; 0 <= k < (m) ==> (b)[k] >= 1 && (b)[k] <= 1000000000);
    ensures \result >= 0;
    ensures \result <= m;
*/
int func(int n, int m, int *a, int *b) {
    int ans = 0;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= m;
        loop invariant ((ans) >= 0 && (ans) <= (i) && (i) <= (m));
        loop assigns ans, i;
        loop variant m - i;
    */
    while (i < m) {
        int j = 0;
        bool found = false;
        int old_ans = ans;
        
        /*@ loop invariant 0 <= j <= n;
            loop invariant ((old_ans) >= 0 && (old_ans) <= (i) && (i) <= (m));
            loop invariant !found ==> ans == old_ans;
            loop invariant found ==> ans == old_ans + 1;
            loop assigns j, ans, found;
            loop variant n - j;
        */
        while (j < n && !found) {
            //@ assert 0 <= i < m && 0 <= j < n;
            if (b[i] == a[j]) {
                ans += 1;
                found = true;
            }
            j += 1;
        }
        i += 1;
    }
    return ans;
}
