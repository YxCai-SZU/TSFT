#include <stdint.h>
#include <stdbool.h>

/*@ requires (2 <= (k) && (k) <= (n) && (n) <= 100000);
    requires \valid(a + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= (n));
    requires (\forall integer i; 0 <= i < (n) - 1 ==> (a)[i] != (a)[i + 1]);
    assigns \nothing;
    ensures \result <= n - 1;
*/
uint32_t func(uint32_t n, uint32_t k, int64_t* a) {
    uint32_t ans = 0;
    uint32_t i = 0;
    
    /*@ loop invariant 0 <= i <= n - 1;
        loop invariant ans <= i;
        loop invariant ans <= n - 1;
        loop assigns ans, i;
        loop variant n - i;
    */
    while (i < n - 1) {
        int64_t t;
        if (a[i] > a[i + 1]) {
            t = a[i] - a[i + 1];
        } else {
            t = a[i + 1] - a[i];
        }
        
        //@ assert t >= 0;
        
        if (t < (int64_t)k) {
            ans = ans + 1;
        }
        
        i = i + 1;
    }
    
    return ans;
}
