#include <stdbool.h>
#include <stddef.h>

/*@ requires (1 <= (n) && (n) <= 100 &&
     1 <= (x) && (x) <= 10000 &&
     \valid((l) + (0 .. (n)-1)) &&
     \forall integer j; 0 <= j < (n) ==> 1 <= (l)[j] && (l)[j] <= 100);
    ensures \result >= 1 && \result <= n + 1;
    assigns \nothing;
*/
unsigned long func(size_t n, unsigned long x, unsigned long *l) {
    unsigned long d = 0;
    unsigned long ans = 1;
    size_t i = 0;
    
    /*@ loop invariant (0 <= ((integer)i) && ((integer)i) <= (integer)(n) &&
     (d) <= ((integer)i) * 100 &&
     (ans) >= 1 &&
     (ans) <= ((integer)i) + 1 &&
     (((integer)i) > 0 ==> \forall integer k; 0 <= k < ((integer)i) ==> (d) >= (l)[k]));
        loop assigns i, d, ans;
        loop variant n - i;
    */
    while (i < n) {
        unsigned long li = l[i];
        d += li;
        
        //@ assert d <= (i + 1) * 100;
        
        if (d <= x) {
            ans += 1;
        }
        
        //@ assert ans >= 1;
        
        i += 1;
    }
    
    //@ assert ans >= 1;
    //@ assert ans <= n + 1;
    
    return ans;
}
