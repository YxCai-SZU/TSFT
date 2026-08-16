#include <stddef.h>
#include <stdbool.h>

/*@
    requires ((n) >= 2 && (n) <= 50 &&
    \valid((a) + (0 .. (n)-1)) &&
    \forall integer j; 0 <= j < (n) ==> 0 <= (a)[j] && (a)[j] <= 100);
    ensures ((\result) >= 0 && (\result) <= (n) - 2);
    assigns \nothing;
*/
size_t func(size_t n, int *a) {
    size_t count = 0;
    size_t i = 1;
    
    /*@
        loop invariant 1 <= i <= n-1;
        loop invariant count >= 0;
        loop invariant count <= i-1;
        loop invariant ((n) >= 2 && (n) <= 50 &&
    \valid((a) + (0 .. (n)-1)) &&
    \forall integer j; 0 <= j < (n) ==> 0 <= (a)[j] && (a)[j] <= 100);
        loop assigns i, count;
        loop variant n-i;
    */
    while (i < n - 1) {
        //@ assert 0 <= i-1 < n && 0 <= i < n && 0 <= i+1 < n;
        
        if (a[i - 1] > a[i] && a[i] < a[i + 1]) {
            count += 1;
        }
        
        if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
            count += 1;
        }
        
        i += 1;
    }
    
    //@ assert ((count) >= 0 && (count) <= (n) - 2);
    return count;
}
