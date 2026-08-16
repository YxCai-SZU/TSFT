#include <stddef.h>
#include <stdbool.h>

/*@
    requires ((n) > 0 && (n) <= 200000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 1000000000);
    ensures \result <= n-1;
    assigns \nothing;
*/
size_t func(size_t n, int *a) {
    size_t ans = n - 1;
    size_t cnt = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n-1;
        loop invariant 0 <= cnt <= i;
        loop invariant ans <= n-1;
        loop invariant ((n) > 0 && (n) <= 200000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 1000000000);
        loop assigns i, cnt, ans;
        loop variant n - i;
    */
    while (i < n - 1) {
        //@ assert 0 <= i < n-1;
        //@ assert 0 <= i+1 < n;
        
        if (a[i] + 1 == a[i + 1]) {
            cnt += 1;
        } else {
            //@ assert ans <= n-1 && cnt <= n-1;
            ans = ans < cnt ? ans : cnt;
            cnt = 0;
        }
        i += 1;
    }
    
    //@ assert ans <= n-1 && cnt <= n-1;
    ans = ans < cnt ? ans : cnt;
    
    //@ assert ans <= n-1;
    return ans;
}
