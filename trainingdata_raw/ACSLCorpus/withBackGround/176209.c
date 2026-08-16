#include <stddef.h>
#include <stdbool.h>

/*@
    predicate valid_array(size_t n, unsigned long long *a) =
        n >= 2 && n <= 300000 &&
        \forall integer i; 0 <= i < n ==> 1 <= a[i] && a[i] <= 1000000000;

    predicate loop_invariant(size_t lp, size_t n, size_t ret) =
        lp <= n && ret <= lp;
*/

/*@
    requires 1 <= k <= 100000;
    requires valid_array(n, aa);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
size_t func(size_t n, size_t k, const unsigned long long *aa) {
    size_t ret = 0;
    size_t lp = 0;
    
    //@ assert ret == 0 && lp == 0;
    
    if (k == 1) {
        //@ assert ret >= 0 && ret <= n;
        return n;
    }
    
    /*@
        loop invariant 0 <= lp <= n;
        loop invariant 0 <= ret <= lp;
        loop assigns lp, ret;
        loop variant n - lp;
    */
    while (lp < n) {
        unsigned long long a = aa[lp];
        
        //@ assert 1 <= a <= 1000000000;
        
        if (a > k) {
            //@ assert ret + 1 <= lp + 1;
            ret = ret + 1;
        } else if (a == k) {
            //@ assert ret + 1 <= lp + 1;
            ret = ret + 1;
        }
        
        //@ assert ret <= lp + 1;
        lp = lp + 1;
    }
    
    //@ assert ret <= n;
    return ret;
}
