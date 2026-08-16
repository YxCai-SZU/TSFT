#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) >= 1 && (n) <= 100000 &&
        \valid((arr) + (0 .. (n)-1)) &&
        \forall integer k; 0 <= k < (n) ==> (arr)[k] >= 0 && (arr)[k] <= 1000000000);
    requires ((m) >= 1 && (m) <= 100000 &&
        \valid((brr) + (0 .. (m)-1)) &&
        \forall integer k; 0 <= k < (m) ==> (brr)[k] >= 0 && (brr)[k] <= 1000000000);
    ensures \result >= 0 || \result == -1;
    assigns \nothing;
*/
int func(int n, int m, int *arr, int *brr) {
    int ans = 0;
    int i = 0;

    /*@
        loop invariant 0 <= i <= m;
        loop invariant ((ans) >= 0 && (ans) <= (i));
        loop invariant ((n) >= 1 && (n) <= 100000 &&
        \valid((arr) + (0 .. (n)-1)) &&
        \forall integer k; 0 <= k < (n) ==> (arr)[k] >= 0 && (arr)[k] <= 1000000000);
        loop invariant ((m) >= 1 && (m) <= 100000 &&
        \valid((brr) + (0 .. (m)-1)) &&
        \forall integer k; 0 <= k < (m) ==> (brr)[k] >= 0 && (brr)[k] <= 1000000000);
        loop assigns ans, i;
        loop variant m - i;
    */
    while (i < m) {
        int b = brr[i];
        int j = 0;
        bool found = false;
        int old_ans = ans;

        /*@
            loop invariant 0 <= j <= n;
            loop invariant ((ans) >= 0 && (ans) <= (i));
            loop invariant ((n) >= 1 && (n) <= 100000 &&
        \valid((arr) + (0 .. (n)-1)) &&
        \forall integer k; 0 <= k < (n) ==> (arr)[k] >= 0 && (arr)[k] <= 1000000000);
            loop invariant ((m) >= 1 && (m) <= 100000 &&
        \valid((brr) + (0 .. (m)-1)) &&
        \forall integer k; 0 <= k < (m) ==> (brr)[k] >= 0 && (brr)[k] <= 1000000000);
            loop invariant b >= 0 && b <= 1000000000;
            loop invariant !found ==> ans == old_ans;
            loop invariant found ==> ans == old_ans + 1;
            loop assigns j, ans, found;
            loop variant n - j;
        */
        while (j < n) {
            int a = arr[j];
            if (a == b) {
                ans += 1;
                found = true;
                break;
            }
            j += 1;
        }

        //@ assert ans >= 0;
        if (ans == -1) {
            return -1;
        }
        i += 1;
    }
    //@ assert ans >= 0;
    return ans;
}
