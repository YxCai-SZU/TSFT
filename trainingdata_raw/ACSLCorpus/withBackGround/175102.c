#include <stddef.h>
#include <stdbool.h>

/*@ predicate valid_array(integer n, int *a) =
    n >= 3 && n <= 20 &&
    \valid(a + (0 .. n-1)) &&
    \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= n &&
    \forall integer i, j; 0 <= i < j < n ==> a[i] != a[j];
*/

/*@ lemma array_properties_preserved:
    \forall integer n, int *a, integer i;
    valid_array(n, a) && 0 <= i <= n-2 ==>
    \forall integer k; 0 <= k < n ==> a[k] >= 1 && a[k] <= n &&
    \forall integer k, l; 0 <= k < l < n ==> a[k] != a[l];
*/

/*@
    requires valid_array(n, a);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
size_t func(size_t n, int *a) {
    size_t ans = 0;
    size_t i = 0;
    
    //@ assert valid_array(n, a);
    
    /*@
        loop invariant 0 <= i <= n-2;
        loop invariant 3 <= n <= 20;
        loop invariant \valid(a + (0 .. n-1));
        loop invariant \forall integer k; 0 <= k < n ==> a[k] >= 1 && a[k] <= n;
        loop invariant \forall integer k, l; 0 <= k < l < n ==> a[k] != a[l];
        loop invariant 0 <= ans <= i;
        loop assigns ans, i;
        loop variant n - i;
    */
    while (i < n - 2) {
        //@ assert 0 <= i < n-2;
        //@ assert i+1 < n;
        //@ assert i+2 < n;
        
        if (a[i] == 1 || a[i + 1] == 2 || a[i + 2] == 3) {
            ans += 1;
        }
        i += 1;
    }
    
    //@ assert 0 <= ans <= n;
    return ans;
}
