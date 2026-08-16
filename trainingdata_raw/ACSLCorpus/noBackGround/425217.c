#include <stdbool.h>
#include <stdint.h>

/*@ requires (1 <= (n) <= 100);
    requires (1 <= (m) <= (n));
    requires \valid(a + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (1 <= ((a)[i]) <= 1000));
    ensures \result >= 0;
    ensures \result <= m * 1000;
*/
uint32_t func(uint32_t n, uint32_t m, uint32_t *a) {
    uint32_t x = 0;
    uint32_t i = 0;
    
    /*@ loop invariant 0 <= i <= m;
        loop invariant x >= 0;
        loop invariant x <= i * 1000;
        loop invariant (\forall integer i; 0 <= i < (n) ==> (1 <= ((a)[i]) <= 1000));
        loop invariant (1 <= (n) <= 100);
        loop invariant (1 <= (m) <= (n));
        loop assigns x, i;
        loop variant m - i;
    */
    while (i < m) {
        //@ assert (0 <= (i) < (n));
        //@ assert (1 <= (a[i]) <= 1000);
        x += a[i];
        i++;
        //@ assert x <= i * 1000;
    }
    
    uint32_t max_val;
    //@ assert (0 <= ((n)-1) < (n));
    //@ assert (1 <= (a[n-1]) <= 1000);
    if (x > a[n - 1]) {
        max_val = x;
    } else {
        max_val = a[n - 1];
    }
    //@ assert max_val <= 100000;
    
    uint32_t ans = 0;
    i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant ans >= 0;
        loop invariant ans <= i;
        loop invariant (\forall integer i; 0 <= i < (n) ==> (1 <= ((a)[i]) <= 1000));
        loop invariant (1 <= (n) <= 100);
        loop invariant (1 <= (m) <= (n));
        loop assigns ans, i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert (0 <= (i) < (n));
        //@ assert (1 <= (a[i]) <= 1000);
        if (max_val <= a[i]) {
            ans++;
        }
        i++;
        //@ assert ans <= i;
    }
    
    //@ assert ans <= n;
    return ans;
}
