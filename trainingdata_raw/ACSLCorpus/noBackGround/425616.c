#include <stdbool.h>
#include <stddef.h>

/*@ requires n > 0 && k > 0;
    requires \valid(h + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (h)[i] > 0);
    assigns \nothing;
    ensures \result <= n;
*/
unsigned int func(unsigned int n, unsigned int k, unsigned int *h) {
    unsigned int ans = 0;
    unsigned int index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant ((ans) >= 0 && (ans) <= (index) && (index) <= (n));
        loop invariant (\forall integer i; 0 <= i < (n) ==> (h)[i] > 0);
        loop assigns ans, index;
    */
    while (index < n) {
        //@ assert index < n;
        if (k <= h[index]) {
            ans = ans + 1;
        }
        index = index + 1;
    }
    
    //@ assert ans <= n;
    return ans;
}
