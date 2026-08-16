#include <stddef.h>
#include <stdbool.h>

/*@
    requires 2 <= n && n <= 100000;
    requires \valid(a + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> (1 <= (a[i]) && (a[i]) <= 1000000000);
    assigns \nothing;
    ensures \result <= n;
    ensures \forall integer i; 0 <= i < n && (((i) + 1) % 2 == 1 && (a[i]) % 2 == 1) ==> \result >= 1;
*/
size_t func(size_t n, const size_t a[]) {
    size_t ans = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i && i <= n;
        loop invariant ans <= i;
        loop invariant \forall integer j; 0 <= j < i && (((j) + 1) % 2 == 1 && (a[j]) % 2 == 1) ==> ans >= 1;
        loop assigns i, ans;
        loop variant n - i;
    */
    while (i < n) {
        size_t x = a[i];
        
        //@ assert (1 <= (x) && (x) <= 1000000000);
        
        if (((i + 1) % 2 == 1) && (x % 2 == 1)) {
            ans += 1;
        }
        
        i += 1;
    }
    
    return ans;
}
