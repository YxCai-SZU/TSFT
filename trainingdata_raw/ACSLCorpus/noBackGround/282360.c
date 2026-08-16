#include <stdbool.h>
/*@
    requires (1 <= (n) && (n) <= 100000 &&
        1 <= (m) && (m) <= 100000);
    requires \valid(xs + (0 .. n-1));
    requires \valid(a + (0 .. m-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (xs)[i] && (xs)[i] <= 1000000000);
    requires (\forall integer i; 0 <= i < (m) ==> 1 <= (a)[i] && (a)[i] <= 1000000000);
    ensures \result >= -1;
    ensures \result <= n;
*/
int func(int n, int m, int *xs, int *a) {
    int ans = -1;
    int j = 0;
    int i = 0;
    /*@
        loop invariant 0 <= j <= m && j <= n;
        loop invariant 0 <= i <= j;
        loop invariant ((ans) >= -1 && (ans) <= (n));
        loop assigns ans, j, i;
        loop variant m - j;
    */
    while (j < m && j < n) {
        //@ assert 0 <= j < n && 0 <= j < m;
        if (xs[j] == a[j]) {
            if (ans == -1) {
                ans = i + 1;
                //@ assert ((ans) >= -1 && (ans) <= (n));
            }
            i += 1;
            //@ assert 0 <= i <= j+1;
        } else {
            i = 0;
            ans = -1;
            //@ assert ((ans) >= -1 && (ans) <= (n));
        }
        j += 1;
        //@ assert 0 <= j <= m && j <= n;
    }
    //@ assert ((ans) >= -1 && (ans) <= (n));
    return ans;
}
