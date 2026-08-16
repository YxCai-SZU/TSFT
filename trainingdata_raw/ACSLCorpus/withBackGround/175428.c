#include <stddef.h>
#include <stdint.h>

/*@
    predicate valid_array(size_t n, uint64_t *a) =
        n >= 2 && n <= 100000 &&
        \valid(a + (0 .. n-1)) &&
        \forall size_t i; 0 <= i < n ==> 1 <= a[i] && a[i] <= 1000000000;

    predicate loop_invariant(size_t n, size_t k, uint64_t *a, size_t i, size_t cnt) =
        0 <= i && i <= n &&
        0 <= cnt && cnt <= i &&
        valid_array(n, a) &&
        1 <= k && k <= n-1;

    lemma cnt_bound: \forall size_t n, size_t k, uint64_t *a, size_t i, size_t cnt;
        loop_invariant(n, k, a, i, cnt) ==> cnt <= i;
*/

/*@
    requires 2 <= n && n <= 100000;
    requires 1 <= k && k <= n-1;
    requires \valid(a + (0 .. n-1));
    requires \forall size_t i; 0 <= i < n ==> 1 <= a[i] && a[i] <= 1000000000;
    assigns \nothing;
    ensures 0 <= \result && \result <= n;
*/
size_t func(size_t n, size_t k, const uint64_t a[]) {
    size_t cnt = 0;
    size_t i = 0;

    /*@
        loop invariant loop_invariant(n, k, a, i, cnt);
        loop assigns i, cnt;
        loop variant n - i;
    */
    while (i < n) {
        uint64_t l = a[i];
        //@ assert 0 <= i && i < n;
        //@ assert 1 <= l && l <= 1000000000;
        
        if (l < (k + 1) / 2) {
            cnt = cnt + 1;
        }
        i = i + 1;
        
        //@ assert cnt <= i;
    }
    
    //@ assert 0 <= cnt && cnt <= n;
    return cnt;
}
