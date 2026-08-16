#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_array(int *p, integer n) =
        n >= 3 && n <= 20 &&
        \valid(p + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> 1 <= p[i] && p[i] <= n &&
        \forall integer i, j; 0 <= i < j < n ==> p[i] != p[j];

    logic integer count_peaks(int *p, integer n, integer i) =
        i >= 1 && i < n-1 ?
            ((p[i-1] < p[i] && p[i] < p[i+1]) || (p[i-1] > p[i] && p[i] > p[i+1]) ? 1 : 0)
        : 0;

    lemma peaks_nonnegative:
        \forall int *p, integer n, i; valid_array(p, n) && 1 <= i < n-1 ==> count_peaks(p, n, i) >= 0;
*/

/*@
    requires valid_array(p, n);
    ensures \result >= -1 && \result <= n-2;
    ensures \result >= 0 ==> \result <= n-2;
    assigns \nothing;
*/
int func(int n, int *p) {
    int res = 0;
    size_t i = 1;
    
    /*@
        loop invariant 1 <= i <= n-1;
        loop invariant res >= 0;
        loop invariant res <= i-1;
        loop invariant valid_array(p, n);
        loop assigns i, res;
        loop variant n-1-i;
    */
    while (i < (size_t)(n - 1)) {
        //@ assert i >= 1 && i < n-1;
        
        if (p[i-1] < p[i] && p[i] < p[i+1]) {
            //@ assert count_peaks(p, n, i) == 1;
            res += 1;
        }
        
        if (p[i-1] > p[i] && p[i] > p[i+1]) {
            //@ assert count_peaks(p, n, i) == 1;
            res += 1;
        }
        
        i += 1;
    }
    
    if (res == 0) {
        return -1;
    } else {
        //@ assert res >= 0 && res <= n-2;
        return res;
    }
}
