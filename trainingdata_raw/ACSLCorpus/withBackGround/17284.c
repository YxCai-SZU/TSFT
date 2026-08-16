#include <stdbool.h>
#include <stddef.h>

/*@
    predicate all_odd_or_divisible_6_or_10(unsigned int *a, integer n, integer i) =
        \forall integer j; 0 <= j < i ==>
            (a[j] % 2 != 0) || (a[j] % 6 == 0) || (a[j] % 10 == 0);
*/

/*@
    requires n > 0 && n <= 100;
    requires \valid(a + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> a[i] > 0 && a[i] <= 1000;
    ensures \result == true <==> 
            \forall integer i; 0 <= i < n ==> 
                (a[i] % 2 != 0) || (a[i] % 6 == 0) || (a[i] % 10 == 0);
    assigns \nothing;
*/
bool func(size_t n, unsigned int a[]) {
    bool ok = true;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant ok == true <==> all_odd_or_divisible_6_or_10(a, n, i);
        loop assigns ok, i;
        loop variant n - i;
    */
    while (i < n) {
        unsigned int ai = a[i];
        //@ assert ai > 0 && ai <= 1000;
        
        if (!((ai % 2 != 0) || (ai % 6 == 0) || (ai % 10 == 0))) {
            ok = false;
        }
        i++;
    }
    return ok;
}
