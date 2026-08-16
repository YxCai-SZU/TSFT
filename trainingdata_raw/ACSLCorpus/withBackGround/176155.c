#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(integer n, int *a) =
    n > 0 && n <= 100 &&
    \valid(a + (0 .. n-1)) &&
    \forall integer i; 0 <= i < n ==> a[i] > 0 && a[i] <= 1000;
*/

/*@ predicate condition_holds(integer n, int *a) =
    \forall integer i; 0 <= i < n ==> 
        a[i] % 2 != 0 || a[i] % 3 == 0 || a[i] % 5 == 0;
*/

/*@ lemma array_bounds: 
    \forall integer n, int *a; valid_array(n, a) ==> 
        \forall integer i; 0 <= i < n ==> a[i] > 0 && a[i] <= 1000;
*/

/*@
    requires valid_array(n, a);
    ensures \result == true <==> condition_holds(n, a);
    assigns \nothing;
*/
bool func(size_t n, int *a) {
    size_t i = 0;
    size_t num = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= num <= i;
        loop invariant valid_array(n, a);
        loop invariant i > 0 ==> 
            (num == 0 <==> \forall integer k; 0 <= k < i ==> 
                !(a[k] % 2 == 0 && a[k] % 3 != 0 && a[k] % 5 != 0));
        loop invariant \forall integer k; 0 <= k < n ==> 
            a[k] % 2 != 0 || a[k] % 3 == 0 || a[k] % 5 == 0 || 
            (a[k] % 2 == 0 && a[k] % 3 != 0 && a[k] % 5 != 0);
        loop assigns i, num;
        loop variant n - i;
    */
    while (i < n) {
        int s = a[i];
        //@ assert 0 <= s && s <= 1000;
        
        if (s % 2 == 0 && s % 3 != 0 && s % 5 != 0) {
            num += 1;
        }
        i += 1;
        //@ assert i <= n;
    }
    return num == 0;
}
