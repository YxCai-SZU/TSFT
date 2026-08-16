#include <stddef.h>
#include <stdbool.h>

/*@
    requires 1 <= n <= 100000;
    requires \valid(a + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> 1 <= a[i] <= n;
    requires \forall integer i, j; 0 <= i < j < n ==> a[i] != a[j];
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int func(size_t n, const int *a) {
    int cnt = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= cnt <= i;
        loop invariant (1 <= (n) <= 100000 &&
        \valid((a) + (0 .. (n)-1)) &&
        (\forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= (n)) &&
        (\forall integer i, j; 0 <= i < j < (n) ==> (a)[i] != (a)[j]));
        loop assigns i, cnt;
        loop variant n - i;
    */
    while (i < n) {
        int a_i = a[i];
        //@ assert 0 <= i < n;
        //@ assert 1 <= a_i <= n;
        if ((int)i + 1 == a_i) {
            cnt += 1;
        }
        i += 1;
    }
    int ans = cnt;
    //@ assert 0 <= ans <= n;
    return ans;
}
