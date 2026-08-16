#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) >= 1 && (n) <= 200000 &&
        \valid((p) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (p)[i] >= 1 && (p)[i] <= (n) &&
        \forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(int n, int *p) {
    int ans = 0;
    int min = p[0];
    int i = 1;
    
    /*@
        loop invariant 1 <= i <= n;
        loop invariant 0 <= ans <= i;
        loop invariant \forall integer k; 0 <= k < i ==> p[k] >= 1 && p[k] <= n;
        loop invariant \forall integer k, j; 0 <= k < j < i ==> p[k] != p[j];
        loop invariant ((n) >= 1 && (n) <= 200000 &&
        \valid((p) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (p)[i] >= 1 && (p)[i] <= (n) &&
        \forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
        loop invariant min == p[0] || (\exists integer k; 0 <= k < i && p[k] == min);
        loop assigns i, ans, min;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert i >= 1 && i < n;
        
        if (min >= p[i]) {
            //@ assert p[i] >= 1 && p[i] <= n;
            ans += 1;
            min = p[i];
        }
        
        i += 1;
    }
    
    //@ assert ans >= 0 && ans <= n;
    return ans;
}
