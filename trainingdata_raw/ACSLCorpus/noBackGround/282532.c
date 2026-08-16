#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) >= 1 &&
    (n) <= 200000 &&
    \valid((a) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 1000000);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(size_t n, const long long *a) {
    int cnt = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant cnt >= 0;
        loop invariant cnt <= (int)i;
        loop invariant \forall integer k; 0 <= k < n ==> a[k] >= 1 && a[k] <= 1000000;
        loop invariant n >= 1 && n <= 200000;
        loop assigns i, cnt;
        loop variant n - i;
    */
    while (i < n) {
        long long num = a[i];
        //@ assert num >= 1 && num <= 1000000;
        
        if ((num & 1) == 0) {
            cnt += 1;
        }
        i += 1;
    }
    return cnt;
}
