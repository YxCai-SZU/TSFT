#include <stddef.h>
#include <stdbool.h>

/*@
    requires n >= 1 && n <= 100;
    requires \valid_read(inputs + (0 .. n-1));
    requires ((n) >= 1 && (n) <= 100 &&
        \forall integer k; 0 <= k < (n) ==> 1 <= (inputs)[k] && (inputs)[k] <= 100);
    assigns \nothing;
    ensures \result >= 0 && \result <= n;
*/
int func(size_t n, const int inputs[]) {
    int a[100];
    size_t i = 0;
    int ans = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant ((i) >= 0 && (i) <= (n) &&
        \forall integer j; 0 <= j < (i) ==> (&a[0])[j] == (inputs)[j]);
        loop invariant ((n) >= 1 && (n) <= 100 &&
        \forall integer k; 0 <= k < (n) ==> 1 <= (inputs)[k] && (inputs)[k] <= 100);
        loop assigns i, a[0 .. n-1];
        loop variant n - i;
    */
    while (i < n) {
        a[i] = inputs[i];
        i++;
    }

    i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant ((i) >= 0 && (i) <= (n) && (ans) >= 0 && (ans) <= (i));
        loop invariant (((n)) >= 0 && ((n)) <= (n) &&
        \forall integer j; 0 <= j < ((n)) ==> (&a[0])[j] == (inputs)[j]);
        loop invariant ((n) >= 1 && (n) <= 100 &&
        \forall integer k; 0 <= k < (n) ==> 1 <= (inputs)[k] && (inputs)[k] <= 100);
        loop assigns i, ans;
        loop variant n - i;
    */
    while (i < n) {
        int ai = a[i];
        if ((i == 0 && ai == 1) || (i > 0 && ai == a[i - 1] + 1)) {
            ans++;
        }
        i++;
    }

    //@ assert ans >= 0 && ans <= n;
    return ans;
}
