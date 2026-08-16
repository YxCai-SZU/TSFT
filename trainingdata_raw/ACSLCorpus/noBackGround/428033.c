#include <limits.h>
#include <stdbool.h>

/*@ requires \valid(p+(0..n-1));
    requires ((n) > 0 && (n) <= 200000 &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] <= (n) &&
      \forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
    ensures \result >= 0;
*/
int func(int n, int *p) {
    int ans = 0;
    int m = INT_MAX;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= ans <= i;
        loop invariant m <= INT_MAX;
        loop invariant ((n) > 0 && (n) <= 200000 &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] <= (n) &&
      \forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
        loop invariant i > 0 ==> ans >= 0;
        loop assigns ans, m, i;
        loop variant n - i;
    */
    while (i < n) {
        int x = p[i];
        //@ assert 1 <= x <= n;
        ans += (x < m) ? 1 : 0;
        m = (x < m) ? x : m;
        i++;
    }
    return ans;
}
