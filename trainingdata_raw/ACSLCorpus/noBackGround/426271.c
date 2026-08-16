#include <stdbool.h>
#include <stdint.h>

/*@
    requires n > 0 && m > 0;
    requires \valid(a + (0..n-1));
    requires \valid(b + (0..m-1));
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
uint32_t func(uint32_t n, uint32_t m, int *a, int *b) {
    uint32_t ans = 0;
    uint32_t i = 0;
    int *a_seq = a;
    int *b_seq = b;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= ans <= i;
        loop invariant (\valid((a) + (0..(n)-1)));
        loop invariant (\valid((b) + (0..(m)-1)));
        loop invariant (\forall integer k; 0 <= k < (i) ==> (a)[k] == (a_seq)[k]);
        loop assigns i, ans;
        loop variant n - i;
    */
    while (i < n) {
        uint32_t j = 0;
        bool found = false;
        uint32_t old_ans = ans;
        
        /*@
            loop invariant 0 <= j <= m;
            loop invariant ans == old_ans + (found ? 1 : 0);
            loop invariant (\valid((a) + (0..(n)-1)));
            loop invariant (\valid((b) + (0..(m)-1)));
            loop invariant (\forall integer k; 0 <= k < (i) ==> (a)[k] == (a_seq)[k]);
            loop invariant (\forall integer k; 0 <= k < (j) ==> (b)[k] == (b_seq)[k]);
            loop invariant !found ==> (\forall integer k; 0 <= k < j ==> a[i] != b[k]);
            loop assigns j, ans, found;
            loop variant m - j;
        */
        while (j < m && !found) {
            if (a[i] == b[j]) {
                ans += 1;
                found = true;
            }
            j += 1;
        }
        i += 1;
    }
    
    //@ assert 0 <= ans <= n;
    return ans;
}
