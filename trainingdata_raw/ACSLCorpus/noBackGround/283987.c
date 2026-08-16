#include <stddef.h>
#include <stdint.h>

/*@
    requires n >= 0 && m >= 0;
    requires n <= 100000 && m <= 100000;
    requires ((n) >= 0 && (n) <= 100000 &&
    \forall integer k; 0 <= k < (n) ==> (a)[k] >= 1 && (a)[k] <= 1000000000);
    requires ((m) >= 0 && (m) <= 100000 &&
    \forall integer k; 0 <= k < (m) ==> (b)[k] >= 1 && (b)[k] <= 1000000000);
    assigns \nothing;
    ensures \result >= 0 && \result <= m;
*/
size_t func(size_t n, const int64_t a[], size_t m, const int64_t b[]) {
    size_t ans = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= m;
        loop invariant ((ans) >= 0 && (ans) <= (i) && (i) <= (m));
        loop invariant ((n) >= 0 && (n) <= 100000 &&
    \forall integer k; 0 <= k < (n) ==> (a)[k] >= 1 && (a)[k] <= 1000000000);
        loop invariant ((m) >= 0 && (m) <= 100000 &&
    \forall integer k; 0 <= k < (m) ==> (b)[k] >= 1 && (b)[k] <= 1000000000);
        loop assigns ans, i;
        loop variant m - i;
    */
    while (i < m) {
        int64_t b_elem = b[i];
        size_t j = 0;
        
        /*@
            loop invariant 0 <= j <= n;
            loop invariant ((ans) >= 0 && (ans) <= (i) && (i) <= (m));
            loop invariant ((n) >= 0 && (n) <= 100000 &&
    \forall integer k; 0 <= k < (n) ==> (a)[k] >= 1 && (a)[k] <= 1000000000);
            loop invariant ((m) >= 0 && (m) <= 100000 &&
    \forall integer k; 0 <= k < (m) ==> (b)[k] >= 1 && (b)[k] <= 1000000000);
            loop assigns j, ans;
            loop variant n - j;
        */
        while (j < n) {
            //@ assert 0 <= j < n ==> a[j] >= 1 && a[j] <= 1000000000;
            if (a[j] == b_elem) {
                ans += 1;
                break;
            }
            j += 1;
        }
        i += 1;
    }
    //@ assert ((ans) >= 0 && (ans) <= ((m)) && ((m)) <= (m));
    return ans;
}
