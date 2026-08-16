#include <stdbool.h>
#include <stddef.h>

/*@ requires n >= 2 && n <= 100000;
    requires \valid(aa + (0 .. n-1));
    requires ((n) >= 2 && (n) <= 100000 &&
      \forall integer i; 0 <= i < (n) ==> (aa)[i] >= 1 && (aa)[i] <= (n) && (aa)[i] != i + 1);
    assigns \nothing;
    ensures \result >= -1 && \result <= n;
*/
int func(size_t n, const int *aa) {
    int cnt = 0;
    size_t i = 0;
    int ans = -1;

    /*@ loop invariant 0 <= i <= n;
        loop invariant cnt >= 0;
        loop invariant cnt <= i;
        loop invariant ans >= -1;
        loop invariant ans <= n;
        loop invariant ((n) >= 2 && (n) <= 100000 &&
      \forall integer i; 0 <= i < (n) ==> (aa)[i] >= 1 && (aa)[i] <= (n) && (aa)[i] != i + 1);
        loop assigns cnt, i, ans;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert aa[i] >= 1 && aa[i] <= n && aa[i] != i + 1;
        if (aa[i] == 2 && ans == -1) {
            ans = cnt + 1;
        }
        cnt += 1;
        i += 1;
    }
    //@ assert ans >= -1 && ans <= n;
    return ans;
}
