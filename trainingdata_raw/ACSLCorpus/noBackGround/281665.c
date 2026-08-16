#include <stdbool.h>
#include <stdint.h>

/*@
    requires n >= 2 && n <= 50;
    requires \valid(aa + (0 .. n-1));
    requires ((n) >= 2 && (n) <= 50 &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (aa)[i] <= 100);
    assigns \nothing;
    ensures \result == true <==> (\forall integer i; 0 <= i < (n) && (aa)[i] % 2 == 0 ==>
            (aa)[i] % 3 == 0 || (aa)[i] % 5 == 0);
*/
bool func(uint64_t n, uint64_t *aa) {
    uint64_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant \forall integer k; 0 <= k < i && aa[k] % 2 == 0 ==>
            aa[k] % 3 == 0 || aa[k] % 5 == 0;
        loop assigns i;
        loop variant n - i;
    */
    while (i < n) {
        uint64_t a = aa[i];
        
        //@ assert a >= 1 && a <= 100;
        
        if (a % 2 == 0) {
            if (!(a % 3 == 0 || a % 5 == 0)) {
                return false;
            }
        }
        i++;
    }
    return true;
}

