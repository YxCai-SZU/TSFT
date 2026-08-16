#include <stdbool.h>
#include <stdint.h>

/*@
    predicate valid_array(integer n, uint64_t *a) =
        1 <= n <= 100000 &&
        \valid(a + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 100000;

    predicate condition_holds(integer n, uint64_t *a) =
        \forall integer i; 0 <= i < n && a[i] % 2 == 0 ==> 
        a[i] % 3 == 0 || a[i] % 5 == 0;

    lemma array_bounds: \forall integer n, uint64_t *a; 
        valid_array(n, a) ==> \forall integer i; 0 <= i < n ==> 0 <= a[i];
*/

/*@
    requires valid_array(n, a);
    ensures \result == true <==> condition_holds(n, a);
    assigns \nothing;
*/
bool func(uint64_t n, uint64_t *a) {
    uint64_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant valid_array(n, a);
        loop invariant \forall integer k; 0 <= k < i && a[k] % 2 == 0 ==> 
            a[k] % 3 == 0 || a[k] % 5 == 0;
        loop assigns i;
        loop variant n - i;
    */
    while (i < n) {
        uint64_t ai = a[i];
        
        //@ assert 0 <= i < n;
        
        if (ai % 2 != 0) {
            i += 1;
            continue;
        }
        
        //@ assert ai % 2 == 0;
        
        if (!(ai % 3 == 0 || ai % 5 == 0)) {
            //@ assert !(ai % 3 == 0 || ai % 5 == 0);
            return false;
        }
        
        //@ assert ai % 3 == 0 || ai % 5 == 0;
        i += 1;
    }
    
    //@ assert i == n;
    //@ assert \forall integer k; 0 <= k < n && a[k] % 2 == 0 ==> a[k] % 3 == 0 || a[k] % 5 == 0;
    return true;
}
