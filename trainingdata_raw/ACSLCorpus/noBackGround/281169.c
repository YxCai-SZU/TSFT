#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/*@
    requires ((n) >= 1 && (n) <= 100 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer k; 0 <= k < (n) ==> (a)[k] >= 1 && (a)[k] <= 100);
    ensures \result >= 0 && \result <= n;
    ensures \forall integer i; 0 <= i < n && a[i] % 2 == 0 && i % 2 == 0 ==> \result > 0;
    assigns \nothing;
*/
uint32_t func(uint32_t n, int *a) {
    uint32_t v = 0;
    size_t i = 0;
    
    //@ assert ((n) >= 1 && (n) <= 100 &&         \valid((a) + (0 .. (n)-1)) &&         \forall integer k; 0 <= k < (n) ==> (a)[k] >= 1 && (a)[k] <= 100);
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant v >= 0 && v <= i;
        loop invariant (\forall integer j; 0 <= j < (i) && (a)[j] % 2 == 0 && j % 2 == 0 ==> (v) > 0);
        loop assigns v, i;
        loop variant n - i;
    */
    while (i < n) {
        int x = a[i];
        
        //@ assert x >= 1 && x <= 100;
        
        if (x % 2 == 0 && i % 2 == 0) {
            //@ assert v + 1 <= i + 1;
            v += 1;
        }
        
        //@ assert (\forall integer j; 0 <= j < (i + 1) && (a)[j] % 2 == 0 && j % 2 == 0 ==> (v) > 0);
        i += 1;
    }
    
    //@ assert \forall integer k; 0 <= k < n && a[k] % 2 == 0 && k % 2 == 0 ==> v > 0;
    return v;
}
